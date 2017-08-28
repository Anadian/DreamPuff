/**
*	@file cno_string.h
*	@brief A wrapper around standard and non-standard string library functions.
*	@author Anadian
*	@copyright MIT License
*/
#ifndef CNO_STRING_H
#define CNO_STRING_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if C\H\UTF8
#include "utf8.h"
#elif C\H\STRING
#include <string.h>
#endif //C\H\STRING

c\u8\ty CNO_String_Copy(c\cstring\ty destination, c\cstring\ty source);
#define CNO_strcpy(...) CNO_String_Copy(__VA_ARGS__)
c\u8\ty CNO_String_Concatenate(c\cstring\ty destination, c\cstring\ty source);
#define CNO_strcat(...) CNO_String_Concatenate(__VA_ARGS__)
c\u8\ty CNO_String_Length(c\cstring\ty string, c\u32\ty *length)
#define CNO_strlen(...) CNO_String_Length((c\cstring\ty string, c\u32\ty *length)
c\u8\ty CNO_String_Match(c\cstring\ty string1, c\cstring\ty string2);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_STRING_H
