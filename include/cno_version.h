/**
*	@file include/cno_version.h
*	@brief 
*	@author Anadian
*	@license MIT License:
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

/*Build stages:
prepare compile assemble test document package link distribute report clean
*/

#ifndef CNO_VERSION_H
#define CNO_VERSION_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"
#include "cno_string.h"

cno_u8_type CNO_Version_Read(cno_u8_type *major, cno_u8_type *minor, cno_u8_type *patch, c\string\ty string);
cno_u8_type CNO_Version_Write(cno_string_type *string, c\u8\ty major, c\u8\ty minor, c\u8\ty patch);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_VERSION_H
