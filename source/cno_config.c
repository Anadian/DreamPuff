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
#if CNO_HAVE_INIH
#include "ini.h" //ini_parse
#endif //CNO_HAVE_INIH
#if CNO_HAVE_ERRNO
#include <errno.h>
#endif //CNO_HAVE_ERRNO

static int handler(void* user, const char* section, const char* name, const char* value){
#if CNO_HAVE_STDLIB && CNO_HAVE_STRING
    CNO_LowLevelConfig_type *pconfig = (CNO_LowLevelConfig_type*)user;
	if(CNO_strcmp(section,"audio") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->audio.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"channels") == 0) pconfig->audio.channels = CNO_atoi(value);
		else if(CNO_strcmp(name,"samplerate") == 0) pconfig->audio.samplerate = CNO_atoi(value);
	} else if(CNO_strcmp(section,"debug") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->debug.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"verbosity") == 0) pconfig->debug.verbosity = CNO_atoi(value);
		else if(CNO_strcmp(name,"standardoutput") == 0) pconfig->debug.standardoutput = CNO_atoi(value);
		else if(CNO_strcmp(name,"file") == 0) pconfig->debug.file = CNO_atoi(value);
		else if(CNO_strcmp(name,"filename") == 0) CNO_strcpy((pconfig->debug.filename),value);
	} else if(CNO_strcmp(section,"joysticks") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->joysticks.enabled = CNO_atoi(value);
	} else if(CNO_strcmp(section,"threads") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->threads.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"maxthreads") == 0) pconfig->threads.maxthreads = CNO_atoi(value);
	} else if(CNO_strcmp(section,"video") == 0){
		if(CNO_strcmp(name,"enabled") == 0) pconfig->video.enabled = CNO_atoi(value);
		else if(CNO_strcmp(name,"screensaver") == 0) pconfig->video.screensaver = CNO_atoi(value);
	} else if(CNO_strcmp(section,"directories") == 0){
		if(CNO_strcmp(name,"unixstyle") == 0) pconfig->directories.unixstyle = CNO_atoi(value);
		else if(CNO_strcmp(name,"enginedata") == 0) CNO_strcpy((pconfig->directories.enginedata),value);
		else if(CNO_strcmp(name,"userdata") == 0) CNO_strcpy((pconfig->directories.userdata),value);
	} 
	else{
		if(CNO_strcmp(name,"dialogs") == 0) pconfig->dialogs = CNO_atoi(value);
		else if(CNO_strcmp(name,"environment") == 0) pconfig->environment = CNO_atoi(value);
		else if(CNO_strcmp(name,"net") == 0) pconfig->net = CNO_atoi(value);
		else if(CNO_strcmp(name,"sdl2") == 0) pconfig->sdl2 = CNO_atoi(value);
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
	CNO_LowLevelConfig.debug.file = 1;
	CNO_strcpy(&(CNO_LowLevelConfig.debug.filename),"CAX.log");
	CNO_LowLevelConfig.dialogs = 1;
	CNO_LowLevelConfig.environment = 1;
	CNO_LowLevelConfig.joysticks.enabled = 1;
	CNO_LowLevelConfig.net = 1;
	CNO_LowLevelConfig.sdl2 = 1;
	CNO_LowLevelConfig.threads.enabled = 1;
	CNO_LowLevelConfig.threads.maxthreads = 5;
	CNO_LowLevelConfig.video.enabled = 1;
	CNO_LowLevelConfig.video.screensaver = 1;
	CNO_strcpy(&(CNO_LowLevelConfig.directories.enginedata),"enginedata");
	CNO_strcat(&(CNO_LowLevelConfig.directories.enginedata), CNO_DS);
#if CNO_OS == 1
	CNO_LowLevelConfig.directories.unixstyle = 0;
	CNO_strcpy(&(CNO_LowLevelConfig.directories.userdata),"savedata\\");
#else
	CNO_LowLevelConfig.directories.unixstyle = 1;
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
		CNO_sprintf(buffer, ";%s DreamPuff config file\n", filename);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "dialogs=%d\n", CNO_LowLevelConfig.dialogs);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "environment=%d\n", CNO_LowLevelConfig.environment);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "net=%d\n", CNO_LowLevelConfig.net);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "sdl2=%d\n", CNO_LowLevelConfig.sdl2);
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
		CNO_sprintf(buffer, "file=%d\n", CNO_LowLevelConfig.debug.file);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "filename=%s\n", CNO_LowLevelConfig.debug.filename);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[joysticks]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.joysticks.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[threads]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.threads.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "maxthreads=%d\n", CNO_LowLevelConfig.threads.maxthreads);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[video]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "enabled=%d\n", CNO_LowLevelConfig.video.enabled);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "screensaver=%d\n", CNO_LowLevelConfig.video.screensaver);
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "[directories]\n");
		CNO_fputs(buffer, configfile);
		CNO_sprintf(buffer, "unixstyle=%d\n", CNO_LowLevelConfig.directories.unixstyle);
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
