/**
*	@file include/cno_application.h
*	@brief Globals pertaining to the application's state.
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

#ifndef CNO_APPLICATION_H
#define CNO_APPLICATION_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct CNO_Application_struct{
	cno_u8_type running;
	cno_u8_type awake;
	cno_u8_type focused;
	cno_u8_type initialized;
	cno_u8_type quit;
	cno_u32_type loops;
	cno_unixtime_type start_time;
	cno_cstring_type process_name;
	CNO_BuildInfo_type
	CNO_Evironment_type evironment;
}

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_APPLICATION_H