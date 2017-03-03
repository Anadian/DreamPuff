//dreampuff_mutex.h

#ifndef DREAMPUFF_MUTEX_H
#define DREAMPUFF_MUTEX_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_ALLOW_THREADS
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
#include <SDL2/SDL_mutex.h>
typedef SDL_mutex* DreamPuff_Mutex_type;
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
#else //CNO_ALLOW_THREADS
typedef void DreamPuff_Mutex_type;
#endif //CNO_ALLOW_THREADS

#define dp_log(...) DreamPuff_Mutex_Lock_By_Name(DreamPuff_Log_Mutex); cno_log(__VA_ARGS__); DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Log_Mutex);

typedef enum DreamPuff_Mutex_Name_enum{
	DreamPuff_Engine_Mutex=0,
	DreamPuff_Log_Mutex,
	DreamPuff_Actions_Mutex,
	DreamPuff_Render_Mutex,
	NumberofDreamPuff_Mutex
} DreamPuff_Mutex_Name_type;

cno_u8_type DreamPuff_Mutex_Create(DreamPuff_Mutex_type *mutex);
cno_u8_type DreamPuff_Mutex_Destroy(DreamPuff_Mutex_type *mutex);
cno_u8_type DreamPuff_Mutex_Init();
cno_u8_type DreamPuff_Mutex_Lock_Mutex(DreamPuff_Mutex_type *mutex);
cno_u8_type DreamPuff_Mutex_Lock_By_Name(DreamPuff_Mutex_Name_type mutexname);
cno_u8_type DreamPuff_Mutex_Unlock_Mutex(DreamPuff_Mutex_type *mutex);
cno_u8_type DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Mutex_Name_type mutexname);
cno_u8_type DreamPuff_Mutex_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_MUTEX_H
