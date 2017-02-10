//dreampuff_time.h

#ifndef DREAMPUFF_TIME_H
#define DREAMPUFF_TIME_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#include "dreampuff_mutex.h"

typedef struct DreamPuff_Timer_struct{
	cno_u8_type paused;
	cno_u32_type activeticks;
	cno_u32_type inactiveticks;
	DreamPuff_Mutex_type mutex;
} DreamPuff_Timer_type;

cno_u8_type DreamPuff_Time_CreateTimer(DreamPuff_Timer_type *timer);
cno_u8_type DreamPuff_Time_DestroyTimer(DreamPuff_Timer_type *timer);
cno_u32_type DreamPuff_Time_GetTicks(DreamPuff_Timer_type *timer);
cno_u8_type DreamPuff_Time_ResetTicks(DreamPuff_Timer_type *timer);
cno_u8_type DreamPuff_Time_SetPause(DreamPuff_Timer_type *timer, cno_u8_type pause);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_TIME_H
