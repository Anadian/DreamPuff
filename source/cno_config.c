//cno_config.c

#include "cno_config.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //printf
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STRING
#include <string.h> //strcmp, strcat
#endif //CNO_HAVE_STRING
#if CNO_HAVE_STDLIB
#include <stdlib.h> //atoi
#endif //CNO_HAVE_STDLIB
#if CNO_HAVE_INIH
#include "ini.h" //ini_parse
#endif //CNO_HAVE_INIH

static int handler(void* user, const char* section, const char* name, const char* value){
    CNO_LowLevelConfig_type *pconfig = (CNO_LowLevelConfig_type*)user;
	if(strcmp(name,"audio") == 0) pconfig->audio = atoi(value);
	else if(strcmp(name,"threads") == 0) pconfig->threads = atoi(value);
	else if(strcmp(name,"video") == 0) pconfig->video = atoi(value);
	else if(strcmp(name,"debug") == 0) pconfig->debug = atoi(value);
	else{
#if CNO_ALLOW_PRINTF
		printf("Ini parse error: unrecognised key/value pair: section %s, name %s, value %s\n", section, name, value);
#endif //CNO_ALLOW_PRINTF
		return 0;
	}
	return 1;
}

cno_u8_type CNO_LowLevelConfig_Init(){
#if CNO_HAVE_INIH
	cno_u8_type i;
	cno_s16_type result;
	for(i = 0; i < CNO_CONFIG_DIRECTORIES; i++){
		cno_u8_type filename[256];
		strcat(filename,CNO_LowLevelConfig_Directories[i]);
		strcat(filename,CNO_BUILD_NAME);
		strcat(filename,"config.ini");
#if CNO_ALLOW_PRINTF
		printf("Attempting to read %s\n", filename);
#endif //CNO_ALLOW_PRINTF
		result = ini_parse(filename, handler, &CNO_LowLevelConfig);
#if CNO_ALLOW_PRINTF
		printf("Result: %d\n", result);
#endif //CNO_ALLOW_PRINTF
		if(result == 0) return 1;
	}
#endif //CNO_HAVE_INIH
	return 0;
}
