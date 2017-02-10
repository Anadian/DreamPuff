//dreampuff_files.h

#ifndef DREAMPUFF_FILES_H
#define DREAMPUFF_FILES_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_PARSON
#include "parson.h"
#endif //CNO_HAVE_PARSON

cno_u8_type DreamPuff_Files_ListFiles(cno_object_type *list, cno_cstring_type directory);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_FILES_H
