//cno_log.h

#ifndef CNO_LOG_H
#define CNO_LOG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

// #if !defined(CNO_LOG_ENGINE)
// #define CNO_LOG_ENGINE CNO_LOG_ENGINE_NONE
// #endif //!defined(CNO_SETTINGS_LOG_ENGINE)
// 
// #if CNO_LOG_ENGINE == CNO_LOG_ENGINE_ORIGINAL
// #if CNO_HAVE_STDARG
// #include <stdarg.h>
// typedef va_list cno_va_list_type;
// #endif //CNO_HAVE_STDARG
// 
// #define cno_log(priority, ...) (priority <= CNO_LowLevelConfig.debug.verbosity)?(CNO_GlobalLog(__func__, __VA_ARGS__)):(CNO_noop)
// 
// cno_u8_type CNO_GlobalLog(cno_cstring_type function, cno_cstring_type format, ...);
// cno_u8_type CNO_SpecificLog(cno_cstring_type filename, cno_cstring_type function, cno_cstring_type format, ...);
// cno_u8_type CNO_NewGlobalLog();
// 
// #elif CNO_LOG_ENGINE == CNO_LOG_ENGINE_LOGH
// #include "log.h"
// 
// #define cno_log(...) CNO_noop
// #define cno_log_debug(...) log_debug(__VA_ARGS__)
// #define cno_log_info(...) log_info(__VA_ARGS__)
// #define cno_log_warn(...) log_warn(__VA_ARGS__)
// #define cno_log_error(...) log_error(__VA_ARGS__)
// #else
// #define cno_log(...) CNO_noop
// #define cno_log_debug(...) CNO_noop
// #define cno_log_info(...) CNO_noop
// #define cno_log_warn(...) CNO_noop
// #define cno_log_error(...) CNO_noop
// #endif //CNO_LOG_ENGINE

#if CNO_HAVE_STDARG
#include <stdarg.h>
#endif //CNO_HAVE_STDARG
#if CNO_HAVE_UNISTD
#include <unistd.h> //isatty
#endif //CNO_HAVE_UNISTD

#include "cno_time.h"
#include "cno_mutex.h"

//\033[[STYLE];[COLOUR]m	Start format
//\x1B[0m 	Reset to plain/normal.
//[STYLE]:
//0 normal
//1 bold
//2 dim
//3 italics
//4 underline
//5 blinking
//6 ???
//7 White on colour background
//8 Invisible
//[COLOUR]:
//30 black
//31 red
//32 green
//33 yellow
//34 blue
//35 magenta
//36 cyan
//37 white

typedef enum CNO_Log_Priority_enum{
	CNO_Log_Priority_Critical=0,
	CNO_Log_Priority_Error=1, //Red
	CNO_Log_Priority_Warn=2, //Yellow
	CNO_Log_Priority_Info=3, //Blue
	CNO_Log_Priority_Special=4, //Magenta
	CNO_Log_Priority_Debug=5 //Green
} CNO_Log_Priority_type; //cyan?

typedef struct CNO_Log_struct{
	CNO_Log_Priority_type verbosity;
	cno_u8_type colour;
	cno_u8_type stream; //stream: 1 (stdout), 2 (stderr), 3 (stdout and stderr), any other number (no streams)
	cno_cstring_type file;
	c\u8\ty persist; //Keep file open
	c\u8\ty overwrite; //Overwrite file if it already exist, otherwise append
} CNO_Log_type;

#if !defined(CNO_NO_GLOBAL_STATE)
cno_mutex_type CNO_Log_Mutex;
C\Log\ty CNO_DefaultLog;
#endif //!defined(CNO_NO_GLOBAL_STATE)

//[bold] Error: [dim] file (line): [normal] function (time unix/clock): message (errno: strerror | other error messages)
c\u8\ty C\Log_Init();
c\u8\ty C\Log_Set(C\Log\ty *log, C\Log\ty value);
/*c\u8\ty C\Log_verbosity_Get(C\Log\ty *log, C\Log_Priority\ty *verbosity);
c\u8\ty C\Log_verbosity_Set(C\Log\ty *log, C\Log_Priority\ty verbosity);
cno_u8_type CNO_Log_colour_Get(CNO_Log_type *log, c\u8\ty *colour);
cno_u8_type CNO_Log_colour_Set(CNO_Log_type *log, c\u8\ty colour);
cno_u8_type CNO_Log_stream_Get(CNO_Log_type *log, c\u8\ty *stream);
cno_u8_type CNO_Log_stream_Set(CNO_Log_type *log, c\u8\ty stream);
cno_u8_type CNO_Log_file_Get(CNO_Log_type *log, c\cstring\ty *file);
cno_u8_type CNO_Log_file_Set(CNO_Log_type *log, c\cstring\ty file);
cno_u8_type CNO_Log_persist_Get(CNO_Log_type *log, c\u8\ty *persist);
cno_u8_type CNO_Log_persist_Set(CNO_Log_type *log, c\u8\ty persist);
cno_u8_type CNO_Log_overwrite_Get(CNO_Log_type *log, c\u8\ty *overwrite);
cno_u8_type CNO_Log_overwrite_Set(CNO_Log_type *log, c\u8\ty overwrite);*/
cno_u8_type CNO_Log(CNO_Log_type *log, CNO_Log_Priority_type priority, cno_cstring_type file, cno_cstring_type line, cno_cstring_type function, cno_unixtime_type unix_time, cno_clocktime_type clock_time, cno_cstring_type format, ...);
c\u8\ty C\Log_Unset(C\Log\ty *Log);
c\u8\ty C\Log_Test();
cno_u8_type CNO_Log_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_LOG_H
