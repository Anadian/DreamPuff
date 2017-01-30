//dreampuff.c

#include "dreampuff.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_HAVE_SDL2
#include <SDL2/SDL.h>
#endif //CNO_HAVE_SDL2

cno_u8_type DreamPuff_Init(){
	if(CNO_LowLevelConfig.debug.enabled){
		CNO_NewGlobalLog();
		cno_log(1, "Test %d %c %s %f", 234, 'a', "yo", 0.112);
	}
	if(CNO_LowLevelConfig.sdl2 > 0){
		
	}
	return 0;
}
	
cno_u8_type DreamPuff_Quit(){
	return 0;
}
