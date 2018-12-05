#include "mm_windows_target.h"
#include "core/mm_logger.h"
#include "flake/mm_cegui_system.h"
//#include "flake/mm_flake_application.h"

#include "OgreRenderTexture.h"
#include "OgreHardwareBuffer.h"
#include "OgreHardwarePixelBuffer.h"
#include "OgreTextureManager.h"
#include "OgreRenderTarget.h"

#include "CEGUI/WindowManager.h"
#include "CEGUI/ImageManager.h"
#include "CEGUI/TextureTarget.h"

#include "CEGUIOgreRenderer/Texture.h"
#include "CEGUIOgreRenderer/TextureTarget.h"

void mm_windows_target_init(struct mm_windows_target* p)
{
	p->d_cegui_system = NULL;
	p->d_name = "mm";
	p->d_image_window = NULL;

	p->d_cegui_texture_target = NULL;

	p->d_cegui_texture = NULL;
	p->d_image = NULL;

	p->d_ogre_texture = Ogre::TexturePtr();
	p->d_render_target = NULL;

	p->d_active = true;
}
void mm_windows_target_destroy(struct mm_windows_target* p)
{
	p->d_name = "mm";
	p->d_image_window = NULL;

	p->d_cegui_texture_target = NULL;

	p->d_cegui_texture = NULL;
	p->d_image = NULL;

	p->d_ogre_texture = Ogre::TexturePtr();
	p->d_render_target = NULL;

	p->d_active = true;
}
void mm_windows_target_launching(struct mm_windows_target* p)
{
	assert(p->d_image_window&&"p->d_image_window is null.");
	struct mm_logger* g_logger = mm_logger_instance();
	//
	mm_logger_log_V(g_logger,"%s %d begin.",__FUNCTION__,__LINE__);
	//////////////////////////////////////////////////////////////////////////
	const CEGUI::Rectf& _rectf = p->d_image_window->getOuterRectClipper();

	float _win_w = _rectf.getWidth();
	float _win_h = _rectf.getHeight();
	_win_w = _win_w < 1 ? 1 : _win_w;
	_win_h = _win_h < 1 ? 1 : _win_h;

	CEGUI::CEGUIOgreRenderer* _ogre_renderer = p->d_cegui_system->get_ogre_renderer();
	p->d_cegui_texture_target = _ogre_renderer->createTextureTarget();
	p->d_cegui_texture_target->declareRenderSize(CEGUI::Sizef(_win_w, _win_h));
	p->d_cegui_texture = &p->d_cegui_texture_target->getTexture();
	CEGUI::CEGUIOgreTexture* _ogre_texture = static_cast<CEGUI::CEGUIOgreTexture*>(p->d_cegui_texture);
	p->d_ogre_texture = _ogre_texture->getOgreTexture();
	CEGUI::CEGUIOgreTextureTarget* _cegui_ogre_render_target = static_cast<CEGUI::CEGUIOgreTextureTarget*>(p->d_cegui_texture_target);
	p->d_render_target = _cegui_ogre_render_target->getOgreRenderTarget();

	//Ogre::TextureManager& _texMgr = Ogre::TextureManager::getSingleton();
	//p->d_ogre_texture =_texMgr.createManual(
	//	WINDOWS_TARGET_OGRE_RTT_TEXTURE + p->d_name,  
	//	Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	//	Ogre::TEX_TYPE_2D,
	//	(Ogre::uint)_win_w,
	//	(Ogre::uint)_win_h,
	//	1,
	//	0,
	//	Ogre::PF_R8G8B8,
	//	Ogre::TU_RENDERTARGET);
	//p->d_render_target = p->d_ogre_texture->getBuffer()->getRenderTarget();

	//CEGUI::CEGUIOgreRenderer* _ogre_renderer = p->d_cegui_system->get_ogre_renderer();
	//p->d_cegui_texture = &_ogre_renderer->createTexture(WINDOWS_TARGET_CEGUI_RTT_TEXTURE + p->d_name);
	//CEGUI::CEGUIOgreTexture* _ogre_texture = static_cast<CEGUI::CEGUIOgreTexture*>(p->d_cegui_texture);
	//_ogre_texture->setOgreTexture(p->d_ogre_texture);

	CEGUI::ImageManager& _imageMgr = CEGUI::ImageManager::getSingleton();
	p->d_image = static_cast<CEGUI::BasicImage*>(&_imageMgr.create("BasicImage",WINDOWS_TARGET_CEGUI_RTT_IMAGE + p->d_name));
	p->d_image->setTexture(p->d_cegui_texture);

	// note : if render target is a rtt,the actual size is roundup 2^n, not the real display size.
	// here we center it to image display size.
	float _tex_real_w = (float)p->d_ogre_texture->getWidth();
	float _tex_real_h = (float)p->d_ogre_texture->getHeight();
	float _real_ratio = _tex_real_w / _tex_real_h;
	float _view_ratio = _win_w / _win_h;
	float _hw = 0;
	float _hh = 0;
	if ( _real_ratio < _view_ratio )
	{
		_hw = 0;
		_hh = (_tex_real_h - _tex_real_w / _view_ratio) / 2.0f;
	}
	else
	{
		_hw = (_tex_real_w - _tex_real_h * _view_ratio) / 2.0f;
		_hh = 0;
	}
	CEGUI::Rectf _imageArea(_hw, _hh, _tex_real_w -_hw, _tex_real_h - _hh);
	// CEGUI::Rectf _imageArea(0, 0, _tex_real_w, _tex_real_h);
	p->d_image->setArea(_imageArea);
	p->d_image->setAutoScaled(CEGUI::ASM_Disabled);

	p->d_image_window->setProperty("Image", p->d_image->getName());
	//
	mm_windows_target_active_update(p);
	//
	mm_logger_log_V(g_logger,"%s %d end.",__FUNCTION__,__LINE__);
}
void mm_windows_target_terminate(struct mm_windows_target* p)
{
	CEGUI::ImageManager& _imageMgr = CEGUI::ImageManager::getSingleton();
	_imageMgr.destroy(*p->d_image);
	CEGUI::CEGUIOgreRenderer* _ogre_renderer = p->d_cegui_system->get_ogre_renderer();
	_ogre_renderer->destroyTextureTarget(p->d_cegui_texture_target);
	p->d_ogre_texture = Ogre::TexturePtr();

	//CEGUI::ImageManager& _imageMgr = CEGUI::ImageManager::getSingleton();
	//_imageMgr.destroy(*p->d_image);
	//CEGUI::CEGUIOgreRenderer* _ogre_renderer = p->d_cegui_system->get_ogre_renderer();
	//_ogre_renderer->destroyTexture(*p->d_cegui_texture);
	//Ogre::TextureManager& _texMgr = Ogre::TextureManager::getSingleton();
	//_texMgr.remove(p->d_ogre_texture->getHandle());
	//p->d_ogre_texture = Ogre::TexturePtr();
}
// set active state.
void mm_windows_target_set_active(struct mm_windows_target* p,bool active)
{
	assert(p->d_render_target&&"p->d_render_target is a null.");
	p->d_active = active;
	mm_windows_target_active_update(p);
}
void mm_windows_target_active_update(struct mm_windows_target* p)
{
	const CEGUI::Rectf& _rectf = p->d_image_window->getOuterRectClipper();
	float _win_w = _rectf.getWidth();
	float _win_h = _rectf.getHeight();
	p->d_render_target->setActive( p->d_active && 0 !=_win_w && 0 != _win_h );
}
//////////////////////////////////////////////////////////////////////////
