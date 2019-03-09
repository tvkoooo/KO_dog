#include "mm_emu_machine.h"

#include "emu/mm_emu_nes.h"

#include "dish/mm_file_path.h"

//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_init(struct mm_emu_machine* p)
{
	p->d_Context = NULL;

	p->d_Name = "mm";
	p->d_DataPath = "emu";
	p->d_WritablePath = "emu";

	mm_emu_emulator_processor_init(&p->super);

	mm_emu_emulator_init(&p->d_Emulator);
	mm_emu_audio_init(&p->d_Audio);
	mm_emu_frame_init(&p->d_Frame);
	//
	mm_emu_emulator_SetProcessor(&p->d_Emulator, &p->super);

	mm_emu_frame_SetPaletteRGB(&p->d_Frame, p->d_Emulator.palette_rgb);

	mm_emu_audio_SetRate(&p->d_Audio, p->d_Emulator.emu->config.audio.nRate);
	mm_emu_audio_SetFormat(&p->d_Audio, AL_FORMAT_MONO8);

	//
	p->super.ThreadEnter = &mm_emu_machine_ThreadEnter;
	p->super.ThreadLeave = &mm_emu_machine_ThreadLeave;
	p->super.ProcessAudio = &mm_emu_machine_ProcessAudio;
	p->super.ProcessFrame = &mm_emu_machine_ProcessFrame;
}
void mm_emu_machine_destroy(struct mm_emu_machine* p)
{
	p->d_Context = NULL;

	p->d_Name = "mm";
	p->d_DataPath = "emu";
	p->d_WritablePath = "emu";

	mm_emu_emulator_processor_destroy(&p->super);

	mm_emu_emulator_destroy(&p->d_Emulator);
	mm_emu_audio_destroy(&p->d_Audio);
	mm_emu_frame_destroy(&p->d_Frame);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_SetContext(struct mm_emu_machine* p, mm::mm_flake_context* context)
{
	p->d_Context = context;

	mm_emu_frame_SetContext(&p->d_Frame, p->d_Context);
}
void mm_emu_machine_SetName(struct mm_emu_machine* p, const std::string& name)
{
	p->d_Name = name;

	mm_emu_frame_SetName(&p->d_Frame, p->d_Name);
}
void mm_emu_machine_SetRomPath(struct mm_emu_machine* p, const char* szRomPath)
{
	mm_emu_emulator_SetRomPath(&p->d_Emulator, szRomPath);
}
void mm_emu_machine_SetDataPath(struct mm_emu_machine* p, const std::string& path)
{
	p->d_DataPath = path;
}
void mm_emu_machine_SetWritablePath(struct mm_emu_machine* p, const std::string& path)
{
	p->d_WritablePath = path;
}
//////////////////////////////////////////////////////////////////////////
mm_uint32_t mm_emu_machine_GetRomLoadCode(struct mm_emu_machine* p)
{
	return mm_emu_emulator_GetRomLoadCode(&p->d_Emulator);
}
struct mm_file_context* mm_emu_machine_GetAssetsFileContext(struct mm_emu_machine* p)
{
	return &p->d_Emulator.emu->assets.file_context;
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_UpdateAssetsPath(struct mm_emu_machine* p)
{
	struct mm_file_context* _file_context = &p->d_Context->d_file_context;

	std::string external_files_directory;
	std::string external_files_directory_writable_path;

	struct mm_string emu_writable_path;
	struct mm_string emu_root_folder_base;
	struct mm_string emu_root_source_base;

	mm_string_init(&emu_writable_path);
	mm_string_init(&emu_root_folder_base);
	mm_string_init(&emu_root_source_base);

	external_files_directory = p->d_Context->get_external_files_directory();
	//
	external_files_directory_writable_path += external_files_directory;
	external_files_directory_writable_path += external_files_directory.empty() ? "" : "/";
	external_files_directory_writable_path += p->d_WritablePath;
	mm_string_assigns(&emu_writable_path, external_files_directory_writable_path.c_str());
	// use little base.
	mm_string_assigns(&emu_root_folder_base, _file_context->assets_root_folder_base.s);
	mm_string_append(&emu_root_folder_base, 0 == _file_context->assets_root_folder_base.l ? "" : "/");
	mm_string_append(&emu_root_folder_base, p->d_DataPath.c_str());

	mm_string_assigns(&emu_root_source_base, _file_context->assets_root_source_base.s);
	mm_string_append(&emu_root_source_base, 0 == _file_context->assets_root_source_base.l ? "" : "/");
	mm_string_append(&emu_root_source_base, p->d_DataPath.c_str());
	//
	mm_mkdir_if_not_exist(emu_writable_path.s);
	// use the main file_context.
	mm_emu_emulator_SetResourceRoot(&p->d_Emulator, MM_EMU_ASSETS_FOLDER, _file_context->assets_root_folder_path.s, emu_root_folder_base.s);
	mm_emu_emulator_SetResourceRoot(&p->d_Emulator, MM_EMU_ASSETS_SOURCE, _file_context->assets_root_source_path.s, emu_root_source_base.s);
	//
	mm_emu_emulator_SetWritablePath(&p->d_Emulator, emu_writable_path.s);
	//
	mm_string_destroy(&emu_writable_path);
	mm_string_destroy(&emu_root_folder_base);
	mm_string_destroy(&emu_root_source_base);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_SetVideoMode(struct mm_emu_machine* p, mm_int_t nMode)
{
	mm_emu_emulator_SetVideoMode(&p->d_Emulator, nMode);
}
void mm_emu_machine_LoadRom(struct mm_emu_machine* p)
{
	mm_emu_emulator_LoadRom(&p->d_Emulator);
}
void mm_emu_machine_ScreenClear(struct mm_emu_machine* p)
{
	mm_emu_emulator_ScreenClear(&p->d_Emulator);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_SetVideoModeImmediately(struct mm_emu_machine* p, mm_int_t nMode)
{
	mm_emu_emulator_SetVideoModeImmediately(&p->d_Emulator, nMode);
}
void mm_emu_machine_LoadRomImmediately(struct mm_emu_machine* p)
{
	mm_emu_emulator_LoadRomImmediately(&p->d_Emulator);
}
void mm_emu_machine_ScreenClearImmediately(struct mm_emu_machine* p)
{
	mm_emu_emulator_ScreenClearImmediately(&p->d_Emulator);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_Play(struct mm_emu_machine* p)
{
	mm_emu_emulator_Play(&p->d_Emulator);
}
void mm_emu_machine_Stop(struct mm_emu_machine* p)
{
	mm_emu_emulator_Stop(&p->d_Emulator);
}
void mm_emu_machine_Pause(struct mm_emu_machine* p)
{
	mm_emu_emulator_Pause(&p->d_Emulator);
}
void mm_emu_machine_Resume(struct mm_emu_machine* p)
{
	mm_emu_emulator_Resume(&p->d_Emulator);
}
mm_int_t mm_emu_machine_GetState(struct mm_emu_machine* p)
{
	return mm_emu_emulator_GetState(&p->d_Emulator);
}
//////////////////////////////////////////////////////////////////////////
// event keyboard.
void mm_emu_machine_KeyboardPressed(struct mm_emu_machine* p, int id)
{
	mm_emu_emulator_KeyboardPressed(&p->d_Emulator, id);
}
void mm_emu_machine_KeyboardRelease(struct mm_emu_machine* p, int id)
{
	mm_emu_emulator_KeyboardRelease(&p->d_Emulator, id);
}
// event Mouse.
void mm_emu_machine_MouseBegan(struct mm_emu_machine* p, mm_long_t x, mm_long_t y, int button_mask)
{
	mm_emu_emulator_MouseBegan(&p->d_Emulator, x, y, button_mask);
}
void mm_emu_machine_MouseMoved(struct mm_emu_machine* p, mm_long_t x, mm_long_t y, int button_mask)
{
	mm_emu_emulator_MouseMoved(&p->d_Emulator, x, y, button_mask);
}
void mm_emu_machine_MouseEnded(struct mm_emu_machine* p, mm_long_t x, mm_long_t y, int button_mask)
{
	mm_emu_emulator_MouseEnded(&p->d_Emulator, x, y, button_mask);
}
// event window.
void mm_emu_machine_EnterBackground(struct mm_emu_machine* p)
{
	mm_emu_emulator_EnterBackground(&p->d_Emulator);
	mm_emu_frame_EnterBackground(&p->d_Frame);
}
void mm_emu_machine_EnterForeground(struct mm_emu_machine* p)
{
	mm_emu_emulator_EnterForeground(&p->d_Emulator);
	mm_emu_frame_EnterForeground(&p->d_Frame);
}
//////////////////////////////////////////////////////////////////////////
// For Manual bit controller Joypad.
void mm_emu_machine_JoypadBitSetData(struct mm_emu_machine* p, int n, mm_word_t data)
{
	mm_emu_emulator_JoypadBitSetData(&p->d_Emulator, n, data);
}
mm_word_t mm_emu_machine_JoypadBitGetData(struct mm_emu_machine* p, int n)
{
	return mm_emu_emulator_JoypadBitGetData(&p->d_Emulator, n);
}
void mm_emu_machine_JoypadBitPressed(struct mm_emu_machine* p, int n, int id)
{
	mm_emu_emulator_JoypadBitPressed(&p->d_Emulator, n, id);
}
void mm_emu_machine_JoypadBitRelease(struct mm_emu_machine* p, int n, int id)
{
	mm_emu_emulator_JoypadBitRelease(&p->d_Emulator, n, id);
}
// For Manual bit controller Nsf.
void mm_emu_machine_NsfBitSetData(struct mm_emu_machine* p, mm_byte_t data)
{
	mm_emu_emulator_NsfBitSetData(&p->d_Emulator, data);
}
mm_byte_t mm_emu_machine_NsfBitGetData(struct mm_emu_machine* p)
{
	return mm_emu_emulator_NsfBitGetData(&p->d_Emulator);
}
void mm_emu_machine_NsfBitPressed(struct mm_emu_machine* p, int id)
{
	mm_emu_emulator_NsfBitPressed(&p->d_Emulator, id);
}
void mm_emu_machine_NsfBitRelease(struct mm_emu_machine* p, int id)
{
	mm_emu_emulator_NsfBitRelease(&p->d_Emulator, id);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_HardwareReset(struct mm_emu_machine* p)
{
	mm_emu_emulator_HardwareReset(&p->d_Emulator);
}
void mm_emu_machine_SoftwareReset(struct mm_emu_machine* p)
{
	mm_emu_emulator_SoftwareReset(&p->d_Emulator);
}
void mm_emu_machine_StateLoad(struct mm_emu_machine* p, const char* szFName, mm_int_t n)
{
	mm_emu_emulator_StateLoad(&p->d_Emulator, szFName, n);
}
void mm_emu_machine_StateSave(struct mm_emu_machine* p, const char* szFName, mm_int_t n)
{
	mm_emu_emulator_StateSave(&p->d_Emulator, szFName, n);
}
void mm_emu_machine_Snapshot(struct mm_emu_machine* p)
{
	mm_emu_emulator_Snapshot(&p->d_Emulator);
}
void mm_emu_machine_MoviePlay(struct mm_emu_machine* p, const char* szFName)
{
	mm_emu_emulator_MoviePlay(&p->d_Emulator, szFName);
}
void mm_emu_machine_MovieRec(struct mm_emu_machine* p, const char* szFName)
{
	mm_emu_emulator_MovieRec(&p->d_Emulator, szFName);
}
void mm_emu_machine_MovieRecAppend(struct mm_emu_machine* p, const char* szFName)
{
	mm_emu_emulator_MovieRecAppend(&p->d_Emulator, szFName);
}
void mm_emu_machine_MovieStop(struct mm_emu_machine* p)
{
	mm_emu_emulator_MovieStop(&p->d_Emulator);
}
void mm_emu_machine_WaveRecStart(struct mm_emu_machine* p, const char* szFName)
{
	mm_emu_emulator_WaveRecStart(&p->d_Emulator, szFName);
}
void mm_emu_machine_WaveRecStop(struct mm_emu_machine* p)
{
	mm_emu_emulator_WaveRecStop(&p->d_Emulator);
}

void mm_emu_machine_TapePlay(struct mm_emu_machine* p, const char* szFName)
{
	mm_emu_emulator_TapePlay(&p->d_Emulator, szFName);
}
void mm_emu_machine_TapeRec(struct mm_emu_machine* p, const char* szFName)
{
	mm_emu_emulator_TapeRec(&p->d_Emulator, szFName);
}
void mm_emu_machine_TapeStop(struct mm_emu_machine* p)
{
	mm_emu_emulator_TapeStop(&p->d_Emulator);
}

void mm_emu_machine_SetBarcodeData(struct mm_emu_machine* p, mm_byte_t* code, mm_int_t len)
{
	mm_emu_emulator_SetBarcodeData(&p->d_Emulator, code, len);
}
void mm_emu_machine_SetTurboFileBank(struct mm_emu_machine* p, mm_int_t bank)
{
	mm_emu_emulator_SetTurboFileBank(&p->d_Emulator, bank);
}
//////////////////////////////////////////////////////////////////////////
const std::string& mm_emu_machine_GetImageName(struct mm_emu_machine* p)
{
	return p->d_Frame.d_name_cegui_image_emu;
}
const std::string& mm_emu_machine_GetAliasTextureName0(struct mm_emu_machine* p)
{
	return p->d_Frame.d_name_ogre_texture_emu_0;
}
const std::string& mm_emu_machine_GetAliasTextureName1(struct mm_emu_machine* p)
{
	return p->d_Frame.d_name_ogre_texture_emu_1;
}
void mm_emu_machine_UpdateFrameBitmap(struct mm_emu_machine* p)
{
	mm_emu_frame_UpdateFrameBitmap(&p->d_Frame);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_Start(struct mm_emu_machine* p)
{
	mm_emu_frame_CreateSource(&p->d_Frame);
	//
	mm_emu_emulator_Start(&p->d_Emulator);
}
void mm_emu_machine_Interrupt(struct mm_emu_machine* p)
{
	mm_emu_emulator_Interrupt(&p->d_Emulator);
}
void mm_emu_machine_Shutdown(struct mm_emu_machine* p)
{
	mm_emu_emulator_Shutdown(&p->d_Emulator);
}
void mm_emu_machine_Join(struct mm_emu_machine* p)
{
	mm_emu_emulator_Join(&p->d_Emulator);

	mm_emu_frame_DeleteSource(&p->d_Frame);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_ThreadEnter(struct mm_emu_emulator_processor* super)
{
	struct mm_emu_machine* p = (struct mm_emu_machine*)(super);

	mm_emu_audio_CreateSource(&p->d_Audio);
	mm_emu_audio_play(&p->d_Audio);
}
void mm_emu_machine_ThreadLeave(struct mm_emu_emulator_processor* super)
{
	struct mm_emu_machine* p = (struct mm_emu_machine*)(super);

	mm_emu_audio_stop(&p->d_Audio);
	mm_emu_audio_DeleteSource(&p->d_Audio);
}
void mm_emu_machine_ProcessAudio(struct mm_emu_emulator_processor* super, mm_byte_t* buffer, size_t length)
{
	struct mm_emu_machine* p = (struct mm_emu_machine*)(super);

	mm_emu_audio_ProcessBuffer(&p->d_Audio, buffer, length);
}
void mm_emu_machine_ProcessFrame(struct mm_emu_emulator_processor* super, mm_byte_t* buffer, size_t length)
{
	struct mm_emu_machine* p = (struct mm_emu_machine*)(super);

	mm_emu_frame_ProcessBuffer(&p->d_Frame, buffer, length);
}
//////////////////////////////////////////////////////////////////////////
