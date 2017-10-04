/**
*	@file source/cno_version.h
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

#include "cno_version.h"
#include "semver.h"

c\u8\ty C\Version_Read(c\u16\ty *major, c\u16\ty *minor, c\u16\ty *patch, c\string\ty string){
	c\u8\ty _return = 0;
	semver_t version = {};
	if(semver_parse(string, &version) == 0){
		*major = (c\u8\ty)version.major;
		*minor = (c\u8\ty)version.minor;
		*patch = (c\u8\ty)version.patch;
		_return = 1;
	} else{
		_return = 0;
	}
	return _return;
}
c\u8\ty C\Version_Write(c\string\ty *string, c\u16\ty major, c\u16\ty minor, c\u16\ty patch){
	c\u8\ty _return = 0;
	semver_t version = {(int)major, (int)minor, (int)patch};
	if(semver_render(&version, string) == 0){
		