// this converts to string
#define STR_(X) #X
// this makes sure the argument is expanded before converting to string
#define STR(X) STR_(X)

//#define KCA680
//#define KCA691
//#define KCA692
//#define KCA710
//#define FGO940
//#define FGO1100
//#define KCA730
#define KCA731

#ifdef KCA680

// IDA: import xref search for CoCreateInstance, rclsid.Data1 = 0x0BCDE0395
#define divaAudioInitPtr 0x14125B050

// IDA: binary search for 4C 8B 74 24 38 F3 44 0F 10 44 24 2C F3 44 0F 10 4C 24 28 F3 0F 10 7C 24 24 F3 0F 10 74 24 20 48 8B 74 24 40 48 8B 7C 24 48 4C 8B 64 24 30
#define divaAudioFillbufferPtr 0x14125BA80

// IDA: binary search for 45 8B C6 BA 50 00 00 00 48 8B CE
#define divaAudioAllocMixerPtr 0x14125AD80

// IDA: search for string SOUND_VOLUME then look directly below
#define stereoPtr 0x141948FB0

// IDA: divaAudioInit + 0x193, should be: call    qword ptr [rax+38h]
#define skipAudioCheckPtr 0x14125B1E3

// IDA: divaAudioInit + 0x1E3, should be: jb      loc_141232400
#define skipAudioCheckPtr2 0x14125B233

// IDA: divaAudioInit + 0x202, should be: cmp     word ptr [rbx+2], 0
#define skipAudioCheckPtr3 0x14125B252

// IDA: divaAudioInit + 0x284, should be: 0F 84 22 02 00 00       jz      loc_1412327BC
#define earlyReturnPtr 0x14125B2D4

#endif

#ifdef KCA691

#define HOOKVERSION STR_(6.91)
#define DLL_NAME_IN_LOG STR_(BoatToot)

// IDA: import xref search for CoCreateInstance, rclsid.Data1 = 0x0BCDE0395
#define divaAudioInitPtr 0x141277B60

// IDA: binary search for 4C 8B 74 24 38 F3 44 0F 10 44 24 2C F3 44 0F 10 4C 24 28 F3 0F 10 7C 24 24 F3 0F 10 74 24 20 48 8B 74 24 40 48 8B 7C 24 48 4C 8B 64 24 30
#define divaAudioFillbufferPtr 0x141278590

// IDA: binary search for 45 8B C6 BA 50 00 00 00 48 8B CE
#define divaAudioAllocMixerPtr 0x141277890

// IDA: search for string SOUND_VOLUME then look directly below
#define stereoPtr 0x14196AA70

// IDA: divaAudioInit + 0x193, should be: call    qword ptr [rax+38h]
#define skipAudioCheckPtr 0x141277CF3

// IDA: divaAudioInit + 0x1E3, should be: jb      loc_141232400
#define skipAudioCheckPtr2 0x141277D43

// IDA: divaAudioInit + 0x202, should be: cmp     word ptr [rbx+2], 0
#define skipAudioCheckPtr3 0x141277D62

// IDA: divaAudioInit + 0x284, should be: 0F 84 22 02 00 00       jz      loc_1412327BC
#define earlyReturnPtr 0x141277DE4

#endif


#ifdef KCA692

#define HOOKVERSION STR_(6.92)
#define DLL_NAME_IN_LOG STR_(BoatToot)

// IDA: import xref search for CoCreateInstance, rclsid.Data1 = 0x0BCDE0395
#define divaAudioInitPtr 0x141280090

// IDA: binary search for 4C 8B 74 24 38 F3 44 0F 10 44 24 2C F3 44 0F 10 4C 24 28 F3 0F 10 7C 24 24 F3 0F 10 74 24 20 48 8B 74 24 40 48 8B 7C 24 48 4C 8B 64 24 30
#define divaAudioFillbufferPtr 0x141280AC0

// IDA: binary search for 45 8B C6 BA 50 00 00 00 48 8B CE
#define divaAudioAllocMixerPtr 0x14127FDC0

// IDA: search for string SOUND_VOLUME then look directly below
#define stereoPtr 0x141975B10

// IDA: divaAudioInit + 0x193, should be: call    qword ptr [rax+38h]
#define skipAudioCheckPtr 0x141280223

// IDA: divaAudioInit + 0x1E3, should be: jb      loc_141232400
#define skipAudioCheckPtr2 0x141280273

// IDA: divaAudioInit + 0x202, should be: cmp     word ptr [rbx+2], 0
#define skipAudioCheckPtr3 0x141280292

// IDA: divaAudioInit + 0x284, should be: 0F 84 22 02 00 00       jz      loc_1412327BC
#define earlyReturnPtr 0x141280314

#endif

#ifdef FGO940

#define HOOKVERSION STR_(9.40)
#define DLL_NAME_IN_LOG STR_(MusicSummoner)

// IDA: import xref search for CoCreateInstance, rclsid.Data1 = 0x0BCDE0395
#define divaAudioInitPtr 0x140CC0F70

// IDA: (FGO) binary search for B8 00 80 FF FF EB 07, take the one with a lot of ADDITIONAL FUNCTION
#define divaAudioFillbufferPtr 0x140CC1A00

// IDA: (FGO) binary search for 48 C7 40 C8 FE FF FF FF 48 89 58 10 48 89 68 18 48 89 70 20 4D
#define divaAudioAllocMixerPtr 0x140CC0C80

// IDA: search for string SOUND_VOLUME then look directly below
#define stereoPtr 0x141401B60

// IDA: divaAudioInit + 0x193, should be: call    qword ptr [rax+38h]
#define skipAudioCheckPtr 0x140CC10FE

// IDA: divaAudioInit + 0x1E3, should be: jb      loc_141232400
#define skipAudioCheckPtr2 0x140CC114E

// IDA: divaAudioInit + 0x202, should be: cmp     word ptr [rbx+2], 0
#define skipAudioCheckPtr3 0x140CC1167

// IDA: divaAudioInit + 0x284, should be: 0F 84 22 02 00 00       jz      loc_1412327BC
#define earlyReturnPtr 0x140CC1206

#endif

#ifdef KCA710

#define HOOKVERSION STR_(7.10)
#define DLL_NAME_IN_LOG STR_(BoatToot)

// IDA: import xref search for CoCreateInstance, rclsid.Data1 = 0x0BCDE0395
#define divaAudioInitPtr 0x14128D050

// IDA: binary search for 4C 8B 74 24 38 F3 44 0F 10 44 24 2C F3 44 0F 10 4C 24 28 F3 0F 10 7C 24 24 F3 0F 10 74 24 20 48 8B 74 24 40 48 8B 7C 24 48 4C 8B 64 24 30
#define divaAudioFillbufferPtr 0x14128DA80

// IDA: binary search for 45 8B C6 BA 50 00 00 00 48 8B CE
#define divaAudioAllocMixerPtr 0x14128CD80

// IDA: search for string SOUND_VOLUME then look directly below
#define stereoPtr 0x141986BF0

// IDA: divaAudioInit + 0x193, should be: call    qword ptr [rax+38h]
#define skipAudioCheckPtr 0x14128D1E3

// IDA: divaAudioInit + 0x1E3, should be: jb      loc_141232400
#define skipAudioCheckPtr2 0x14128D233

// IDA: divaAudioInit + 0x202, should be: cmp     word ptr [rbx+2], 0
#define skipAudioCheckPtr3 0x14128D252

// IDA: divaAudioInit + 0x284, should be: 0F 84 22 02 00 00       jz      loc_1412327BC
#define earlyReturnPtr 0x14128D2D4

#endif

#ifdef FGO1100

#define HOOKVERSION STR_(11.00)
#define DLL_NAME_IN_LOG STR_(MusicSummoner)

// IDA: import xref search for CoCreateInstance, rclsid.Data1 = 0x0BCDE0395
#define divaAudioInitPtr 0x140D35AC0

// IDA: (FGO) binary search for B8 00 80 FF FF EB 07, take the one with a lot of ADDITIONAL FUNCTION
#define divaAudioFillbufferPtr 0x140D36550

// IDA: (FGO) binary search for 48 C7 40 C8 FE FF FF FF 48 89 58 10 48 89 68 18 48 89 70 20 4D
#define divaAudioAllocMixerPtr 0x140D357D0

// IDA: search for string SOUND_VOLUME then look directly below
#define stereoPtr 0x1414D3800

// IDA: divaAudioInit + 0x193, should be: call    qword ptr [rax+38h]
#define skipAudioCheckPtr 0x140D35C4E

// IDA: divaAudioInit + 0x1E3, should be: jb      loc_141232400
#define skipAudioCheckPtr2 0x140D35C9E

// IDA: divaAudioInit + 0x202, should be: cmp     word ptr [rbx+2], 0
#define skipAudioCheckPtr3 0x140D35CB7

// IDA: divaAudioInit + 0x284, should be: 0F 84 22 02 00 00       jz      loc_1412327BC
#define earlyReturnPtr 0x140D35D56

#endif

#ifdef KCA730

#define HOOKVERSION STR_(7.30)
#define DLL_NAME_IN_LOG STR_(BoatToot)

// IDA: import xref search for CoCreateInstance, rclsid.Data1 = 0x0BCDE0395
#define divaAudioInitPtr 0x1412DFED0

// IDA: binary search for 4C 8B 74 24 38 F3 44 0F 10 44 24 2C F3 44 0F 10 4C 24 28 F3 0F 10 7C 24 24 F3 0F 10 74 24 20 48 8B 74 24 40 48 8B 7C 24 48 4C 8B 64 24 30
#define divaAudioFillbufferPtr 0x1412E0900

// IDA: binary search for 45 8B C6 BA 50 00 00 00 48 8B CE
#define divaAudioAllocMixerPtr 0x1412DFC00

// IDA: search for string SOUND_VOLUME then look directly below
#define stereoPtr 0x1419EA580

// IDA: divaAudioInit + 0x193, should be: call    qword ptr [rax+38h]
#define skipAudioCheckPtr 0x1412E0063

// IDA: divaAudioInit + 0x1E3, should be: jb      loc_141232400
#define skipAudioCheckPtr2 0x1412E00B3

// IDA: divaAudioInit + 0x202, should be: cmp     word ptr [rbx+2], 0
#define skipAudioCheckPtr3 0x1412E00D2

// IDA: divaAudioInit + 0x284, should be: 0F 84 22 02 00 00       jz      loc_1412327BC
#define earlyReturnPtr 0x1412E0154

#endif

#ifdef KCA731

#define HOOKVERSION STR_(7.31)
#define DLL_NAME_IN_LOG STR_(BoatToot)

#define divaAudioInitPtr 0x1412DFF20
#define divaAudioFillbufferPtr 0x1412E0950
#define divaAudioAllocMixerPtr 0x1412DFC50
#define stereoPtr 0x1419EA580
#define skipAudioCheckPtr 0x1412E00B3
#define skipAudioCheckPtr2 0x1412E0103
#define skipAudioCheckPtr3 0x1412E0122
#define earlyReturnPtr 0x1412E01A4

#endif