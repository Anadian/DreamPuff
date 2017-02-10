//dreampuff_render.h

#ifndef DREAMPUFF_RENDER_H
#define DREAMPUFF_RENDER_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_SDL2
typedef SDL_Color DreamPuff_Colour;
typedef SDL_Texture* Texture;
#endif //CNO_HAVE_SDL2

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_RENDER_H
