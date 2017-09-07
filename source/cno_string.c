/**
*	@file source/cno_string.c
*	@author Anadian
*	@copyright MIT License:
	Copyright 2017 Canosw
	Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so, subject to the following 
conditions:
	The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "cno_string.h"

#if CNO_HAVE_UTF8
#include "utf8.h"
#elif CNO_HAVE_STRING
#include <string.h>
#endif //CNO_HAVE_UTF8

cno_u8_type CNO_String_Concatenate(cno_string_type *destination, cno_string_type source){
#if CNO_HAVE_UTF8
	utf8cat((*destination), source);
	return 1;
#elif CNO_HAVE_STRING
	strcat((*destination), source);
	return 1;
#else
	return 0;
#endif //CNO_HAVE_UTF8
}
cno_u8_type CNO_String_Copy(cno_string_type *destination, cno_string_type source){
#if CNO_HAVE_UTF8
	utf8cpy((*destination), source);
	return 1;
#elif CNO_HAVE_STRING
	strcpy((*destination), source);
	return 1;
#else
	return 0;
#endif //CNO_HAVE_UTF8
}
cno_size_type CNO_String_Length(cno_string_type string){
#if CNO_HAVE_UTF8
	return utf8len(string);
#elif CNO_HAVE_STRING
	return strlen(string);
#else
	return 0;
#endif //CNO_HAVE_UTF8
}
cno_u8_type CNO_String_Match(cno_string_type string1, cno_string_type string2){
	cno_u8_type _return;
	cno_s32_type cmp_return;
#if CNO_HAVE_UTF8
	cmp_return = utf8cmp(string1, string2);
#elif CNO_HAVE_STRING
	cmp_return = strcmp(string1, string2);
#else
	cmp_return = -1;
#endif //CNO_HAVE_UTF8
	if(cmp_return == 0){
		_return = 1;
	} else{
		_return = 0;
	}
	return _return;
}
