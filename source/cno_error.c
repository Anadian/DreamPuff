/**
*	@file source/cno_error.c
*	@brief Global error macros and definitions.
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

#include "cno_error.h"
#include "cno_time.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //fprintf
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_ERRNO
#include <errno.h> //errno
#endif //CNO_HAVE_ERRNO
#if CNO_HAVE_STRING
#include <string.h> //strerror
#endif //CNO_HAVE_STRING

cno_u8_type CNO_Error(cno_cstring_type function, cno_cstring_type message){
	cno_u8_type _return;
#if CNO_HAVE_STRING && CNO_HAVE_ERRNO && CNO_HAVE_STDIO
	fprintf(stderr, "Error: %s(%d): %s (errno: %d description: %s)\n", function, CNO_Time_Unix(), message, errno, strerror(errno));
#elif CNO_HAVE_ERRNO && CNO_HAVE_STDIO
	fprintf(stderr, "Error: %s(%d): %s (errno: %d)\n", function, CNO_Time_Unix(), message, errno);
#elif CNO_HAVE_STDIO
	fprintf(stderr, "Error: %s(%d): %s\n", function, CNO_Time_Unix(), message);
#endif //CNO_HAVE_STRING && CNO_HAVE_ERRNO && CNO_HAVE_STDIO
	
