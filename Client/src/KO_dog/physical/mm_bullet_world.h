#ifndef __mm_bullet_world_h__
#define __mm_bullet_world_h__
//////////////////////////////////////////////////////////////////////////
#include "mm_bullet_debug_drawer.h"
//////////////////////////////////////////////////////////////////////////
#include "LinearMath/btDefaultMotionState.h"
#include "LinearMath/btIDebugDraw.h"
#include "BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h"
#include "BulletCollision/BroadphaseCollision/btDbvtBroadphase.h"
#include "BulletCollision/CollisionShapes/btCollisionShape.h"
#include "BulletCollision/CollisionShapes/btBoxShape.h"
#include "BulletCollision/CollisionShapes/btSphereShape.h"
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"
#include "pthread.h"
#include "core/mm_spinlock.h"
//////////////////////////////////////////////////////////////////////////
struct mm_bullet_world
{
	btDefaultCollisionConfiguration* d_collision_configuration;
	btCollisionDispatcher* d_collision_dispatcher;
	btBroadphaseInterface* d_broadphase;
	btConstraintSolver* d_constraint_solver;
	btDynamicsWorld* d_dynamics_world;
	mm_bullet_debug_drawer* d_debug_draw;
	//
	pthread_t d_thread;// check thread.
	mm_atomic_t d_locker;
	mm_sint8_t d_state;// run state.1 is run 0 is stop.
	btScalar d_time_step;// default is 1/60.0f second.
	mm_sint8_t d_active;// whether active step at loop,1 is run 0 is stop.default is 0.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_bullet_world_init(struct mm_bullet_world* p);
extern void mm_bullet_world_destroy(struct mm_bullet_world* p);
//////////////////////////////////////////////////////////////////////////
// lock yourself.
extern int mm_bullet_world_step_simulation(struct mm_bullet_world* p, btScalar timeStep,int maxSubSteps=1, btScalar fixedTimeStep=btScalar(1.)/btScalar(60.));
//////////////////////////////////////////////////////////////////////////
extern void mm_bullet_world_loop(struct mm_bullet_world* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_bullet_world_lock(struct mm_bullet_world* p);
extern void mm_bullet_world_unlock(struct mm_bullet_world* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_bullet_world_draw(struct mm_bullet_world* p);
//////////////////////////////////////////////////////////////////////////
// start thread.
extern void mm_bullet_world_start(struct mm_bullet_world* p);
// interrupt thread.
extern void mm_bullet_world_interrupt(struct mm_bullet_world* p);
// join thread.
extern void mm_bullet_world_join(struct mm_bullet_world* p);
//////////////////////////////////////////////////////////////////////////
#endif//__mm_bullet_world_h__