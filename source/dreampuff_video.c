//dreampuff_video.c

#include "dreampuff_video.h"

#include "cno_config.h"
#include "cno_log.h"

#include "dreampuff_mutex.h"

#if CNO_HAVE_SDL2
#include <SDL2/SDL.h>
#if CNO_HAVE_SDL2_IMAGE
#include <SDL2/SDL_image.h>
#endif //CNO_HAVE_SDL_IMAGE
#if CNO_HAVE_SDL2_TTF
#include <SDL2/SDL_ttf.h>
typedef TTF_Font* DreamPuff_Font_type;
#endif //CNO_HAVE_SDL2_TTF
typedef SDL_Window* DreamPuff_Window_type;
typedef SDL_Renderer* DreamPuff_Renderer_type;
typedef SDL_Texture* DreamPuff_Texture_type;
typedef SDL_Surface* DreamPuff_Surface_type;
typedef SDL_Color DreamPuff_Colour_type;
typedef SDL_Point DreamPuff_Point_type;
typedef SDL_Rect DreamPuff_Rect_type;
#endif //CNO_HAVE_SDL2

DreamPuff_Window_type DreamPuff_Window;
DreamPuff_Renderer_type DreamPuff_Renderer;

#if CNO_HAVE_STRETCHYBUFFER
#include "stretchy_buffer.h"
#endif //CNO_HAVE_STRETCHYBUFFER

DreamPuff_Font_type *DreamPuff_Fonts;

static DreamPuff_Colour_type DreamPuff_Colours[] = {
	{0,0,0,255}, //black
	{255,0,0,255}, //red
	{0,255,0,255}, //green
	{255,255,0,255}, //yellow
	{0,0,255,255}, //blue
	{255,0,255,255}, //purple
	{0,255,255,255}, //cyan
	{255,255,255,255} //white
};
typedef enum DreamPuff_Colours_Name_enum{
	DreamPuff_Colour_Black=0,
	DreamPuff_Colour_Red,
	DreamPuff_Colour_Green,
	DreamPuff_Colour_Yellow,
	DreamPuff_Colour_Blue,
	DreamPuff_Colour_Purple,
	DreamPuff_Colour_Cyan,
	DreamPuff_Colour_White,
	NumberofDreamPuff_Colour
} DreamPuff_Colour_Name_type;

cno_u8_type DreamPuff_Video_CreateSurfaceFromRenderer(DreamPuff_Surface_type *surface){
#if CNO_HAVE_SDL2
	*surface = SDL_CreateRGBSurface(0, CNO_LowLevelConfig.video.width, CNO_LowLevelConfig.video.height, CNO_LowLevelConfig.video.bitsperpixel, 0, 0, 0, 0);
	if(*surface != NULL){
		if(SDL_MUSTLOCK(*surface)) SDL_LockSurface(*surface);
		cno_s8_type result;
		result = SDL_RenderReadPixels(DreamPuff_Renderer, NULL, 0, *surface->pixels, *surface->pitch);
		if(SDL_MUSTLOCK(*surface)) SDL_UnlockSurface(*surface);
		if(result == 0){
			cno_log(5, "Success. %s", SDL_GetError());
			return 1;
		}
	}
	cno_log(5,"Failure. %s", SDL_GetError());
#endif //CNO_HAVE_SDL2
	return 0;
}
cno_u8_type DreamPuff_Video_Init(){
#if CNO_HAVE_SDL2
	if(CNO_LowLevelConfig.sdl2.sdl2enabled){
		cno_s16_type VideoDrivers, VideoDisplays;
		VideoDrivers = SDL_GetNumVideoDrivers();
		VideoDisplays = SDL_GetNumVideoDisplays();
		cno_log(3,"Video Drivers: %d Video Displays: %d", VideoDrivers, VideoDisplays);
		cno_u8_type i;
		for(i = 0; i < VideoDrivers; i++){
			cno_log(3,"Video Driver %d: %s", i, SDL_GetVideoDriver(i));
		}
		for(i = 0; i < VideoDisplays; i++){
			cno_log(3,"Display %d: %s %d", i, SDL_GetDisplayName(i), SDL_GetNumDisplayModes(i));
		}
		cno_u32_type flags;
		if(CNO_LowLevelConfig.video.exclusivefullscreen) flags |= SDL_WINDOW_FULLSCREEN;
		if(CNO_LowLevelConfig.video.resizable) flags |= SDL_WINDOW_RESIZABLE;
		if(CNO_LowLevelConfig.video.borderless) flags |= SDL_WINDOW_BORDERLESS;
		if(SDL_CreateWindowAndRenderer(CNO_LowLevelConfig.video.width, CNO_LowLevelConfig.video.height, flags, &DreamPuff_Window, &DreamPuff_Renderer) != 0){
			cno_log(1,"Couldn't create window/renderer: %s", SDL_GetError());
			return 0;
		}
		cno_log(2,"Window and Renderer created");
		return 1;
	}
#endif //CNO_HAVE_SDL2
	return 0;
}
cno_u8_type DreamPuff_Video_LoadTexture(cno_cstring_type filename){
#if CNO_HAVE_SDL2 && CNO_HAVE_SDL2_IMAGE && CNO_HAVE_STRETCHYBUFFER
	if(CNO_LowLevelConfig.video.enabled && CNO_LowLevelConfig.sdl2.sdl2enabled && CNO_LowLevelConfig.sdl2image.enabled){
		DreamPuff_Texture_type texture;
		texture = IMG_LoadTexture(DreamPuff_Renderer, filename);
		sb_push(DreamPuff_Textures, texture);
		dp_log(4,"Attempting to load %s %s %s %d", filename, SDL_GetError(), IMG_GetError(), sb_count(DreamPuff_Textures));
		return sb_count(DreamPuff_Textures);
	}
#endif //CNO_HAVE_SDL2 && CNO_HAVE_SDL2_IMAGE && CNO_HAVE_STRETCHYBUFFER
	return 0;
}
cno_u8_type DreamPuff_Video_LoadFont(cno_cstring_type filename, cno_u16_type size){
#if CNO_HAVE_SDL2 && CNO_HAVE_SDL2_TTF && CNO_HAVE_STRETCHYBUFFER
	if(CNO_LowLevelConfig.video.enabled && CNO_LowLevelConfig.sdl2.sdl2enabled && CNO_LowLevelConfig.sdl2.sdl2ttfenabled){
		DreamPuff_Font_type font;
		font = TTF_OpenFont(filename, size);
		sb_push(DreamPuff_Fonts,font);
		dp_log(4,"Attempting to load %s %s %s %d", filename, SDL_GetError(), TTF_GetError(), sb_count(DreamPuff_Fonts));
		return sb_count(DreamPuff_Fonts);
	}
#endif //CNO_HAVE_SDL2 && CNO_HAVE_SDL2_TTF && CNO_HAVE_STRETCHYBUFFER
	return 0;
}
cno_u8_type DreamPuff_Video_Render(){
	//bg, tilemap, sprites, fg, HUD, cover, menu HUD2
	DreamPuff_Video_RenderBG()
	//DreamPuff_Video_RenderTilemap()
	//DreamPuff_Video_RenderObjects()
	//DreamPuff_Video_RenderFG()
	//DreamPuff_Video_RenderHUD()
	//DreamPuff_Video_RenderCover()
	//DreamPuff_Video_RenderMenu()
	//DreamPuff_Video_RenderHUD2();
	DreamPuff_Video_Update();
	return 0;
}
cno_u8_type DreamPuff_Video_SaveScreenshot(){
#if CNO_HAVE_STDIO && CNO_HAVE_TIME && CNO_HAVE_SDL2
	cno_u8_type buffer[32];
	CNO_Time_Full(buffer);
	DreamPuff_Surface_type surface;
	DreamPuff_Video_CreateSurfaceFromRenderer(&surface);
	if(CNO_LowLevelConfig.video.savescreenshotbmp){
		cno_cstring_type filename;
		CNO_sprintf(filename, "%s%s.bmp", CNO_LowLevelConfig.directories.userdata, buffer);
		SDL_SaveBMP(surface, filename);
	}
#if CNO_HAVE_SDL2_IMAGE
	if(CNO_LowLevelConfig.video.savescreenshotpng){
		cno_cstring_type filename;
		CNO_sprintf(filename, "%s%s.png", CNO_LowLevelConfig.directories.userdata, buffer);
		IMG_SavePNG(surface, filename);
	}
#endif //CNO_HAVE_SDL2_IMAGE
	if(surface != NULL) SDL_FreeSurface(surface);
	return 1;
#endif //CNO_HAVE_STDIO && CNO_HAVE_TIME && CNO_HAVE_SDL2
	return 0;
}
cno_u8_type DreamPuff_Video_Quit(){
#if CNO_HAVE_SDL2
	if(CNO_LowLevelConfig.sdl2.sdl2enabled){
		SDL_DestroyRenderer(DreamPuff_Renderer);
		cno_log(2,"Renderer destroyed %s", SDL_GetError());
		SDL_DestroyWindow(DreamPuff_Window);
		cno_log(2,"Window destroyed %s", SDL_GetError());
		return 1;
	}
#endif //CNO_HAVE_SDL2
	return 0;
}
