//cno_thread.h

#ifndef CNO_THREAD_H
#define CNO_THREAD_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if (CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2) && C\H\SDL2
#include <SDL2/SDL_thread.h>

typedef SDL_Thread* c\thread\ty;
typedef int c\threadfunction\ty;
#endif //(CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2) && C\H\SDL2

c\u8\ty CNO_Thread_Create(c\thread\ty thread, c\threadfunction\ty function, c\cstring\ty name);
c\u8\ty CNO_Thread_Wait(c\thread\ty thread);
//c\u8\ty CNO_Thread_Destroy(c\thread\ty thread);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_THREAD_H
