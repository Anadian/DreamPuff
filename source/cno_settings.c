//cno_settings.c
#include <cno_settings.h>

#if CNO_HAVE_STDIO
#include <stdio.h> //fprintf
#include <stddef.h> //size_t
#endif //CNO_HAVE_STDIO

#if C\H\STRING
#include <string.h>
#endif //C\H\STRING

#if C\H\GOPT && C\A\OPTIONS
#include "gopt.h"
#endif //C\H\GOPT && C\A\OPTIONS

cno_u8_type CNO_Settings_Init(){
	cno_u8_type _return;
	c\size\ty number_of_settings;
	number_of_settings = (sizeof(CNO_Settings)/sizeof(CNO_Setting\ty));
	c\size\ty i; ///Settings index
	for(i=0; i<number_of_settings; i++){
		c\u8\ty section[32];
		c\u8\ty config_name[32];
		c\u8\ty option_name[32];
		c\u8\ty option_key;
		C\Value_Type\ty value_type;
		c\u8\ty hint[32];
		c\u8\ty description[CNO_BUFFER_MAXSIZE];
		c\u8\ty valid_values[32];
		c\u8\ty argument[C\BUFFER_MAXSIZE];
		c\size\ty length_of_setting_name;
		length_of_setting_name = sizeof(CNO_Settings[i].name);
		c\u8\ty parser_section = 0;
		c\u8\ty j; ///Setting-parser index
		for(j=0; j<length_of_setting_name; j++){
			
