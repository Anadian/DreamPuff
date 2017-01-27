//cno_config.h

#ifndef CNO_CONFIG_H
#define CNO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#define CNO_CONFIG_DIRECTORIES 6

#if CNO_OS == 1
static char *CNO_LowLevelConfig_Directories_a1[CNO_CONFIG_DIRECTORIES] = {"./config/","~/Library/Application Support/","~/.config/","/usr/local/etc/","/usr/etc/","/etc/"};
#elif CNO_OS == 2
static char *CNO_LowLevelConfig_Directories_a1[CNO_CONFIG_DIRECTORIES] = {"~/Library/Application Support/","~/.config/","./config/","/usr/local/etc/","/usr/etc/","/etc/"};
#else
static char *CNO_LowLevelConfig_Directories_a1[CNO_CONFIG_DIRECTORIES] = {"~/.config/","./config/","~/Library/Application Support/","/usr/local/etc/","/usr/etc/","/etc/"};
#endif //CNO_OS

typedef struct CNO_LowLevelConfig_struct {
	cno_u8_type debug;
	cno_u8_type sdl2;
	cno_u8_type threads;
	cno_u8_type video;
	cno_u8_type audio;
	cno_cstring_type enginedata;
	cno_cstring_type userdata;
	cno_u8_type net;
} CNO_LowLevelConfig_type;

CNO_LowLevelConfig_type CNO_LowLevelConfig;

cno_u8_type CNO_LowLevelConfig_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_CONFIG_H
