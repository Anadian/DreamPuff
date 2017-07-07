//cno_mutex.h

#ifndef CNO_MUTEX_H
#define CNO_MUTEX_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if (CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2) && CNO_HAVE_SDL2
#include <SDL2/SDL_mutex.h>
typedef SDL_mutex* cno_mutex_type;
#endif //CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2) && CNO_HAVE_SDL2

#if CNO_THREAD_ENGINE != CNO_THREAD_ENGINE_NONE
cno_u8_type CNO_Mutex_Create(cno_mutex_type mutex);
cno_u8_type CNO_Mutex_Lock(cno_mutex_type mutex);
cno_u8_type CNO_Mutex_Unlock(cno_mutex_type mutex);
cno_u8_type CNO_Mutex_Destroy(cno_mutex_type mutex);
#endif //CNO_THREAD_ENGINE != CNO_THREAD_ENGINE_NONE

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_MUTEX_H
