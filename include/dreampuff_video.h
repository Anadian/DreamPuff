//dreampuff_video.h

#ifndef DREAMPUFF_VIDEO_H
#define DREAMPUFF_VIDEO_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#include "dreampuff_json.h"


DreamPuff_Object_type RenderList;
/*{"layer":{1,
	"blits":[
		{"type": point/line/rect/image,
		"x1": x
		"y1": y
		if(line or rect)
		"x2": w
		"y2": h
		if(texture)
		"rotation": rot
		"scale": 
		"reversed": 
		"inverted":
		"colourmod"}*/

cno_u8_type DreamPuff_Video_Init();
cno_u8_type DreamPuff_Video_LoadTexture(cno_cstring_type filename);
cno_u8_type DreamPuff_Video_LoadFont(cno_cstring_type filename, cno_u16\t size);
cno_u8_type DreamPuff_Video_SaveScreenshot();
cno_u8_type DreamPuff_Video_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_VIDEO_H
