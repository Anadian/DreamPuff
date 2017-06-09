//cno_settings.c
#include <cno_settings.h>

#if C\SETTINGS_LOG_ENGINE == C\SETTINGS_LOG_ENGINE_CLOGGED
c\u8\ty C\Settings_Log_Clogged_Init()

#if CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX
#include <regex.h> //regcomp regerror regexec regfree
c\u8\ty CNO_CompileRegex(regex_t *compiled_regex, c\cstring\ty regular_expression){
	
}
#endif //CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX

c\u8\ty CNO_Settings_Log_Init(){
#if CNO_SETTINGS_LOG_ENGINE == CNO_SETTINGS_LOG_ENGINE_CLOGGED
	clg_logger_default(CNO_Log, CNO_SETTINGS_LOG_LEVEL);
	return 1;
#endif //CNO_SETTINGS_LOG_ENGINE == CNO_SETTINGS_LOG_ENGINE_CLOGGED
	return 0;
}

c\u8\ty CNO_Settings_Init(CNO_Log\ty *log, CNO_Setting\t *settings){
	CNO_Settings_Log_Init(log);
	CNO_Settings
	
	