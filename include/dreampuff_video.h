//dreampuff_video.h

#ifndef DREAMPUFF_VIDEO_H
#define DREAMPUFF_VIDEO_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#include "dreampuff_json.h"
#if CNO_HAVE_UTF8
#include "utf8.h"
#endif //CNO_HAVE_UTF8

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

cno_object_type RenderList;
/*{"layer":{1,
	"blits":[
		{"type": point/line/rect/image,
		"x1": x
		"y1": y
		if(line or rect)
		"x2": w
		"y2": h
		if(texture)
		"clip":
		"rotation": rot
		"scale": 
		"reversed": 
		"inverted":
		"colourmod"}*/

cno_u8_type DreamPuff_Video_Init();
cno_u8_type DreamPuff_Video_LoadTexture(cno_cstring_type filename);
//cno_u8_type DreamPuff_Video_LoadFont(cno_cstring_type filename, cno_u16_type size);
cno_u8_type DreamPuff_Video_Render();
cno_u8_type DreamPuff_Video_SaveScreenshot();
cno_u8_type DreamPuff_Video_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_VIDEO_H
