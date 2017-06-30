//cno_log.h

#ifndef CNO_LOG_H
#define CNO_LOG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if !defined(CNO_LOG_ENGINE)
#define CNO_LOG_ENGINE CNO_LOG_ENGINE_NONE
#endif //!defined(CNO_SETTINGS_LOG_ENGINE)

#if CNO_LOG_ENGINE == CNO_LOG_ENGINE_ORIGINAL
#if CNO_HAVE_STDARG
#include <stdarg.h>
typedef va_list cno_va_list_type;
#endif //CNO_HAVE_STDARG

#define cno_log(priority, ...) (priority <= CNO_LowLevelConfig.debug.verbosity)?(CNO_GlobalLog(__func__, __VA_ARGS__)):(CNO_noop)

cno_u8_type CNO_GlobalLog(cno_cstring_type function, cno_cstring_type format, ...);
cno_u8_type CNO_SpecificLog(cno_cstring_type filename, cno_cstring_type function, cno_cstring_type format, ...);
cno_u8_type CNO_NewGlobalLog();

#elif CNO_LOG_ENGINE == CNO_LOG_ENGINE_LOGH
#include "log.h"

#define cno_log(...) CNO_noop
#define cno_log_debug(...) log_debug(__VA_ARGS__)
#define cno_log_info(...) log_info(__VA_ARGS__)
#define cno_log_warn(...) log_warn(__VA_ARGS__)
#define cno_log_error(...) log_error(__VA_ARGS__)
#else
#define cno_log(...) CNO_noop
#define cno_log_debug(...) CNO_noop
#define cno_log_info(...) CNO_noop
#define cno_log_warn(...) CNO_noop
#define cno_log_error(...) CNO_noop
#endif //CNO_LOG_ENGINE
#if C\H\STDARG
#include <stdarg.h>
#endif //C\H\STDARG
#if C\H\ERRNO
#include <errno.h>
#endif //C\H\ERRNO
#if C\H\TIME
#include "cno_time.h"

cno_u8_type CNO_Log_Init();
cno_u8_type CNO_Log(cno_u8_type priority, c\cstring\ty file, c\cstring\ty line, c\cstring\ty function, c\s16\ty errno, c\unixtime\ty unix_time, c\clocktime\ty clock_time, cno_cstring_type format, ...);
cno_u8_type CNO_Log_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_LOG_H
