//cno_config.h

#ifndef CNO_CONFIG_H
#define CNO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_OS == 1
#define CNO_CONFIG_DIRECTORIES 0
//static char *CNO_LowLevelConfig_Directories_a1[CNO_CONFIG_DIRECTORIES] = {"./config/","~/Library/Application Support/","~/.config/","/usr/local/etc/","/usr/etc/","/etc/"};
#elif CNO_OS == 2
#define CNO_CONFIG_DIRECTORIES 6
static char *CNO_LowLevelConfig_Directories_a1[CNO_CONFIG_DIRECTORIES] = {"~/Library/Application Support/","~/.config/","./config/","/usr/local/etc/","/usr/etc/","/etc/"};
#else
#define CNO_CONFIG_DIRECTORIES 6
static char *CNO_LowLevelConfig_Directories_a1[CNO_CONFIG_DIRECTORIES] = {"~/.config/","./config/","~/Library/Application Support/","/usr/local/etc/","/usr/etc/","/etc/"};
#endif //CNO_OS

typedef struct CNO_LowLevelConfig_struct {
	struct audio_struct{
		cno_u8_type enabled;
		cno_s8_type channels;
		cno_s16_type samplerate;
	} audio;
	struct debug_struct{
		cno_u8_type enabled;
		cno_s8_type verbosity;
		cno_u8_type stdout;
		cno_u8_type file;
		cno_u8_type filename[64];
	} debug;
	cno_u8_type dialogs;
	cno_u8_type environment;
	struct joysticks_struct{
		cno_u8_type enabled;
	} joysticks;
	cno_u8_type net;
	cno_u8_type sdl2;
	struct threads_struct{
		cno_u8_type enabled;
		cno_u8_type maxthreads;
	} threads;
	struct video_struct{
		cno_u8_type enabled;
		cno_u8_type screensaver;
	} video;
	struct directories_struct{
		cno_u8_type unixstyle;
		cno_u8_type enginedata[128];
		cno_u8_type userdata[128];
	} directories;
} CNO_LowLevelConfig_type;

CNO_LowLevelConfig_type CNO_LowLevelConfig;

cno_u8_type CNO_LowLevelConfig_Init();
cno_u8_type CNO_LowLevelConfig_LoadDefaults();
cno_u8_type CNO_LowLevelConfig_Load(cno_cstring_type filename);
cno_u8_type CNO_LowLevelConfig_Save(cno_cstring_type filename);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_CONFIG_H
