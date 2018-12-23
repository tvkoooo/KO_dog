#ifndef __mm_windows_target_h__
#define __mm_windows_target_h__

#include "core/mm_core.h"

#include "flake/mm_cegui_system.h"

#include "OgreRenderTarget.h"
#include "OgreTexture.h"

#include "CEGUI/Window.h"
#include "CEGUI/Texture.h"
#include "CEGUI/BasicImage.h"

#include <string>

#include "core/mm_prefix.h"

// render scene to image.
static const std::string WINDOWS_TARGET_OGRE_RTT_TEXTURE  = "windows_target_ogre_rtt_texture_";
static const std::string WINDOWS_TARGET_CEGUI_RTT_TEXTURE = "windows_target_cegui_rtt_texture_";
static const std::string WINDOWS_TARGET_CEGUI_RTT_IMAGE   = "windows_target_cegui_rtt_image_";
struct mm_windows_target
{
	mm::mm_cegui_system* d_cegui_system;// weak ref.
	// Ogre::TextureManager windows_target_ogre_rtt_texture_%s
	// CEGUI::OgreRenderer  windows_target_cegui_rtt_texture_%s
	// CEGUI::ImageManager  windows_target_cegui_rtt_image_%s
	std::string d_name;// strong ref.name pattern for rtt resource.default is "mm".
	CEGUI::Window* d_image_window;// weak ref.
	//
	CEGUI::TextureTarget* d_cegui_texture_target;
	//
	CEGUI::Texture* d_cegui_texture;// strong ref.
	CEGUI::BasicImage* d_image;// strong ref.

	Ogre::TexturePtr d_ogre_texture;// strong ref.
	Ogre::RenderTarget* d_render_target;// weak ref.is target to d_ogre_texture.

	bool d_active;// default is true.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_windows_target_init(struct mm_windows_target* p);
extern void mm_windows_target_destroy(struct mm_windows_target* p);
//////////////////////////////////////////////////////////////////////////
// launch
extern void mm_windows_target_launching(struct mm_windows_target* p);
// closed
extern void mm_windows_target_terminate(struct mm_windows_target* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_windows_target_update(struct mm_windows_target* p, double interval);
//////////////////////////////////////////////////////////////////////////
// set active state.
extern void mm_windows_target_set_active(struct mm_windows_target* p,bool active);
// update windows target whether need active.
extern void mm_windows_target_active_update(struct mm_windows_target* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_windows_target_h__