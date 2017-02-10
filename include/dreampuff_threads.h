//dreampuff_threads.h

#ifndef DREAMPUFF_THREADS_H
#define DREAMPUFF_THREADS_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_ALLOW_THREADS

#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
#include <SDL2/SDL_thread.h>
typedef SDL_Thread* DreamPuff_Thread_type;
typedef SDL_ThreadFunction DreamPuff_ThreadFunction_type;
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS

#endif //CNO_ALLOW_THREADS

cno_u8_type DreamPuff_Threads_Init();
cno_u8_type DreamPuff_Threads_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_THREADS_H
