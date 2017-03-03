//dreampuff_threads.c

#include "dreampuff_threads.h"
#include "dreampuff_core.h"
#include "dreampuff_mutex.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_ALLOW_THREADS
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
DreamPuff_Thread_type DreamPuff_LogicThread;
DreamPuff_ThreadFunction_type DreamPuff_LogicThread_function(void *ptr){
	dp_log(3,"DreamPuff Logic Thread Initialised.");
	while(DreamPuff_Engine_IsRunning()){
		//dp_log(1,"Yo from logic thread");
		//Logic_Real()
	}
	dp_log(3, "DreamPuff Logic Thread Terminating.");
	return 0;
}
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
#endif //CNO_ALLOW_THREADS


cno_u8_type DreamPuff_Threads_Init(){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			if(CNO_LowLevelConfig.threads.logic) DreamPuff_LogicThread = SDL_CreateThread(DreamPuff_LogicThread_function, "DPLogicThread", NULL);
		}
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		DreamPuff_Mutex_Init();
		return 1;
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
cno_u8_type DreamPuff_Threads_Quit(){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
		DreamPuff_Mutex_Quit();
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			if(CNO_LowLevelConfig.threads.logic) SDL_WaitThread(DreamPuff_LogicThread, NULL);
		}
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		return 1;
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
		
			
