//cno_time.h: Time retrieval functions

#ifndef CNO_TIME_H
#define CNO_TIME_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_TIME
#include <time.h>
typedef time_t cno_unixtime_type;
typedef clock_t cno_clocktime_type;
typedef struct tm cno_calendartime_type;
#endif //CNO_HAVE_TIME

cno_unixtime_type CNO_Time_Unix();
cno_u8_type CNO_Time_Calendar(cno_u8_type *buffer);
cno_u8_type CNO_Time_Concise(cno_u8_type *buffer);
cno_u8_type CNO_Time_Full(cno_cstring_type buffer);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_TIME_H
