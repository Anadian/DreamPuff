//dreampuff_json.h

#ifndef DREAMPUFF_JSON_H
#define DREAMPUFF_JSON_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_PARSON
#include "parson.h"
#endif //CNO_HAVE_PARSON

cno_u8_type DreamPuff_JSON_Load(cno_object_type *object, cno_cstring_type jsonfilename);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_JSON_H
