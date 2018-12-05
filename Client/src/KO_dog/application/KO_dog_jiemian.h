#ifndef __KO_dog_jiemian_h__
#define __KO_dog_jiemian_h__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "math/mm_vector3.h"

#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreViewport.h"
#include "OgreEntity.h"

#include "dotsceneloader/DotSceneLoader.h"

//#include "unit/DishUnitAnimation.h"
#include "unit/mm_unit_animation.h"
#include "unit/mm_unit_audio.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"
#include "KO_dog_zhujiemian.h"



//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class KO_dog_jiemian
	{
	public:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	public:
		KO_dog_zhujiemian zhujiemian;

	public:
		KO_dog_jiemian();
		virtual ~KO_dog_jiemian();

	public:
		virtual void assign_flake_context(mm_flake_context* flake_context);
	public:
		virtual void on_finish_launching(mm_flake_surface* surface);
		virtual void on_before_terminate(mm_flake_surface* surface);

	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_jiemian_h__