//dreampuff_middleware.c

#include "dreampuff_middleware.h"

#if CNO_HAVE_SDL2
#include <SDL2/SDL.h>
#if CNO_HAVE_SDL2_IMAGE
#include <SDL2/SDL_image.h>
#endif //CNO_HAVE_SDL2_IMAGE
#if CNO_HAVE_SDL2_MIXER
#include <SDL2/SDL_mixer.h>
#endif //CNO_HAVE_SDL2_MIXER
#if CNO_HAVE_SDL2_TTF
#include <SDL2/SDL_ttf.h>
#endif //CNO_HAVE_SDL2_TTF
#endif //CNO_HAVE_SDL2

#include "cno_config.h"
#include "cno_log.h"

cno_u8_type DreamPuff_MiddleWare_Init(){
#if CNO_HAVE_SDL2
	if(CNO_LowLevelConfig.sdl2.sdl2enabled){
		cno_u32_type flags;
		if(CNO_LowLevelConfig.video.enabled) flags |= SDL_INIT_VIDEO;
		if(CNO_LowLevelConfig.audio.enabled) flags |= SDL_INIT_AUDIO;
		if(CNO_LowLevelConfig.joysticks.enabled) flags |= SDL_INIT_JOYSTICK;
		if(SDL_Init(flags) < 0){
			cno_log(1,"SDL failed to initialise: %s", SDL_GetError());
			return 0;
		}
		SDL_version sdlcompiled, sdllinked;
		SDL_VERSION(&sdlcompiled);
		SDL_GetVersion(&sdllinked);
		cno_log(2,"SDL %d.%d.%d (compiled) %d.%d.%d (linked)", sdlcompiled.major, sdlcompiled.minor, sdlcompiled.patch, sdllinked.major, sdllinked.minor, sdllinked.patch);
#if CNO_HAVE_SDL2_IMAGE
		if(CNO_LowLevelConfig.video.enabled && CNO_LowLevelConfig.sdl2image.enabled){
			flags = 0;
			if(CNO_LowLevelConfig.sdl2image.jpg) flags |= IMG_INIT_JPG;
			if(CNO_LowLevelConfig.sdl2image.png) flags |= IMG_INIT_PNG;
			if(CNO_LowLevelConfig.sdl2image.tif) flags |= IMG_INIT_TIF;
			if(IMG_Init(flags) != flags){
				cno_log(1,"SDL_Image failed to initialise: %s", IMG_GetError());
				return 0;
			}
			SDL_version sdlimagecompiled;
			SDL_IMAGE_VERSION(&sdlimagecompiled);
			SDL_version *sdlimagelinked = IMG_Linked_Version();
			cno_log(2,"SDL_Image %d.%d.%d (compiled) %d.%d.%d (linked)", sdlimagecompiled.major, sdlimagecompiled.minor, sdlimagecompiled.patch, sdlimagelinked->major, sdlimagelinked->minor, sdlimagelinked->patch);
		}
#endif //CNO_HAVE_SDL2_IMAGE
#if CNO_HAVE_SDL2_MIXER
		if(CNO_LowLevelConfig.audio.enabled && CNO_LowLevelConfig.sdl2mixer.enabled){
			flags = 0;
			if(CNO_LowLevelConfig.sdl2mixer.flac) flags |= MIX_INIT_FLAC;
			if(CNO_LowLevelConfig.sdl2mixer.mod) flags |= MIX_INIT_MOD;
			if(CNO_LowLevelConfig.sdl2mixer.mp3) flags |= MIX_INIT_MP3;
			if(CNO_LowLevelConfig.sdl2mixer.ogg) flags |= MIX_INIT_OGG;
			if(Mix_Init(flags) != flags){
				cno_log(1,"SDL_Mixer failed to initialise: %s", Mix_GetError());
				return 0;
			}
			SDL_version sdlmixercompiled;
			SDL_MIXER_VERSION(&sdlmixercompiled);
			SDL_version *sdlmixerlinked = Mix_Linked_Version();
			cno_log(2,"SDL_Mixer %d.%d.%d (compiled) %d.%d.%d (linked)", sdlmixercompiled.major, sdlmixercompiled.minor, sdlmixercompiled.patch, sdlmixerlinked->major, sdlmixerlinked->minor, sdlmixerlinked->patch);
		}
#endif //CNO_HAVE_SDL2_MIXER
#if CNO_HAVE_SDL2_TTF
		if(CNO_LowLevelConfig.sdl2.sdl2ttfenabled){
			if(TTF_Init() != 0){
				cno_log(1,"SDL_TTF failed to initialise: %s", TTF_GetError());
				return 0;
			}
			SDL_version sdlttfcompiled;
			SDL_TTF_VERSION(&sdlttfcompiled);
			SDL_version *sdlttflinked = TTF_Linked_Version();
			cno_log(2,"SDL_TTF %d.%d.%d (compiled) %d.%d.%d (linked)", sdlttfcompiled.major, sdlttfcompiled.minor, sdlttfcompiled.patch, sdlttflinked->major, sdlttflinked->minor, sdlttflinked->patch);
		}
#endif //CNO_HAVE_SDL2_TTF
	return 1;
	}
#endif //CNO_HAVE_SDL2
	return 0;
}

cno_u8_type DreamPuff_MiddleWare_Quit(){
#if CNO_HAVE_SDL2
	if(CNO_LowLevelConfig.sdl2.sdl2enabled){
#if CNO_HAVE_SDL2_TTF
		if(CNO_LowLevelConfig.sdl2.sdl2ttfenabled){
			TTF_Quit();
			cno_log(3,"SDL_TTF quit");
		}
#endif //CNO_HAVE_SDL2_TTF
#if CNO_HAVE_SDL2_MIXER
		if(CNO_LowLevelConfig.sdl2mixer.enabled){
			Mix_Quit();
			cno_log(3,"SDL_Mixer quit");
		}
#endif //CNO_HAVE_SDL2_MIXER
#if CNO_HAVE_SDL2_IMAGE
		if(CNO_LowLevelConfig.sdl2image.enabled){
			IMG_Quit();
			cno_log(3,"SDL_Image quit");
		}
#endif //CNO_HAVE_SDL2_IMAGE
		SDL_Quit();
		cno_log(2,"SDL quit");
		return 1;
	}
#endif //CNO_HAVE_SDL2
	return 0;
}
