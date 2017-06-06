//cno_config.h

#ifndef CNO_CONFIG_H
#define CNO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_OS == CNO_OS_WINDOWS
#define CNO_CONFIG_DIRECTORIES 0
//static char *CNO_LowLevelConfig_Directories_a1[CNO_CONFIG_DIRECTORIES] = {"./config/","~/Library/Application Support/","~/.config/","/usr/local/etc/","/usr/etc/","/etc/"};
#elif CNO_OS == CNO_OS_APPLE
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
		cno_cstring_type filename;
	} debug;
	cno_u8_type dialogs;
	cno_u8_type environment;
	struct input_struct{
		cno_cstring_type keyboard_mode; //scancode, keycode, text
		cno_cstring_type text_mode; //software, hardware
		cno_u8_type mouse_relative_motion;
		cno_u8_type mouse_buttons;
		cno_u8_type mouse_wheel;
		cno_cstring_type controller_engine; //none, sdl-joystick, sdl-controller, xinput, libusb, libgamepad
		cno_u8_type joystick_buttons;
		cno_u8_type joystick_axis;
		cno_u8_type joystick_hat;
		cno_u8_type joystick_ball;
		cno_u32_type joystick_axis_deadzone;
		cno_u32_type joystick_axis_peak;
		cno_cstring_type touch_mode; //mouse, touch
	} input;
	cno_u8_type net;
	struct sdl2_struct{
		cno_u8_type sdl2_enabled;
		cno_u8_type sdl2_ttf_enabled;
		cno_u8_type sdl2_gfx_enabled;
	} sdl2;
	struct sdl2image_struct{
		cno_u8_type enabled;
		cno_u8_type jpg;
		cno_u8_type png;
		cno_u8_type tif;
	} sdl2_image;
	struct sdl2mixer_struct{
		cno_u8_type enabled;
		cno_u8_type flac;
		cno_u8_type mod;
		cno_u8_type mp3;
		cno_u8_type ogg;
	} sdl2_mixer;
	struct threads_struct{
		cno_u8_type enabled;
		cno_u8_type maxthreads;
		cno_u8_type logic;
		cno_u8_type fileio;
		cno_u8_type network;
	} threads;
	struct video_struct{
		cno_u8_type enabled;
		cno_u8_type save_screenshot_bmp;
		cno_u8_type save_screenshot_png;
		cno_s8_type driver;
		cno_s8_type display;
		cno_s8_type displaymode;
		cno_s32_type x_offset;
		cno_s32_type y_offset;
		cno_u32_type width;
		cno_u32_type height;
		cno_u8_type bits_per_pixel;
		cno_u8_type exclusive_fullscreen;
		cno_u16_type framerate;
		cno_u8_type resizable;
		cno_u8_type borderless;
		cno_u8_type disable_screensaver;
		cno_u8_type software_bitmaps;
		cno_u8_type software_effects;
		cno_u8_type software_render;
	} video;
	struct directories_struct{
		cno_u8_type portable;
		cno_u8_type engine_data[CNO_Filename_Size];
		cno_u8_type user_data[CNO_Filename_Size];
	} directories;
} CNO_LowLevelConfig_type;

typedef struct CNO_ConfigVariable_struct {
	cno_cstring_type section;
	cno_cstring_type name;
	cno_u8_type option_value;
	cno_u8_type option_only;
	CNO_Option_Arguments_type arguments; //if CNO_Option_Arguments_None: don't show in config files
	cno_cstring_type hint;
	cno_cstring_type default_value;
	cno_cstring_type description;
	cno_cstring_type accepts;
	cno_u8_type hits;
	cno_cstring_type argument;
	void *pointer;
}; //system defaults => user config => options => -C if specified

CNO_LowLevelConfig_type CNO_LowLevelConfig;

cno_u8_type CNO_LowLevelConfig_Init();
//cno_u8_type CNO_LowLevelConfig_LoadDefaults();
cno_u8_type CNO_LowLevelConfig_Load(cno_cstring_type filename);
cno_u8_type CNO_LowLevelConfig_Save(cno_cstring_type filename);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_CONFIG_H
