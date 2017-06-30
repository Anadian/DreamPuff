//cno_settings.c
#include <cno_settings.h>

#if CNO_HAVE_STDIO
#include <stdio.h> //fprintf
#include <stddef.h> //size_t
#endif //CNO_HAVE_STDIO

#if CNO_HAVE_REGEX && (CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX)
#include <regex.h> //regcomp regerror regexec regfree, regex_t
regex_t CNO_Settings_Match_Validation_Regex;

cno_u8_type CNO_Settings_Match_Regex_Compile(regex_t *compiled_regex, cno_cstring_type pattern){
	cno_u8_type _return;
	cno_s16_type regcomp_result;
	regcomp_result = regcomp(compiled_regex, pattern, REG_EXTENDED);
	if(regcomp_result){
#if CNO_HAVE_STDIO
		cno_u8_type buffer[CNO_BUFFER_MAXSIZE];
		size_t regerror_result;
		regerror_result = regerror(regcomp_result, &validation_regex, buffer, CNO_BUFFER_MAXSIZE);
		fprintf(stderr, "%s: %d %s %d %s %d", __func__, regcomp_result, buffer, regerror_result, CNO_SETTINGS_MATCH_VALIDATION_REGEX, CNO_BUFFER_MAXSIZE);
#endif //CNO_HAVE_STDIO
		_return = 0;
	} else{
		_return = 1;
	}
	return _return;
}
#endif //CNO_HAVE_REGEX && (CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX)

cno_u8_type CNO_Settings_Init(CNO_Setting_type *settings){
	cno_u8_type _return;
#if (CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX) && CNO_HAVE_REGEX && defined(CNO_SETTINGS_MATCH_VALIDATION_REGEX)
	CNO_Settings_Match_Regex_Compile(&validation_regex, CNO_SETTINGS_MATCH_VALIDATION
	
	
