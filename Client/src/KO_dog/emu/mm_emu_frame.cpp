#include "mm_emu_frame.h"

#include "core/mm_spinlock.h"
#include "core/mm_integer.h"

#include "emu/mm_emu_screen.h"

#include "OgreTextureManager.h"

#include "CEGUIOgreRenderer/Texture.h"
#include "CEGUIOgreRenderer/GeometryBuffer.h"

#include "CEGUI/ImageManager.h"
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_init(struct mm_emu_frame* p)
{
	p->d_ScreenBuffSize = sizeof(mm_byte_t) * MM_EMU_SCREEN_WIDTH * MM_EMU_SCREEN_HEIGHT;
	p->d_ScreenRealSize = p->d_ScreenBuffSize;
	mm_roundup32(p->d_ScreenRealSize);
	p->d_ScreenBufferPtr = (mm_byte_t*)mm_malloc(p->d_ScreenRealSize * 2);
	p->d_ScreenPtr[0] = p->d_ScreenBufferPtr;
	p->d_ScreenPtr[1] = p->d_ScreenBufferPtr + p->d_ScreenRealSize;
	//
	p->d_Context = NULL;

	p->d_Name = "";

	p->d_name_ogre_texture_emu_0 = "";
	p->d_name_ogre_texture_emu_1 = "";
	p->d_name_cegui_texture_emu = "";
	p->d_name_cegui_image_emu = "";

	p->d_ogre_texture0.reset();
	p->d_ogre_texture1.reset();

	p->d_cegui_texture = NULL;
	p->d_image = NULL;

	p->d_HardwarePixelBuffer0.reset();
	p->d_HardwarePixelBuffer1.reset();

	p->d_PaletteRGB = NULL;

	p->d_texture_w = MM_EMU_SCREEN_WIDTH;
	p->d_texture_h = MM_EMU_SCREEN_HEIGHT;

	mm_spinlock_init(&p->d_locker_ScreenPtr_0, NULL);
	mm_spinlock_init(&p->d_locker_ScreenPtr_1, NULL);
	// 0x3F is black color index.
	mm_memset(p->d_ScreenBufferPtr, 0x3F, p->d_ScreenRealSize * 2);

	//
	mm_emu_frame_SetName(p, "mm");
	//
	mm_roundup32(p->d_texture_w);
	mm_roundup32(p->d_texture_h);
}
void mm_emu_frame_destroy(struct mm_emu_frame* p)
{
	p->d_Context = NULL;

	p->d_Name = "";

	p->d_name_ogre_texture_emu_0 = "";
	p->d_name_ogre_texture_emu_1 = "";
	p->d_name_cegui_texture_emu = "";
	p->d_name_cegui_image_emu = "";

	p->d_ogre_texture0.reset();
	p->d_ogre_texture1.reset();

	p->d_cegui_texture = NULL;
	p->d_image = NULL;

	p->d_HardwarePixelBuffer0.reset();
	p->d_HardwarePixelBuffer1.reset();

	p->d_PaletteRGB = NULL;

	p->d_texture_w = MM_EMU_SCREEN_WIDTH;
	p->d_texture_h = MM_EMU_SCREEN_HEIGHT;

	mm_spinlock_destroy(&p->d_locker_ScreenPtr_0);
	mm_spinlock_destroy(&p->d_locker_ScreenPtr_1);
	// 0x3F is black color index.
	mm_memset(p->d_ScreenBufferPtr, 0x3F, p->d_ScreenRealSize * 2);
	//
	mm_roundup32(p->d_texture_w);
	mm_roundup32(p->d_texture_h);
	//
	mm_free(p->d_ScreenBufferPtr);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_SetContext(struct mm_emu_frame* p, mm::mm_flake_context* context)
{
	p->d_Context = context;
}
void mm_emu_frame_SetName(struct mm_emu_frame* p, const std::string& name)
{
	p->d_Name = name;

	p->d_name_ogre_texture_emu_0 = MM_EMU_FRAME_OGRE_TEXTURE + p->d_Name + "_0";
	p->d_name_ogre_texture_emu_1 = MM_EMU_FRAME_OGRE_TEXTURE + p->d_Name + "_1";
	p->d_name_cegui_texture_emu = MM_EMU_FRAME_CEGUI_TEXTURE + p->d_Name;
	p->d_name_cegui_image_emu = MM_EMU_FRAME_CEGUI_IMAGE + p->d_Name;
}
void mm_emu_frame_SetPaletteRGB(struct mm_emu_frame* p, void* data)
{
	p->d_PaletteRGB = data;
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_CreateSource(struct mm_emu_frame* p)
{
	Ogre::TextureManager& _TextureManager = Ogre::TextureManager::getSingleton();
	CEGUI::ImageManager& _ImageManager = CEGUI::ImageManager::getSingleton();
	mm::mm_cegui_system* _cegui_system = &p->d_Context->d_cegui_system;
	CEGUI::CEGUIOgreRenderer* _ogre_renderer = _cegui_system->get_ogre_renderer();
	CEGUI::CEGUIOgreTexture* _ogre_texture = NULL;
	//
	CEGUI::Rectf _imageArea(0, 0, (float)p->d_texture_w, (float)p->d_texture_h);
	//
	p->d_ogre_texture0 = _TextureManager.createManual(
		p->d_name_ogre_texture_emu_0,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::TEX_TYPE_2D,
		(Ogre::uint)16,
		(Ogre::uint)16,
		1,
		0,
		Ogre::PF_A8R8G8B8,
		Ogre::TU_RENDERTARGET);

	p->d_ogre_texture1 = _TextureManager.createManual(
		p->d_name_ogre_texture_emu_1,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::TEX_TYPE_2D,
		(Ogre::uint)p->d_texture_w,
		(Ogre::uint)p->d_texture_h,
		1,
		0,
		Ogre::PF_L8,
		Ogre::TU_RENDERTARGET);

	p->d_HardwarePixelBuffer0 = p->d_ogre_texture0->getBuffer(0, 0);
	p->d_HardwarePixelBuffer1 = p->d_ogre_texture1->getBuffer(0, 0);

	p->d_cegui_texture = &_ogre_renderer->createTexture(p->d_name_cegui_texture_emu);
	_ogre_texture = static_cast<CEGUI::CEGUIOgreTexture*>(p->d_cegui_texture);
	_ogre_texture->setOgreTexture(p->d_ogre_texture1);

	p->d_image = static_cast<CEGUI::BasicImage*>(&_ImageManager.create("BasicImage", p->d_name_cegui_image_emu));
	p->d_image->setTexture(p->d_cegui_texture);

	p->d_image->setArea(_imageArea);
	p->d_image->setAutoScaled(CEGUI::ASM_Disabled);

	// update palette.
	mm_emu_frame_UpdatePalette(p);
}
void mm_emu_frame_DeleteSource(struct mm_emu_frame* p)
{
	Ogre::TextureManager& _TextureManager = Ogre::TextureManager::getSingleton();
	CEGUI::ImageManager& _ImageManager = CEGUI::ImageManager::getSingleton();
	mm::mm_cegui_system* _cegui_system = &p->d_Context->d_cegui_system;
	CEGUI::CEGUIOgreRenderer* _ogre_renderer = _cegui_system->get_ogre_renderer();

	_ImageManager.destroy(*p->d_image);
	_ogre_renderer->destroyTexture(*p->d_cegui_texture);
	_TextureManager.remove(p->d_ogre_texture0->getHandle());
	p->d_ogre_texture0.reset();
	_TextureManager.remove(p->d_ogre_texture1->getHandle());
	p->d_ogre_texture1.reset();
	//
	p->d_HardwarePixelBuffer0.reset();
	p->d_HardwarePixelBuffer1.reset();
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_EnterBackground(struct mm_emu_frame* p)
{

}
void mm_emu_frame_EnterForeground(struct mm_emu_frame* p)
{
	if (NULL != p->d_ogre_texture0.get())
	{
		// some time the HardwarePixelBuffer will change when EnterBackground and EnterForeground.
		p->d_HardwarePixelBuffer0 = p->d_ogre_texture0->getBuffer(0, 0);
		//
		mm_emu_frame_UpdatePalette(p);
	}
	if (NULL != p->d_ogre_texture1.get())
	{
		// some time the HardwarePixelBuffer will change when EnterBackground and EnterForeground.
		p->d_HardwarePixelBuffer1 = p->d_ogre_texture1->getBuffer(0, 0);
		//
		mm_emu_frame_UpdateFrameBitmap(p);
	}
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_UpdatePalette(struct mm_emu_frame* p)
{
	Ogre::PixelBox srcPixelBox(16, 16, 1, Ogre::PF_A8R8G8B8, (void*)p->d_PaletteRGB);
	Ogre::Box dstBox(0, 0, 16, 16);

	p->d_HardwarePixelBuffer0->blitFromMemory(srcPixelBox, dstBox);
}
void mm_emu_frame_UpdateFrameBitmap(struct mm_emu_frame* p)
{
	Ogre::PixelBox srcPixelBox(MM_EMU_SCREEN_WIDTH, MM_EMU_SCREEN_HEIGHT, 1, Ogre::PF_L8, NULL);
	Ogre::Box dstBox(0, 0, MM_EMU_SCREEN_WIDTH, MM_EMU_SCREEN_HEIGHT);

	if (mm_spinlock_trylock(&p->d_locker_ScreenPtr_1))
	{
		srcPixelBox.data = (void*)p->d_ScreenPtr[1];
		p->d_HardwarePixelBuffer1->blitFromMemory(srcPixelBox, dstBox);

		mm_spinlock_unlock(&p->d_locker_ScreenPtr_1);
	}
	else
	{
		mm_spinlock_lock(&p->d_locker_ScreenPtr_0);

		srcPixelBox.data = (void*)p->d_ScreenPtr[0];
		p->d_HardwarePixelBuffer1->blitFromMemory(srcPixelBox, dstBox);

		mm_spinlock_unlock(&p->d_locker_ScreenPtr_0);
	}
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_frame_ProcessBuffer(struct mm_emu_frame* p, mm_byte_t* buffer, size_t length)
{
	if (mm_spinlock_trylock(&p->d_locker_ScreenPtr_0))
	{
		mm_memcpy(p->d_ScreenPtr[0], buffer, length);

		mm_spinlock_lock(&p->d_locker_ScreenPtr_1);
		mm_integer_uintptr_swap((uintptr_t*)&p->d_ScreenPtr[0], (uintptr_t*)&p->d_ScreenPtr[1]);
		mm_spinlock_unlock(&p->d_locker_ScreenPtr_1);

		mm_spinlock_unlock(&p->d_locker_ScreenPtr_0);
	}
	else
	{
		mm_spinlock_lock(&p->d_locker_ScreenPtr_1);
		mm_memcpy(p->d_ScreenPtr[1], buffer, length);
		mm_spinlock_unlock(&p->d_locker_ScreenPtr_1);
	}
}
//////////////////////////////////////////////////////////////////////////
