//cno_thread.c

#include "cno_thread.h"

#if C\H\STDIO
#include <stdio.h> // fprintf
#endif //C\H\STDIO

#if CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2
#include <SDL2/SDL_error.h>
#endif //CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2

c\u8\ty CNO_Thread_Create(c\thread\ty thread, c\threadfunction\ty function, c\cstring\ty name){
	c\u8\ty _return;
#if (CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	thread = SDL_CreateThread(function, name, NULL);
	if(thread != NULL) _return = 1;
	else{
		_return = 0;
		CNO_fprintf(stderr, "SDL_CreateThread error: %s", SDL_GetError());
	}
#else
	_return = 0;
#endif //(CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	return _return;
}
c\u8\ty CNO_Thread_Wait(c\thread\ty thread){
	c\u8\ty _return;
#if (CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	c\threadfunction\ty threadfunction_return;
	SDL_WaitThread(thread, &threadfunction_return);
	CNO_fprintf(stderr, "Thread returned with %d", threadfunction_return);
	_return = 1;
#else
	_return = 0;
#endif //(CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	return _return;
}