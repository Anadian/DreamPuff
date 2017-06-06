//cno_settings.c
#include <cno_settings.h>

#if CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX
#include <regex.h> //regcomp regerror regexec regfree
c\u8\ty CNO_CompileRegex(regex_t *compiled_regex, c\cstring\ty regular_expression){
	
}
#endif //CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX

c\u8\ty CNO_Settings_Init(CNO_Setting\t *settings){
#if CNO_SETTINGS_LOG_ENGINE == CNO_SETTINGS_LOG_ENGINE_CLOGGED
	clg_logger_default(CNO_Log, CNO_SETTINGS_LOG_LEVEL);
#endif //CNO_SETTINGS_LOG_ENGINE == CNO_SETTINGS_LOG_ENGINE_CLOGGED
	