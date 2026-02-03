#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <string>
#include <vector>
#include <thread>
#define MINIAUDIO_IMPLEMENTATION
#include "../miniaudio/miniaudio.h"
#include "../bassasio/bassasio.h"
#include <mmdeviceapi.h>
#include <audioclient.h>
#include "versions.h"

void (__cdecl* divaAudioInit)(void* cls, uint64_t unk, uint64_t unk2) = (void(__cdecl*)(void* cls, uint64_t unk, uint64_t unk2))divaAudioInitPtr;

// IDA: binary search for 4C 8B 74 24 38 F3 44 0F 10 44 24 2C F3 44 0F 10 4C 24 28 F3 0F 10 7C 24 24 F3 0F 10 74 24 20 48 8B 74 24 40 48 8B 7C 24 48 4C 8B 64 24 30
void (__cdecl* divaAudioFillbuffer)(void* mixer, int16_t* buf, uint64_t nFrames, bool disableHpVol, bool invertPhase) = (void(__cdecl*)(void* mixer, int16_t* buf, uint64_t nFrames, bool disableHpVol, bool invertPhase))divaAudioFillbufferPtr;
// mixer is a pointer to an audioMixer (from audio init's cls + 0x70)
// disableHpVol uses speaker volume for headphones (only works in 4ch mode)
// invertPhase inverts the output signal (only works if disableHpVol == false)

// IDA: binary search for 45 8B C6 BA 50 00 00 00 48 8B CE
int (__cdecl* divaAudioAllocMixer)(void* cls, uint64_t unk, uint64_t unk2, int64_t nFrames) = (int(__cdecl*)(void* cls, uint64_t unk, uint64_t unk2, int64_t nFrames))divaAudioAllocMixerPtr;
// unks are the same as from the init call. they seem to set the internal mixing channel counts(?) 
// cls is the same as mixer in divaAudioFillbuffer
// nFrames is number of audio frames to hold in the mixing buffers (only used when divaAudioFillbuffer is called). Internally this is multiplied by 16 (buffers are built using 32bit floats)

// __int64 __fastcall sub_1400D0DB0(__int64 a1, int a2)
//int(__fastcall* mtx_init)(void* mutex, int type) = (int(__cdecl*)(void* mutex, int type))0x1400D0DB0; // kca 6.50

#pragma pack(push, 1)
struct _50 {
	byte padding00[0x50];
};
struct _70 {
	byte padding00[0x70];
};

struct streamingState {
	std::vector<_50>* state;
	float* buffer;
	uint64_t buffer_size;
};

struct initClass;

struct audioMixer {
	initClass* audioClass;

	std::vector<_70>** state1;
	uint64_t state1_len;
	streamingState* state2;
	uint64_t state2_len;

	float* mixbuffer;
	uint64_t mixbuffer_size;

	void* volume_mutex; // not sure if this is pointer or not
	float volume_master;
	float volume_channels[4];

	byte padding54[4];
};

struct initClass {
	WAVEFORMATEXTENSIBLE wave_format;
	IMMDeviceEnumerator *pEnumerator;
	IMMDevice *pDevice;
	IAudioClient *pAudioClient;


	uint64_t buffer_size;

	IAudioRenderClient *pRenderClient;
	HANDLE hEvent;
	uint64_t unknown;

	uint64_t channels;
	uint64_t rate; // should always =44100
	uint64_t depth; // should always =16

	audioMixer* mixer;
	
	HANDLE* hCallback;
	int32_t breakDword;
};
#pragma pack(pop)

// known internal audio mixer variables (used by divaAudioFillbuffer and divaAudioAllocMixer)
// cls + 0x00 = pointer to main audio/init class
// cls + 0x08 = internal state 1 (SE?) vector pointer (or full class?)
// cls + 0x10 = internal state 1 (SE?) length (channels?)
// cls + 0x18 = internal state 2 (streaming?) vector pointer (or full class?)
// cls + 0x20 = internal state 2 (streaming?) length (channels?)
// cls + 0x28 = mixing buffer pointer (when a buffer is generated, this is filled with 32bit floats (four per frame)
// cls + 0x30 = mixing buffer size (frame count * 16)
//
// cls + 0x38 = mutex lock for volume
// cls + 0x40 = master volume float (multiply other volumes by this)
// cls + 0x44 = ch1 volume
// cls + 0x48 = ch2 volume
// cls + 0x4c = ch3 volume
// cls + 0x50 = ch4 volume
//
//
// known main/init audio class variables (used by divaAudioInit)
// cls + 0x0 = WAVEFORMATEXTENSIBLE wave_format (null with old method) (length 0x28)
// cls + 0x28 = IMMDeviceEnumerator *pEnumerator
// cls + 0x30 = IMMDevice *pDevice (default device)
// cls + 0x38 = IAudioClient *pAudioClient
//
// cls + 0x40 = buffer size in frames
//
// cls + 0x48 = IAudioRenderClient *pRenderClient
//
// cls + 0x50 = HANDLE hEvent (for original WASAPI buffer timing)
//
// cls + 0x58 = number of output channels
// cls + 0x60 = audio sample rate
// cls + 0x68 = audio bit depth (only 16bit works)
//
// cls + 0x70 = pointer to mixer class
//
// cls + 0x78 = HANDLE* hCallback (handle to original callback thread)
//
// cls + 0x80 = break flag dword (becomes 1 on exit)


initClass *divaAudCls;
audioMixer *divaAudioMixCls;

std::thread loopThread;

ma_context_config contextConfig;
ma_context context;
ma_device_config deviceConfig;
ma_device device;

int maInternalBufferSizeInMilliseconds;
int divaBufSizeInFrames;
int divaBufSizeInMilliseconds;

int nChannels; // this can only be 2 or 4
int bitDepth; // signed 16/24 bit integer or 32 bit float
int requestBuffer;
int nPeriods;
wchar_t backendName[32]; // wasapi or directsound
ma_backend maBackend;
ma_share_mode maSharemode;
bool useAsio;
int asioDevice;
bool showAsioPanel;

bool useOldInit;

std::wstring ExePath() {
	WCHAR buffer[MAX_PATH];
	GetModuleFileNameW(NULL, buffer, MAX_PATH);
	return std::wstring(buffer);
}

std::wstring DirPath() {
	std::wstring exepath = ExePath();
	std::wstring::size_type pos = exepath.find_last_of(L"\\/");
	return exepath.substr(0, pos);
}

std::wstring CONFIG_FILE_STRING = DirPath() + L"\\sound.ini";
LPCWSTR CONFIG_FILE = CONFIG_FILE_STRING.c_str();