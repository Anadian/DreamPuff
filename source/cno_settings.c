//cno_settings.c
#include <cno_settings.h>

#if CNO_HAVE_STDIO
#include <stdio.h> //fprintf
#include <stddef.h> //size_t
#endif //CNO_HAVE_STDIO

#if CNO_HAVE_STRING
#include <string.h>
#endif //CNO_HAVE_STRING

#if CNO_HAVE_GOPT && CNO_ALLOW_OPTIONS
#include "gopt.h"
#endif //CNO_HAVE_GOPT && CNO_ALLOW_OPTIONS

cno_u8_type CNO_Settings_Init(){
	cno_u8_type _return;
	cno_size_type number_of_settings;
	number_of_settings = (sizeof(CNO_Settings)/sizeof(CNO_Setting_type));
	cno_size_type i; ///Settings index
	for(i=0; i<number_of_settings; i++){
		cno_u8_type section[32];
		cno_u8_type config_name[32];
		cno_u8_type option_name[32];
		cno_u8_type option_key;
		CNO_Value_Type_type value_type;
		cno_u8_type hint[32];
		cno_u8_type description[CNO_BUFFER_MAXSIZE];
		cno_u8_type valid_values[32];
		cno_u8_type argument[CNO_BUFFER_MAXSIZE];
		cno_size_type length_of_setting_name;
		length_of_setting_name = sizeof(CNO_Settings[i].name);
		cno_u8_type parser_section = 0;
		cno_u8_type j; ///Setting-parser index
		for(j=0; j<length_of_setting_name; j++){
			
