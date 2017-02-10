//dreampuff_core.h

#ifndef DREAMPUFF_CORE_H
#define DREAMPUFF_CORE_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#include "dreampuff_mode.h"

typedef struct DreamPuff_Engine_struct{
	cno_u8_type running;
	cno_u8_type sleeping;
	DreamPuff_Mode_type mode;
} DreamPuff_Engine_type;

cno_u8_type DreamPuff_Engine_IsRunning();
cno_u8_type DreamPuff_Engine_IsSleeping();
cno_u8_type DreamPuff_Engine_Sleep();
cno_u8_type DreamPuff_Engine_Wake();
cno_u8_type DreamPuff_Engine_Stop();

cno_u8_type DreamPuff_Init();
cno_u8_type DreamPuff_Input();
cno_u8_type DreamPuff_Net();
cno_u8_type DreamPuff_Logic();
cno_u8_type DreamPuff_FileIO();
cno_u8_type DreamPuff_Video();
cno_u8_type DreamPuff_Audio();
cno_u8_type DreamPuff_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_CORE_H
