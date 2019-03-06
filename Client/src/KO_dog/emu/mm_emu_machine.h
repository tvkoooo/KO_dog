#ifndef __mm_emu_machine_h__
#define __mm_emu_machine_h__

#include "core/mm_core.h"

#include "emu/mm_emu_emulator.h"

#include "emu/mm_emu_audio.h"
#include "emu/mm_emu_frame.h"

//////////////////////////////////////////////////////////////////////////
struct mm_emu_machine
{
	struct mm_emu_emulator_processor super;

	mm::mm_flake_context* d_Context;// weak ref.

	std::string d_Name;// strong ref. name pattern resource. default is "mm".
	std::string d_DataPath;// default is "emu"
	std::string d_WritablePath;// default is "emu", mm_file_context writable path + "/" + d_WritablePath.

	struct mm_emu_emulator d_Emulator;

	struct mm_emu_audio d_Audio;
	struct mm_emu_frame d_Frame;
};
void mm_emu_machine_init(struct mm_emu_machine* p);
void mm_emu_machine_destroy(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_SetContext(struct mm_emu_machine* p, mm::mm_flake_context* context);
void mm_emu_machine_SetName(struct mm_emu_machine* p, const std::string& name);
void mm_emu_machine_SetRomPath(struct mm_emu_machine* p, const char* szRomPath);
void mm_emu_machine_SetDataPath(struct mm_emu_machine* p, const std::string& path);
void mm_emu_machine_SetWritablePath(struct mm_emu_machine* p, const std::string& path);
//////////////////////////////////////////////////////////////////////////
mm_uint32_t mm_emu_machine_GetRomLoadCode(struct mm_emu_machine* p);
struct mm_file_context* mm_emu_machine_GetAssetsFileContext(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_UpdateAssetsPath(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
// NTSC/PAL/Dendy
void mm_emu_machine_SetVideoMode(struct mm_emu_machine* p, mm_int_t nMode);
// Load rom use event queue.
void mm_emu_machine_LoadRom(struct mm_emu_machine* p);
// Screen clear.
void mm_emu_machine_ScreenClear(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
// NTSC/PAL/Dendy
void mm_emu_machine_SetVideoModeImmediately(struct mm_emu_machine* p, mm_int_t nMode);
// Load rom Immediately, not use the event queue.
void mm_emu_machine_LoadRomImmediately(struct mm_emu_machine* p);
// Screen clear Immediately, not use the event queue.
void mm_emu_machine_ScreenClearImmediately(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_Play(struct mm_emu_machine* p);
void mm_emu_machine_Stop(struct mm_emu_machine* p);
void mm_emu_machine_Pause(struct mm_emu_machine* p);
void mm_emu_machine_Resume(struct mm_emu_machine* p);
mm_int_t mm_emu_machine_GetState(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
// event keyboard.
void mm_emu_machine_KeyboardPressed(struct mm_emu_machine* p, int id);
void mm_emu_machine_KeyboardRelease(struct mm_emu_machine* p, int id);
// event Mouse.
void mm_emu_machine_MouseBegan(struct mm_emu_machine* p, mm_long_t x, mm_long_t y, int button_mask);
void mm_emu_machine_MouseMoved(struct mm_emu_machine* p, mm_long_t x, mm_long_t y, int button_mask);
void mm_emu_machine_MouseEnded(struct mm_emu_machine* p, mm_long_t x, mm_long_t y, int button_mask);
// event window.
void mm_emu_machine_EnterBackground(struct mm_emu_machine* p);
void mm_emu_machine_EnterForeground(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
// For Manual bit controller Joypad.
void mm_emu_machine_JoypadBitSetData(struct mm_emu_machine* p, int n, mm_word_t data);
mm_word_t mm_emu_machine_JoypadBitGetData(struct mm_emu_machine* p, int n);
void mm_emu_machine_JoypadBitPressed(struct mm_emu_machine* p, int n, int id);
void mm_emu_machine_JoypadBitRelease(struct mm_emu_machine* p, int n, int id);
// For Manual bit controller Nsf.
void mm_emu_machine_NsfBitSetData(struct mm_emu_machine* p, mm_byte_t data);
mm_byte_t mm_emu_machine_NsfBitGetData(struct mm_emu_machine* p);
void mm_emu_machine_NsfBitPressed(struct mm_emu_machine* p, int id);
void mm_emu_machine_NsfBitRelease(struct mm_emu_machine* p, int id);
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_HardwareReset(struct mm_emu_machine* p);
void mm_emu_machine_SoftwareReset(struct mm_emu_machine* p);

void mm_emu_machine_StateLoad(struct mm_emu_machine* p, const char* szFName, mm_int_t n);
void mm_emu_machine_StateSave(struct mm_emu_machine* p, const char* szFName, mm_int_t n);

void mm_emu_machine_Snapshot(struct mm_emu_machine* p);

void mm_emu_machine_MoviePlay(struct mm_emu_machine* p, const char* szFName);
void mm_emu_machine_MovieRec(struct mm_emu_machine* p, const char* szFName);
void mm_emu_machine_MovieRecAppend(struct mm_emu_machine* p, const char* szFName);
void mm_emu_machine_MovieStop(struct mm_emu_machine* p);

void mm_emu_machine_WaveRecStart(struct mm_emu_machine* p, const char* szFName);
void mm_emu_machine_WaveRecStop(struct mm_emu_machine* p);

void mm_emu_machine_TapePlay(struct mm_emu_machine* p, const char* szFName);
void mm_emu_machine_TapeRec(struct mm_emu_machine* p, const char* szFName);
void mm_emu_machine_TapeStop(struct mm_emu_machine* p);

void mm_emu_machine_SetBarcodeData(struct mm_emu_machine* p, mm_byte_t* code, mm_int_t len);
void mm_emu_machine_SetTurboFileBank(struct mm_emu_machine* p, mm_int_t bank);
//////////////////////////////////////////////////////////////////////////
// render thread.
const std::string& mm_emu_machine_GetImageName(struct mm_emu_machine* p);
const std::string& mm_emu_machine_GetAliasTextureName0(struct mm_emu_machine* p);
const std::string& mm_emu_machine_GetAliasTextureName1(struct mm_emu_machine* p);
void mm_emu_machine_UpdateFrameBitmap(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_machine_Start(struct mm_emu_machine* p);
void mm_emu_machine_Interrupt(struct mm_emu_machine* p);
void mm_emu_machine_Shutdown(struct mm_emu_machine* p);
void mm_emu_machine_Join(struct mm_emu_machine* p);
//////////////////////////////////////////////////////////////////////////
// virtual function for super.
void mm_emu_machine_ThreadEnter(struct mm_emu_emulator_processor* super);
void mm_emu_machine_ThreadLeave(struct mm_emu_emulator_processor* super);
void mm_emu_machine_ProcessAudio(struct mm_emu_emulator_processor* super, mm_byte_t* buffer, size_t length);
void mm_emu_machine_ProcessFrame(struct mm_emu_emulator_processor* super, mm_byte_t* buffer, size_t length);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_emu_audio_h__