#include "mm_bullet_debug_drawer.h"
#include "OgreCamera.h"
#include "OgreHardwareVertexBuffer.h"
#include "OgreHardwareBufferManager.h"
#include "OgreMaterialManager.h"
#include "mm_bullet_ogre_conver.h"
#include "core/mm_logger_manager.h"
btVector3 mm_bullet_debug_drawer::d_axis_x_color = btVector3(0.7f,0.0f,0.0f);
btVector3 mm_bullet_debug_drawer::d_axis_y_color = btVector3(0.0f,0.7f,0.0f);
btVector3 mm_bullet_debug_drawer::d_axis_z_color = btVector3(0.0f,0.0f,0.7f);
mm_bullet_debug_drawer::mm_bullet_debug_drawer()
	: d_node_debug_draw(NULL)
	, d_debug_mode(0)
{
	Ogre::MaterialManager* _material_manager = Ogre::MaterialManager::getSingletonPtr();
	Ogre::MaterialPtr _material_axis_x = _material_manager->getByName("color/axis_x");
	Ogre::MaterialPtr _material_axis_y = _material_manager->getByName("color/axis_y");
	Ogre::MaterialPtr _material_axis_z = _material_manager->getByName("color/axis_z");
	Ogre::MaterialPtr _material_comm_draw = _material_manager->getByName("color/comm_draw");
	this->d_axis_x.setMaterial(_material_axis_x);
	this->d_axis_y.setMaterial(_material_axis_y);
	this->d_axis_z.setMaterial(_material_axis_z);
	this->d_comm_draw.setMaterial(_material_comm_draw);
	mm_spinlock_init(&this->d_locker,0);
}
mm_bullet_debug_drawer::~mm_bullet_debug_drawer()
{
	mm_spinlock_destroy(&this->d_locker);
}
void mm_bullet_debug_drawer::drawLine(const btVector3& from,const btVector3& to,const btVector3& color)
{
	if ( this->d_debug_mode > 0 )
	{
		mm_spinlock_lock(&this->d_locker);
		if ( this->d_axis_x_color == color )
		{
			this->d_axis_x.addLine(mm_vec3_bt_to_og(from), mm_vec3_bt_to_og(to));
		}
		else if ( this->d_axis_y_color == color )
		{
			this->d_axis_y.addLine(mm_vec3_bt_to_og(from), mm_vec3_bt_to_og(to));
		} 
		else if ( this->d_axis_z_color == color )
		{
			this->d_axis_z.addLine(mm_vec3_bt_to_og(from), mm_vec3_bt_to_og(to));
		} 
		else
		{
			this->d_comm_draw.addLine(mm_vec3_bt_to_og(from), mm_vec3_bt_to_og(to));
		}
		mm_spinlock_unlock(&this->d_locker);
	}
}
void mm_bullet_debug_drawer::drawLine(const btVector3& from,const btVector3& to, const btVector3& fromColor, const btVector3& toColor)
{
	(void) toColor;
	this->drawLine (from, to, fromColor);
}
void mm_bullet_debug_drawer::drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color)
{

}
void mm_bullet_debug_drawer::reportErrorWarning(const char* warningString)
{
	mm_logger_manager_logger_section(mm_logger_instance(), "bullet", MM_LOG_WARNING, warningString);
}
void mm_bullet_debug_drawer::draw3dText(const btVector3& location,const char* textString)
{

}
void mm_bullet_debug_drawer::setDebugMode(int debugMode)
{
	this->d_debug_mode = debugMode;
}
int mm_bullet_debug_drawer::getDebugMode() const
{
	return this->d_debug_mode;
}
void mm_bullet_debug_drawer::setSceneNode(Ogre::SceneNode* _node)
{
	if (this->d_node_debug_draw)
	{
		this->d_node_debug_draw->detachObject(&this->d_axis_x);
		this->d_node_debug_draw->detachObject(&this->d_axis_y);
		this->d_node_debug_draw->detachObject(&this->d_axis_z);
		this->d_node_debug_draw->detachObject(&this->d_comm_draw);
	}
	this->d_node_debug_draw = _node;
	if (this->d_node_debug_draw)
	{
		this->d_node_debug_draw->attachObject(&this->d_axis_x);
		this->d_node_debug_draw->attachObject(&this->d_axis_y);
		this->d_node_debug_draw->attachObject(&this->d_axis_z);
		this->d_node_debug_draw->attachObject(&this->d_comm_draw);
	}
}
Ogre::SceneNode* mm_bullet_debug_drawer::getSceneNode() const
{
	return this->d_node_debug_draw;
}
void mm_bullet_debug_drawer::drawGeometry()
{
	mm_spinlock_lock(&this->d_locker);
	this->d_axis_x.drawGeometry();
	this->d_axis_y.drawGeometry();
	this->d_axis_z.drawGeometry();
	this->d_comm_draw.drawGeometry();
	mm_spinlock_unlock(&this->d_locker);
}
void mm_bullet_debug_drawer::clearGeometry()
{
	mm_spinlock_lock(&this->d_locker);
	this->d_axis_x.clear();
	this->d_axis_y.clear();
	this->d_axis_z.clear();
	this->d_comm_draw.clear();
	mm_spinlock_unlock(&this->d_locker);
}