//cno_log.h

#ifndef CNO_LOG_H
#define CNO_LOG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_STDARG
#include <stdarg.h>
typedef va_list cno_va_list_type;
#endif //CNO_HAVE_STDARG

#define cno_log(priority, ...) (priority < CNO_LowLevelConfig.debug/* && LOGTHISFUNCTION == 1*/)?(CNO_GlobalLog(__func__, __VA_ARGS__)):(CNO_noop)

cno_u8_type CNO_GlobalLog(cno_cstring_type function, cno_cstring_type format, ...);
cno_u8_type CNO_SpecificLog(cno_cstring_type filename, cno_cstring_type function, cno_cstring_type format, ...);
cno_u8_type CNO_NewGlobalLog();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_LOG_H
