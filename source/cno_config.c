//cno_config.c

#include "cno_config.h"

#include "cno_options.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //printf
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STRING
#include <string.h> //strcmp, strcat, strcpy
#endif //CNO_HAVE_STRING
#if CNO_HAVE_STDLIB
#include <stdlib.h> //atoi
#endif //CNO_HAVE_STDLIB
#if CNO_HAVE_INIH
#include "ini.h" //ini_parse
#endif //CNO_HAVE_INIH
#if CNO_HAVE_ERRNO
#include <errno.h>
#endif //CNO_HAVE_ERRNO

static int handler(void* user, const char* section, const char* name, const char* value){
    CNO_LowLevelConfig_type *pconfig = (CNO_LowLevelConfig_type*)user;
	if(CNO_strcmp(name,"audio") == 0) pconfig->audio = CNO_atoi(value);
	else if(CNO_strcmp(name,"threads") == 0) pconfig->threads = CNO_atoi(value);
	else if(CNO_strcmp(name,"video") == 0) pconfig->video = CNO_atoi(value);
	else if(CNO_strcmp(name,"debug") == 0) pconfig->debug = CNO_atoi(value);
	else if(CNO_strcmp(name,"enginedata") == 0) pconfig->enginedata = value;
	else if(CNO_strcmp(name,"userdata") == 0) pconfig->userdata = value;
	else{
#if CNO_ALLOW_PRINTF
		CNO_printf("Ini parse error: unrecognised key/value pair: section %s, name %s, value %s\n", section, name, value);
#endif //CNO_ALLOW_PRINTF
		return 0;
	}
	return 1;
}

cno_u8_type CNO_LowLevelConfig_NewDefault(cno_cstring_type filename){
#if CNO_HAVE_STDIO
	cno_file_type configfile;
	configfile = CNO_fopen(filename, "w");
	if(configfile != NULL){
		CNO_fputs("audio=1",configfile);
		CNO_fputs("debug=1",configfile);
		CNO_fputs("enginedata=",configfile);
		CNO_fputs("userdata=",configfile);
		CNO_fputs("video=1",configfile);
		CNO_fclose(configfile);
		return 1;
	} else{
		CNO_printf("Couldn't open %s (errno: %d)\n", filename, errno);
#if CNO_ALLOW_EXIT
		CNO_printf("Aborting...");
		CNO_exit(EXIT_FAILURE);
#endif //CNO_ALLOW_EXIT
	}
#endif CNO_HAVE_STDIO
	return 0;
}
	

cno_u8_type CNO_LowLevelConfig_Init(){
#if CNO_HAVE_INIH
	cno_s16_type result;
	result = -1;
	if(!(CNO_strcmp(CNO_Options_Argument_Config,"\0") == 0)){
		CNO_printf("Attempting to read %s\n", CNO_Options_Argument_Config);
		result = ini_parse(CNO_Options_Argument_Config, handler, &CNO_LowLevelConfig);
		CNO_printf("Result: %d", result);
		if(result == 0) return 1;
	}
	cno_u8_type i;
	for(i = 0; i < CNO_CONFIG_DIRECTORIES; i++){
		cno_u8_type filename[256];
		CNO_strcpy(filename,"\0");
		CNO_strcat(filename,CNO_LowLevelConfig_Directories_a1[i]);
		CNO_strcat(filename,CNO_BUILD_NAME);
		CNO_strcat(filename,"/");
		CNO_strcat(filename,"config.ini");
#if CNO_ALLOW_PRINTF
		CNO_printf("Attempting to read %s\n", filename);
#endif //CNO_ALLOW_PRINTF
		result = ini_parse(filename, handler, &CNO_LowLevelConfig);
#if CNO_ALLOW_PRINTF
		CNO_printf("Result: %d\n", result);
#endif //CNO_ALLOW_PRINTF
		if(result == 0) return 1;
	}
	CNO_printf("No existing config.ini file found.\n");
	CNO_printf("Using defaults.\n");
	CNO_LowLevelConfig.audio = 1;
	CNO_LowLevelConfig.threads = 4;
	CNO_LowLevelConfig.video = 1;
	CNO_LowLevelConfig.debug = 5;
	/*cno_u8_type filename[256];
	CNO_strcpy(filename, "\0");
	CNO_strcat(filename,CNO_LowLevelConfig_Directories_a1[0]);
	CNO_strcat(filename,CNO_BUILD_NAME);
	CNO_strcat(filename,"/");
	CNO_strcat(filename,"config.ini");
	CNO_printf("Attempting to create a new one at: %s\n", filename);
	return CNO_LowLevelConfig_NewDefault(filename);*/
#endif //CNO_HAVE_INIH
	return 0;
}
