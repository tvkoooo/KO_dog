#include "mm_bullet_debug_lines.h"
#include "core/mm_logger.h"
#include "OgreCamera.h"
#include "OgreHardwareVertexBuffer.h"
#include "OgreHardwareBufferManager.h"
#include "OgreMaterialManager.h"
#include "OgreTechnique.h"
#include "OgrePass.h"

#define MM_POSITION_BINDING 0

//----------------------------------------------------------------------------//
// Helper to allocate a vertex buffer and initialse a Ogre::RenderOperation
static void __static_create_operation_data(Ogre::RenderOperation& rop, Ogre::HardwareVertexBufferSharedPtr& vb, size_t count)
{
	rop.vertexData = OGRE_NEW Ogre::VertexData();
	rop.indexData = NULL;
	rop.vertexData->vertexCount = count;
	rop.vertexData->vertexStart = 0;
	rop.operationType = Ogre::RenderOperation::OT_LINE_LIST;
	rop.useIndexes = false;

	// setup vertex declaration for format we will use
	Ogre::VertexDeclaration* decl = rop.vertexData->vertexDeclaration;
	Ogre::VertexBufferBinding* bind = rop.vertexData->vertexBufferBinding;

	size_t vd_offset = 0;
	decl->addElement(MM_POSITION_BINDING, vd_offset, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
	vd_offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
	decl->addElement(MM_POSITION_BINDING, vd_offset, Ogre::VET_FLOAT1, Ogre::VES_TEXTURE_COORDINATES);

	Ogre::HardwareVertexBufferSharedPtr vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
		decl->getVertexSize(MM_POSITION_BINDING),
		rop.vertexData->vertexCount,
		Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE);

	bind->setBinding(MM_POSITION_BINDING, vbuf);
}

//----------------------------------------------------------------------------//
// Helper to cleanup what initialiseRenderOp did.
static void __static_delete_operation_data(Ogre::RenderOperation& rop, Ogre::HardwareVertexBufferSharedPtr& vb)
{
	OGRE_DELETE rop.vertexData;
	rop.vertexData = NULL;
	vb.reset();
}

mm_bullet_debug_lines::mm_bullet_debug_lines()
{
	__static_create_operation_data(this->mRenderOp, this->d_vertex_buffer, this->d_points.size());
	//
	this->setCastShadows(false);
}
mm_bullet_debug_lines::~mm_bullet_debug_lines()
{
	this->clear();
	__static_delete_operation_data(this->mRenderOp, this->d_vertex_buffer);
}
Ogre::Real mm_bullet_debug_lines::getSquaredViewDepth(const Ogre::Camera *cam) const
{
	Ogre::Vector3 vMin, vMax, vMid, vDist;
	vMin = mBox.getMinimum();
	vMax = mBox.getMaximum();
	vMid = ((vMin - vMax) * 0.5) + vMin;
	vDist = cam->getDerivedPosition() - vMid;

	return vDist.squaredLength();
}
Ogre::Real mm_bullet_debug_lines::getBoundingRadius(void) const
{
	return Ogre::Math::Sqrt(std::max(mBox.getMaximum().squaredLength(), mBox.getMinimum().squaredLength()));
}
void mm_bullet_debug_lines::drawGeometry()
{
	if (this->d_points.empty())
	{
		return;
	}

	Ogre::VertexDeclaration* decl = this->mRenderOp.vertexData->vertexDeclaration;
	Ogre::VertexBufferBinding* bind = this->mRenderOp.vertexData->vertexBufferBinding;

	Ogre::HardwareVertexBufferSharedPtr vbuf;
	if (this->mRenderOp.vertexData->vertexCount != this->d_points.size())
	{
		this->mRenderOp.vertexData->vertexCount = d_points.size();

		bind->unsetBinding(MM_POSITION_BINDING);

		vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
			decl->getVertexSize(MM_POSITION_BINDING),
			this->mRenderOp.vertexData->vertexCount,
			Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE);

		bind->setBinding(MM_POSITION_BINDING, vbuf); 
	} 
	else
	{
		vbuf = this->mRenderOp.vertexData->vertexBufferBinding->getBuffer(MM_POSITION_BINDING);
	}
	// Drawing stuff
	unsigned int size = (unsigned int)this->d_points.size();
	Ogre::Vector3 vaabMin = Ogre::Vector3::ZERO;
	Ogre::Vector3 vaabMax = Ogre::Vector3::ZERO;

	float *prPos = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));

	for(unsigned int i = 0; i < size; i++)
	{
		*prPos++ = this->d_points[i].x;
		*prPos++ = this->d_points[i].y;
		*prPos++ = this->d_points[i].z;

		*prPos++ = 0;

		if (this->d_points[i].x < vaabMin.x)
			vaabMin.x = this->d_points[i].x;
		else if (this->d_points[i].x > vaabMax.x)
			vaabMax.x = this->d_points[i].x;

		if (this->d_points[i].y < vaabMin.y)
			vaabMin.y = this->d_points[i].y;
		else if (this->d_points[i].y > vaabMax.y)
			vaabMax.y = this->d_points[i].y;

		if (this->d_points[i].z < vaabMin.z)
			vaabMin.z = this->d_points[i].z;
		else if (this->d_points[i].z > vaabMax.z)
			vaabMax.z = this->d_points[i].z;
	}

	vbuf->unlock();

	this->mBox.setInfinite();
	this->mBox.setExtents(vaabMin, vaabMax);
}
void mm_bullet_debug_lines::clear()
{
	this->d_points.clear();
}
void mm_bullet_debug_lines::addLine(const Ogre::Vector3 &start,const Ogre::Vector3 &end)
{
	this->d_points.push_back(start);
	this->d_points.push_back(end);
}
void mm_bullet_debug_lines::addLine(Ogre::Real start_x, Ogre::Real start_y, Ogre::Real start_z, 
			 Ogre::Real end_x, Ogre::Real end_y, Ogre::Real end_z)
{
	this->addLine(Ogre::Vector3(start_x,start_y,start_z),
		Ogre::Vector3(end_x,end_y,end_z));
}

void mm_bullet_debug_lines::addPoint(const Ogre::Vector3 &pt)
{
	this->d_points.push_back(pt);
}

void mm_bullet_debug_lines::addPoint(Ogre::Real x, Ogre::Real y, Ogre::Real z)
{
	this->addPoint(Ogre::Vector3(x, y, z));
}
