#include "mm_bullet_world.h"
#include "BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h"
#include "core/mm_time.h"
//////////////////////////////////////////////////////////////////////////
static void* __static_bullet_world_handle_thread(void* _arg);
//////////////////////////////////////////////////////////////////////////
void mm_bullet_world_init(struct mm_bullet_world* p)
{
	p->d_collision_configuration = new btDefaultCollisionConfiguration();;
	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	p->d_collision_dispatcher = new btCollisionDispatcher(p->d_collision_configuration);
	///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
	p->d_broadphase = new btDbvtBroadphase();
	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	p->d_constraint_solver = new btSequentialImpulseConstraintSolver;
	p->d_dynamics_world = new btDiscreteDynamicsWorld(p->d_collision_dispatcher,p->d_broadphase,p->d_constraint_solver,p->d_collision_configuration);
	p->d_debug_draw = new mm_bullet_debug_drawer;
	p->d_dynamics_world->setDebugDrawer(p->d_debug_draw);
	//
	mm_spinlock_init(&p->d_locker,0);
	p->d_state = 0;
	p->d_time_step = 1/60.0f;
	p->d_active = 1;
	//
	btGImpactCollisionAlgorithm::registerAlgorithm(p->d_collision_dispatcher);
}
void mm_bullet_world_destroy(struct mm_bullet_world* p)
{
	delete p->d_collision_configuration;
	p->d_collision_configuration = NULL;
	delete p->d_collision_dispatcher;
	p->d_collision_dispatcher = NULL;
	delete p->d_broadphase;
	p->d_broadphase = NULL;
	delete p->d_constraint_solver;
	p->d_constraint_solver = NULL;
	delete p->d_dynamics_world;
	p->d_dynamics_world = NULL;
	delete p->d_debug_draw;
	p->d_debug_draw = NULL;
	//
	mm_spinlock_destroy(&p->d_locker);
	p->d_state = 0;
	p->d_time_step = 1/60.0f;
	p->d_active = 0;
}
int mm_bullet_world_step_simulation(struct mm_bullet_world* p, btScalar timeStep,int maxSubSteps/*=1*/, btScalar fixedTimeStep/*=btScalar(1.)/btScalar(60.)*/)
{
	return p->d_dynamics_world->stepSimulation(timeStep,maxSubSteps,fixedTimeStep);
}
void mm_bullet_world_loop(struct mm_bullet_world* p)
{
	struct timeval time_point;
	struct timeval time_front;
	struct timeval time_after;
	btScalar _time_offset = 0;
	btScalar _distance = 0;
	int _max_sub_steps = 1;
	mm_gettimeofday(&time_point, NULL);
	while( 0 != p->d_state )
	{
		mm_gettimeofday(&time_front, NULL);
		_time_offset = time_front.tv_sec - time_point.tv_sec + (btScalar)(time_front.tv_usec - time_point.tv_usec) / MM_USEC_PER_SEC;
		_max_sub_steps = (int)(_time_offset / p->d_time_step);
		_max_sub_steps = _max_sub_steps < 1 ? 1 : _max_sub_steps;
		if ( 1 == p->d_active )
		{
			mm_bullet_world_lock(p);
			mm_bullet_world_step_simulation(p,_time_offset,_max_sub_steps,p->d_time_step);
			mm_bullet_world_unlock(p);
		}
		mm_gettimeofday(&time_after, NULL);
		_time_offset = time_after.tv_sec - time_front.tv_sec + (btScalar)(time_after.tv_usec - time_front.tv_usec) / MM_USEC_PER_SEC;
		_distance = p->d_time_step - _time_offset;
		time_point = time_front;
		mm_msleep( (int)( (_distance < 0 ? 0 : _distance) * MM_MSEC_PER_SEC ) );
	}
}
void mm_bullet_world_lock(struct mm_bullet_world* p)
{
	mm_spinlock_lock(&p->d_locker);
}
void mm_bullet_world_unlock(struct mm_bullet_world* p)
{
	mm_spinlock_unlock(&p->d_locker);
}
void mm_bullet_world_draw(struct mm_bullet_world* p)
{
	p->d_debug_draw->clearGeometry();
	p->d_dynamics_world->debugDrawWorld();
	p->d_debug_draw->drawGeometry();
}
// start thread.
void mm_bullet_world_start(struct mm_bullet_world* p)
{
	p->d_state = 1;
	pthread_create(&p->d_thread, NULL, &__static_bullet_world_handle_thread, p);
}
// interrupt thread.
void mm_bullet_world_interrupt(struct mm_bullet_world* p)
{
	p->d_state = 0;
}
// join thread.
void mm_bullet_world_join(struct mm_bullet_world* p)
{
	pthread_join(p->d_thread, NULL);
}
//////////////////////////////////////////////////////////////////////////
static void* __static_bullet_world_handle_thread(void* _arg)
{
	struct mm_bullet_world* p = (struct mm_bullet_world*)(_arg);
	mm_bullet_world_loop(p);
	return NULL;
}