//dreampuff_events.h

#ifndef DREAMPUFF_EVENTS_H
#define DREAMPUFF_EVENTS_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

typedef struct DreamPuff_Event_struct{
	cno_u8_type code[8];
	cno_s16_type value;
	cno_u32_type time;
} DreamPuff_Event_type;
DreamPuff_Event_type *DreamPuff_Events;

cno_u8_type DreamPuff_Events_Process();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_EVENTS_H
