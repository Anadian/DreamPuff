//dreampuff_time.c

#include "dreampuff_time.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_HAVE_SDL2
#include <SDL2/SDL.h> //SDL_GetTicks()
#endif //CNO_HAVE_SDL2

cno_u8_type DreamPuff_Time_CreateTimer(DreamPuff_Timer_type *timer){
#if CNO_HAVE_SDL2
	return DreamPuff_Mutex_Create(&(timer->mutex));
#endif //CNO_HAVE_SDL2
	return 0;
}
cno_u8_type DreamPuff_Time_DestroyTimer(DreamPuff_Timer_type *timer){
#if CNO_HAVE_SDL2
	return DreamPuff_Mutex_Destroy(&(timer->mutex));
#endif //CNO_HAVE_SDL2
	return 0;
}
cno_u32_type DreamPuff_Time_GetTicks(DreamPuff_Timer_type *timer){
#if CNO_HAVE_SDL2
	DreamPuff_Mutex_Lock_Mutex(&(timer->mutex));
	cno_u32_type ticks;
	if(timer->paused) ticks = timer->activeticks;
	else ticks = (SDL_GetTicks() - timer->inactiveticks);
	DreamPuff_Mutex_Unlock_Mutex(&(timer->mutex));
	return ticks;
#endif //CNO_HAVE_SDL2
	return 0;
}
cno_u8_type DreamPuff_Time_ResetTicks(DreamPuff_Timer_type *timer){
#if CNO_HAVE_SDL2
	DreamPuff_Mutex_Lock_Mutex(&(timer->mutex));
	timer->paused = 0;
	timer->activeticks = 0;
	timer->inactiveticks = SDL_GetTicks();
	DreamPuff_Mutex_Unlock_Mutex(&(timer->mutex));
	return 1;
#endif //CNO_HAVE_SDL2
	return 0;
}
cno_u8_type DreamPuff_Time_SetPause(DreamPuff_Timer_type *timer, cno_u8_type pause){
#if CNO_HAVE_SDL2
	DreamPuff_Mutex_Lock_Mutex(&(timer->mutex));
	if(timer->paused == 0){
		if(pause == 1){
			timer->activeticks = (SDL_GetTicks() - timer->inactiveticks);
			timer->paused = 1;
		}
	}else{
		if(pause == 0){
			timer->inactiveticks = (SDL_GetTicks() - timer->activeticks);
			timer->paused = 0;
		}
	}
	DreamPuff_Mutex_Unlock_Mutex(&(timer->mutex));
	return 1;
#endif //CNO_HAVE_SDL2
	return 0;
}
