#ifndef __mm_emu_frame_h__
#define __mm_emu_frame_h__

#include "core/mm_core.h"
#include "core/mm_string.h"

#include "flake/mm_flake_context.h"

#include "CEGUI/BasicImage.h"

#include "OgreHardwarePixelBuffer.h"

#include "core/mm_prefix.h"

//////////////////////////////////////////////////////////////////////////
static const std::string MM_EMU_FRAME_OGRE_TEXTURE = "_ogre_texture_emu_";
static const std::string MM_EMU_FRAME_CEGUI_TEXTURE = "_cegui_texture_emu_";
static const std::string MM_EMU_FRAME_CEGUI_IMAGE = "_cegui_image_emu_";
//////////////////////////////////////////////////////////////////////////
struct mm_emu_frame
{
	mm::mm_flake_context* d_Context;// weak ref.

	std::string d_Name;// strong ref. name pattern resource. default is "mm".

	std::string d_name_ogre_texture_emu_0;
	std::string d_name_ogre_texture_emu_1;
	std::string d_name_cegui_texture_emu;
	std::string d_name_cegui_image_emu;

	Ogre::TexturePtr d_ogre_texture0;// strong ref.
	Ogre::TexturePtr d_ogre_texture1;// strong ref.

	CEGUI::Texture* d_cegui_texture;// strong ref.
	CEGUI::BasicImage* d_image;// strong ref.

	Ogre::HardwarePixelBufferSharedPtr d_HardwarePixelBuffer0;// weak ref.
	Ogre::HardwarePixelBufferSharedPtr d_HardwarePixelBuffer1;// weak ref.

	// cache texture w h.
	mm_uint32_t d_texture_w;
	mm_uint32_t d_texture_h;

	mm_atomic_t d_locker_ScreenPtr_0;
	mm_atomic_t d_locker_ScreenPtr_1;
	mm_uint32_t d_ScreenBuffSize;
	mm_uint32_t d_ScreenRealSize;
	mm_byte_t* d_ScreenBufferPtr;
	mm_byte_t* d_ScreenPtr[2];
};
void mm_emu_frame_init(struct mm_emu_frame* p);
void mm_emu_frame_destroy(struct mm_emu_frame* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_SetContext(struct mm_emu_frame* p, mm::mm_flake_context* context);
void mm_emu_frame_SetName(struct mm_emu_frame* p, const std::string& name);
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_CreateSource(struct mm_emu_frame* p);
void mm_emu_frame_DeleteSource(struct mm_emu_frame* p);
//////////////////////////////////////////////////////////////////////////
// render thread.
// palette_rgb x 256
void mm_emu_frame_UpdatePalette(struct mm_emu_frame* p, struct mm_emu_rgbquad* palette_rgb);
void mm_emu_frame_UpdateFrameBitmap(struct mm_emu_frame* p);
//////////////////////////////////////////////////////////////////////////
// emulator thread.
void mm_emu_frame_ProcessBuffer(struct mm_emu_frame* p, mm_byte_t* buffer, size_t length);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_emu_frame_h__