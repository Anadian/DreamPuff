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
		cno_u8_type standardoutput;
		cno_u8_type standarderror;
		cno_u8_type file;
		cno_u8_type filename[CNO_Filename_Size];
		cno_u16_type logmessagebuffersize;
		cno_u16_type logmessageargumentbuffersize;
	} debug;
	cno_u8_type dialogs;
	cno_u8_type environment;
	struct joysticks_struct{
		cno_u8_type enabled;
	} joysticks;
	cno_u8_type net;
	struct sdl2_struct{
		cno_u8_type sdl2enabled;
		cno_u8_type sdl2ttfenabled;
	} sdl2;
	struct sdl2image_struct{
		cno_u8_type enabled;
		cno_u8_type jpg;
		cno_u8_type png;
		cno_u8_type tif;
	} sdl2image;
	struct sdl2mixer_struct{
		cno_u8_type enabled;
		cno_u8_type flac;
		cno_u8_type mod;
		cno_u8_type mp3;
		cno_u8_type ogg;
	} sdl2mixer;
	struct threads_struct{
		cno_u8_type enabled;
		cno_u8_type maxthreads;
		cno_u8_type pthread;
		cno_u8_type sdl2;
		cno_u8_type logic;
		cno_u8_type fileio;
		cno_u8_type network;
	} threads;
	struct video_struct{
		cno_u8_type enabled;
		cno_u8_type screensaver;
		cno_u8_type savescreenshotbmp;
		cno_u8_type savescreenshotpng;
		cno_u8_type maxwindows;
		cno_s8_type driver;
		cno_s8_type display;
		cno_s8_type displaymode;
		cno_s32_type xoffset;
		cno_s32_type yoffset;
		cno_u32_type width;
		cno_u32_type height;
		cno_u8_type bitsperpixel;
		cno_u8_type exclusivefullscreen;
		cno_u16_type framerate;
		cno_u8_type resizable;
		cno_u8_type borderless;
	} video;
	struct directories_struct{
		cno_u8_type portable;
		cno_u8_type enginedata[CNO_Filename_Size];
		cno_u8_type userdata[CNO_Filename_Size];
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
