//dreampuff_mutex.c

#include "dreampuff_mutex.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_ALLOW_THREADS
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
DreamPuff_Mutex_type DreamPuff_Mutex[NumberofDreamPuff_Mutex];
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
#endif //CNO_ALLOW_THREADS

cno_u8_type DreamPuff_Mutex_Create(DreamPuff_Mutex_type *mutex){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			*mutex = SDL_CreateMutex();
			cno_log(5,"%s", SDL_GetError());
		}
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		return 1;
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
cno_u8_type DreamPuff_Mutex_Destroy(DreamPuff_Mutex_type *mutex){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			SDL_DestroyMutex(*mutex);
			cno_log(5,"%s", SDL_GetError());
		}
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		return 1;
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
cno_u8_type DreamPuff_Mutex_Init(){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			cno_u8_type i;
			for(i = 0; i < NumberofDreamPuff_Mutex; i++){
				DreamPuff_Mutex[i] = SDL_CreateMutex();
			}
		}
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		return 1;
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
cno_u8_type DreamPuff_Mutex_Lock_Mutex(DreamPuff_Mutex_type *mutex){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			SDL_LockMutex(*mutex);
		}
		return 1;
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}	
cno_u8_type DreamPuff_Mutex_Lock_By_Name(DreamPuff_Mutex_Name_type mutexname){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			SDL_LockMutex(DreamPuff_Mutex[mutexname]);
		}
		return 1;
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
cno_u8_type DreamPuff_Mutex_Unlock_Mutex(DreamPuff_Mutex_type *mutex){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			SDL_UnlockMutex(*mutex);
		}
		return 1;
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
cno_u8_type DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Mutex_Name_type mutexname){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			SDL_UnlockMutex(DreamPuff_Mutex[mutexname]);
		}
		return 1;
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
cno_u8_type DreamPuff_Mutex_Quit(){
#if CNO_ALLOW_THREADS
	if(CNO_LowLevelConfig.threads.enabled){
#if CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
		if(CNO_LowLevelConfig.threads.sdl2){
			cno_u8_type i;
			for(i = 0; i < NumberofDreamPuff_Mutex; i++){
				SDL_DestroyMutex(DreamPuff_Mutex[i]);
			}
		}
		return 1;
#endif //CNO_HAVE_SDL2 && CNO_ALLOW_SDL2_THREADS
	}
#endif //CNO_ALLOW_THREADS
	return 0;
}
