//cno_config.c

#include "cno_config.h"

#include "cno_options.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //printf, f*
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STDLIB
#include <stdlib.h> //atoi
#endif //CNO_HAVE_STDLIB
#if CNO_HAVE_STRING
#include <string.h> //strcmp, strcat, strcpy
#endif //CNO_HAVE_STRING
#if CNO_HAVE_ERRNO
#include <errno.h>
#endif //CNO_HAVE_ERRNO

#if CNO_HAVE_INIH && (CNO_CONFIG == CNO_CONFIG_INIH)
#define INI_ALLOW_MULTILINE 0
#define INI_MAX_LINE CNO_BUFFER_MAXSIZE
#include "ini.h" //ini_parse

static int handler(void* user, const char* section, const char* name, const char* value){
#if CNO_HAVE_STDLIB && CNO_HAVE_STRING
    CNO_LowLevelConfig_type *pconfig = (CNO_LowLevelConfig_type*)user;
	if(CNO_strcmp(section,"audio") == 0){ //llcnm
		if(CNO_strcmp(name,"enabled") == 0) pconfig->audio.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"channels") == 0) pconfig->audio.channels = CNO_atoi(value);
		else if(CNO_strcmp(name,"samplerate") == 0) pconfig->audio.samplerate = CNO_atoi(value);
	} else if(CNO_strcmp(section,"debug") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->debug.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"verbosity") == 0) pconfig->debug.verbosity = CNO_atoi(value);
		else if(CNO_strcmp(name,"standardoutput") == 0) pconfig->debug.standardoutput = CNO_atoi(value);
		else if(CNO_strcmp(name,"standarderror") == 0) pconfig->debug.standarderror = CNO_atoi(value);
		else if(CNO_strcmp(name,"file") == 0) pconfig->debug.file = CNO_atoi(value);
		else if(CNO_strcmp(name,"filename") == 0) CNO_strcpy((pconfig->debug.filename),value);
	} else if(CNO_strcmp(section,"input") == 0){
		if(CNO_strcmp(name,"keyboard_mode") == 0) pconfig->input.keyboard_mode = CNO_atoi(value);
		if(CNO_strcmp(name,"test_mode") == 0) pconfig->input.test_mode = CNO_atoi(value);
		if(CNO_strcmp(name,"mouse_relative_motion") == 0) pconfig->input.mouse_relative_motion = CNO_atoi(value);
		if(CNO_strcmp(name,"mouse_buttons") == 0) pconfig->input.mouse_buttons = CNO_atoi(value);
		if(CNO_strcmp(name,"mouse_wheel") == 0) pconfig->input.mouse_wheel = CNO_atoi(value);
		if(CNO_strcmp(name,"controller_engine") == 0) pconfig->input.controller_engine = CNO_atoi(value);
		if(CNO_strcmp(name,"joystick_buttons") == 0) pconfig->input.joystick_buttons = CNO_atoi(value);
		if(CNO_strcmp(name,"joystick_axis") == 0) pconfig->input.joystick_axis = CNO_atoi(value);
		if(CNO_strcmp(name,"joystick_hat") == 0) pconfig->input.joystick_hat = CNO_atoi(value);
		if(CNO_strcmp(name,"joystick_ball") == 0) pconfig->input.joystick_ball = CNO_atoi(value);
		if(CNO_strcmp(name,"joystick_axis_deadzone") == 0) pconfig->input.joystick_axis_deadzone = CNO_atoi(value);
		if(CNO_strcmp(name,"joystick_axis_peak") == 0) pconfig->input.joystick_axis_peak = CNO_atoi(value);
		if(CNO_strcmp(name,"touch_mode") == 0) pconfig->input.touch_mode = CNO_atoi(value);
	} else if(CNO_strcmp(section,"sdl2") == 0){
		if(CNO_strcmp(name,"sdl2enabled") == 0) pconfig->sdl2.sdl2enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"sdl2ttfenabled") == 0) pconfig->sdl2.sdl2ttfenabled = CNO_atoi(value);
	} else if(CNO_strcmp(section,"sdl2_image") == 0){
		if(CNO_strcmp(name,"jpg") == 0) pconfig->sdl2_image.jpg = CNO_atoi(value);
		else if(CNO_strcmp(name,"png") == 0) pconfig->sdl2_image.png = CNO_atoi(value);
		else if(CNO_strcmp(name,"tif") == 0) pconfig->sdl2_image.tif = CNO_atoi(value);
	} else if(CNO_strcmp(section,"sdl2_mixer") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->sdl2_mixer.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"flac") == 0) pconfig->sdl2_mixer.flac = CNO_atoi(value);
		else if(CNO_strcmp(name,"mod") == 0) pconfig->sdl2_mixer.mod = CNO_atoi(value);
		else if(CNO_strcmp(name,"mp3") == 0) pconfig->sdl2_mixer.mp3 = CNO_atoi(value);
		else if(CNO_strcmp(name,"ogg") == 0) pconfig->sdl2_mixer.ogg = CNO_atoi(value);
	} else if(CNO_strcmp(section,"threads") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->threads.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"sdl2") == 0) pconfig->threads.sdl2 = CNO_atoi(value);
		else if(CNO_strcmp(name,"logic") == 0) pconfig->threads.logic = CNO_atoi(value);
		else if(CNO_strcmp(name,"fileio") == 0) pconfig->threads.fileio = CNO_atoi(value);
		else if(CNO_strcmp(name,"network") == 0) pconfig->threads.network = CNO_atoi(value);
	} else if(CNO_strcmp(section,"video") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->video.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"savescreenshotbmp") == 0) pconfig->video.savescreenshotbmp = CNO_atoi(value);
		else if(CNO_strcmp(name,"savescreenshotpng") == 0) pconfig->video.savescreenshotpng = CNO_atoi(value);
		else if(CNO_strcmp(name,"driver") == 0) pconfig->video.driver = CNO_atoi(value);
		else if(CNO_strcmp(name,"display") == 0) pconfig->video.display = CNO_atoi(value);
		else if(CNO_strcmp(name,"displaymode") == 0) pconfig->video.displaymode = CNO_atoi(value);
		else if(CNO_strcmp(name,"xoffset") == 0) pconfig->video.xoffset = CNO_atoi(value);
		else if(CNO_strcmp(name,"yoffset") == 0) pconfig->video.yoffset = CNO_atoi(value);
		else if(CNO_strcmp(name,"width") == 0) pconfig->video.width = CNO_atoi(value);
		else if(CNO_strcmp(name,"height") == 0) pconfig->video.height = CNO_atoi(value);
		else if(CNO_strcmp(name,"bitsperpixel") == 0) pconfig->video.bitsperpixel = CNO_atoi(value);
		else if(CNO_strcmp(name,"exclusivefullscreen") == 0) pconfig->video.exclusivefullscreen = CNO_atoi(value);
		else if(CNO_strcmp(name,"framerate") == 0) pconfig->video.framerate = CNO_atoi(value);
		else if(CNO_strcmp(name,"resizable") == 0) pconfig->video.resizable = CNO_atoi(value);
		else if(CNO_strcmp(name,"borderless") == 0) pconfig->video.borderless = CNO_atoi(value);
	} else if(CNO_strcmp(section,"directories") == 0){
		if(CNO_strcmp(name,"portable") == 0) pconfig->directories.portable = CNO_atoi(value);
		else if(CNO_strcmp(name,"enginedata") == 0) CNO_strcpy((pconfig->directories.enginedata),value);
		else if(CNO_strcmp(name,"userdata") == 0) CNO_strcpy((pconfig->directories.userdata),value);
	} 
	else{
		if(CNO_strcmp(name,"dialogs") == 0) pconfig->dialogs = CNO_atoi(value);
		else if(CNO_strcmp(name,"environment") == 0) pconfig->environment = CNO_atoi(value);
		else if(CNO_strcmp(name,"net") == 0) pconfig->net = CNO_atoi(value);
		else{
#if CNO_ALLOW_PRINTF
			CNO_printf("Ini parse error: unrecognised key/value pair: section %s, name %s, value %s\n", section, name, value);
#endif //CNO_ALLOW_PRINTF
			return 0;
		}
	}
	return 1;
#endif //CNO_HAVE_STDLIB && CNO_HAVE_STRING
	return 0;
}	

cno_u8_type CNO_LowLevelConfig_Init(){
#if CNO_HAVE_INIH
	cno_s16_type result;
	result = -1;
	if(!(CNO_strcmp(CNO_Options_Argument_Config,"\0") == 0)){
		return CNO_LowLevelConfig_Load(CNO_Options_Argument_Config);
	}
#if CNO_OS == 1
	cno_u8_type filename[32];
	CNO_strcpy(filename,"config.ini");
	if(CNO_LowLevelConfig_Load(filename)) return 1;
#else
	cno_u8_type i;
	for(i = 0; i < CNO_CONFIG_DIRECTORIES; i++){
		cno_u8_type filename[256];
		CNO_strcpy(filename,"\0");
		CNO_strcat(filename,CNO_LowLevelConfig_Directories_a1[i]);
		CNO_strcat(filename,CNO_BUILD_NAME);
		CNO_strcat(filename,"/");
		CNO_strcat(filename,"config.ini");
		if(CNO_LowLevelConfig_Load(filename)) return 1;
	}
#endif //CNO_OS == 1
	CNO_printf("No existing config.ini file found.\n");
	CNO_printf("Using defaults.\n");
	return CNO_LowLevelConfig_LoadDefaults();
#endif //CNO_HAVE_INIH
	return 0;
}

cno_u8_type CNO_LowLevelConfig_LoadDefaults(){
#if CNO_HAVE_STRING
	CNO_LowLevelConfig.audio.enabled = 1;
	CNO_LowLevelConfig.audio.channels = 2;
	CNO_LowLevelConfig.audio.samplerate = 48000;
	CNO_LowLevelConfig.debug.enabled = 1;
	CNO_LowLevelConfig.debug.verbosity = 5;
	CNO_LowLevelConfig.debug.standardoutput = 1;
	CNO_LowLevelConfig.debug.standarderror = 1;
	CNO_LowLevelConfig.debug.file = 1;
	CNO_strcpy(&(CNO_LowLevelConfig.debug.filename),"CAX.log");
	CNO_LowLevelConfig.debug.logmessagebuffersize = 4096;
	CNO_LowLevelConfig.debug.logmessageargumentbuffersize = 1024;
	CNO_LowLevelConfig.dialogs = 1;
	CNO_LowLevelConfig.environment = 1;
	CNO_LowLevelConfig.joysticks.enabled = 1;
	CNO_LowLevelConfig.net = 1;
	CNO_LowLevelConfig.sdl2.sdl2enabled = 1;
	CNO_LowLevelConfig.sdl2.sdl2ttfenabled = 1;
	CNO_LowLevelConfig.sdl2_image.enabled = 1;
	CNO_LowLevelConfig.sdl2_image.jpg = 0;
	CNO_LowLevelConfig.sdl2_image.png = 1;
	CNO_LowLevelConfig.sdl2_image.tif = 0;
	CNO_LowLevelConfig.sdl2_mixer.enabled = 1;
	CNO_LowLevelConfig.sdl2_mixer.flac = 0;
	CNO_LowLevelConfig.sdl2_mixer.mod = 0;
	CNO_LowLevelConfig.sdl2_mixer.mp3 = 1;
	CNO_LowLevelConfig.sdl2_mixer.ogg = 0;
	CNO_LowLevelConfig.threads.enabled = 1;
	CNO_LowLevelConfig.threads.maxthreads = 5;
	CNO_LowLevelConfig.threads.sdl2 = 1;
	CNO_LowLevelConfig.threads.logic = 1;
	CNO_LowLevelConfig.threads.fileio = 0;
	CNO_LowLevelConfig.threads.network = 0;
	CNO_LowLevelConfig.video.enabled = 1;
	CNO_LowLevelConfig.video.screensaver = 1;
	CNO_LowLevelConfig.video.savescreenshotpng = 1;
	CNO_LowLevelConfig.video.savescreenshotbmp = 0;
	CNO_LowLevelConfig.video.maxwindows = 8;
	CNO_LowLevelConfig.video.driver = -1;
	CNO_LowLevelConfig.video.display = -1;
	CNO_LowLevelConfig.video.displaymode = -1;
	CNO_LowLevelConfig.video.xoffset = 0;
	CNO_LowLevelConfig.video.yoffset = 0;
	CNO_LowLevelConfig.video.width = 640;
	CNO_LowLevelConfig.video.height = 480;
	CNO_LowLevelConfig.video.bitsperpixel = 32;
	CNO_LowLevelConfig.video.exclusivefullscreen = 0;
	CNO_LowLevelConfig.video.framerate = 60;
	CNO_LowLevelConfig.video.resizable = 0;
	CNO_LowLevelConfig.video.borderless = 0;
	CNO_strcpy(&(CNO_LowLevelConfig.directories.enginedata),"enginedata");
	CNO_strcat(&(CNO_LowLevelConfig.directories.enginedata), CNO_DS);
#if CNO_OS == 1
	CNO_LowLevelConfig.directories.portable = 1;
	CNO_strcpy(&(CNO_LowLevelConfig.directories.userdata),"savedata\\");
#else
	CNO_LowLevelConfig.directories.portable = 0;
	CNO_strcpy(&(CNO_LowLevelConfig.directories.userdata),"~/DreamPuff/");
#endif //CNO_OS
	return 1;
#endif //CNO_HAVE_STRING
	return 0;
}

cno_u8_type CNO_LowLevelConfig_Load(cno_cstring_type filename){
#if CNO_HAVE_INIH
	cno_s8_type result;
	CNO_printf("Attempting to read %s\n", filename);
	result = ini_parse(filename, handler, &CNO_LowLevelConfig);
	CNO_printf("Result: %d\n", result);
	if(result == 0) return 1;
#endif //CNO_HAVE_INIH
	return 0;
}
cno_u8_type CNO_LowLevelConfig_Save(cno_cstring_type filename){
#if CNO_HAVE_STDIO
	cno_file_type configfile;
	configfile = CNO_fopen(filename, "w");
	if(configfile != NULL){
		cno_u8_type buffer[256];
		CNO_sprintf(buffer, ";%s DreamPuff config file\n", filename); //llcvm
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "dialogs=%d\n", CNO_LowLevelConfig.dialogs);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "environment=%d\n", CNO_LowLevelConfig.environment);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "net=%d\n", CNO_LowLevelConfig.net);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[audio]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.audio.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "channels=%d\n", CNO_LowLevelConfig.audio.channels);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "samplerate=%d\n", CNO_LowLevelConfig.audio.samplerate);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[debug]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.debug.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "verbosity=%d\n", CNO_LowLevelConfig.debug.verbosity);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "standardoutput=%d\n", CNO_LowLevelConfig.debug.standardoutput);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "stanarderror=%d\n", CNO_LowLevelConfig.debug.stanarderror);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "file=%d\n", CNO_LowLevelConfig.debug.file);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "filename=%s\n", CNO_LowLevelConfig.debug.filename);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "logmessagebuffersize=%d\n", CNO_LowLevelConfig.debug.logmessagebuffersize);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "logmessageargumentbuffersize=%d\n", CNO_LowLevelConfig.debug.logmessageargumentbuffersize);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[joysticks]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.joysticks.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[sdl2]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "sdl2enabled=%d\n", CNO_LowLevelConfig.sdl2.sdl2enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "sdl2ttfenabled=%d\n", CNO_LowLevelConfig.sdl2.sdl2ttfenabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[sdl2_image]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.sdl2_image.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "jpg=%d\n", CNO_LowLevelConfig.sdl2_image.jpg);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "png=%d\n", CNO_LowLevelConfig.sdl2_image.png);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "tif=%d\n", CNO_LowLevelConfig.sdl2_image.tif);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[sdl2_mixer]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.sdl2_mixer.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "flac=%d\n", CNO_LowLevelConfig.sdl2_mixer.flac);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "mod=%d\n", CNO_LowLevelConfig.sdl2_mixer.mod);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "mp3=%d\n", CNO_LowLevelConfig.sdl2_mixer.mp3);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "ogg=%d\n", CNO_LowLevelConfig.sdl2_mixer.ogg);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[threads]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.threads.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "maxthreads=%d\n", CNO_LowLevelConfig.threads.maxthreads);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "sdl2=%d\n", CNO_LowLevelConfig.threads.sdl2);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "logic=%d\n", CNO_LowLevelConfig.threads.logic);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "fileio=%d\n", CNO_LowLevelConfig.threads.fileio);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "network=%d\n", CNO_LowLevelConfig.threads.network);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[video]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.video.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "screensaver=%d\n", CNO_LowLevelConfig.video.screensaver);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "savescreenshotbmp=%d\n", CNO_LowLevelConfig.video.savescreenshotbmp);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "savescreenshotpng=%d\n", CNO_LowLevelConfig.video.savescreenshotpng);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "maxwindows=%d\n", CNO_LowLevelConfig.video.maxwindows);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "driver=%d\n", CNO_LowLevelConfig.video.driver);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "display=%d\n", CNO_LowLevelConfig.video.display);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "displaymode=%d\n", CNO_LowLevelConfig.video.displaymode);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "xoffset=%d\n", CNO_LowLevelConfig.video.xoffset);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "yoffset=%d\n", CNO_LowLevelConfig.video.yoffset);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "width=%d\n", CNO_LowLevelConfig.video.width);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "height=%d\n", CNO_LowLevelConfig.video.height);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "bitsperpixel=%d\n", CNO_LowLevelConfig.video.bitsperpixel);
		CNO_fputs(buffer, configfile);;
		CNO_sprintf(buffer, "exclusivefullscreen=%d\n", CNO_LowLevelConfig.video.exclusivefullscreen);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "framerate=%d\n", CNO_LowLevelConfig.video.framerate);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "resizable=%d\n", CNO_LowLevelConfig.video.resizable);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "borderless=%d\n", CNO_LowLevelConfig.video.borderless);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[directories]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "portable=%d\n", CNO_LowLevelConfig.directories.portable);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enginedata=%s\n", CNO_LowLevelConfig.directories.enginedata);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "userdata=%s\n", CNO_LowLevelConfig.directories.userdata);
		CNO_fputs(buffer, configfile);
		CNO_fclose(configfile);
		return 1;
	} else{
		CNO_printf("Error writing %s", filename);
#if CNO_HAVE_ERRNO
		CNO_printf(" (errno %d)", errno);
#endif //CNO_HAVE_ERRNO
		CNO_printf("\n");
	}
#endif //CNO_HAVE_STDIO
	return 0;
}
