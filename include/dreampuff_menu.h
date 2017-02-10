//dreampuff_menu.h

#ifndef DREAMPUFF_MENU_H
#define DREAMPUFF_MENU_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_UTF8
#include "utf8.h"
#endif //CNO_HAVE_UTF8
#if CNO_HAVE_PARSON
#include "parson.h"
#endif //CNO_HAVE_PARSON

/*typedef struct DreamPuff_MenuEntry_struct{
	cno_utf8_type title;
	cno_u8_type locked;
	cno_u8_type hidden;
	cno_utf8_type description;
	cno_utf8_type lockeddescription;
	cno_cstring_type function;
} DreamPuff_MenuEntry\t;

typedef struct DreamPuff_Menu_struct{
	cno_utf8_type title;
	cno_u16_type numberofentries;
	DreamPuff_MenuEntry\t *entry;
} DreamPuff_Menu\t;*/

JSON_Object *DreamPuff_Menu;

cno_u8_type DreamPuff_Menu_Load(cno_cstring_type menufilename);
	

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_MENU_H
