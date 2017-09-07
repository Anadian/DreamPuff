/**
*	@file source/cno_filebuffer.c
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
#include "cno_filebuffer.h"
#include "cno_filestream.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //fread, fwrite
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STDLIB
#include <stdlib.h> //calloc, free
#endif //CNO_HAVE_STDLIB

cno_u8_type CNO_Buffer_Read(cno_u8_type *buffer, cno_string_type filename){
	cno_filestream_type stream;
	cno_u8_type read_return = CNO_File_Read(&stream,filename);
	if(read_return == 1){
		cno_size_type file_size = sizeof(stream);
		cno_u8_type *allocated_space = calloc(file_size, sizeof(cno_u8_type));
		cno_size_type fread_return = 0;
		fread_return = fread(allocated_space, sizeof(cno_u8_type), file_size, stream);
		if(fread_return <= 0){
			return 0;
		}
		CNO_FileStream_Close(&stream);
		return allocated_space;
	}
	return 0;
}
cno_u8_type CNO_Buffer_Write(cno_buffer_type *buffer, cno_string_type filename){
	cno_filestream_type stream;
	if(CNO_File_Write(&stream, filename)){
		cno_size_type fwrite_return = 0;
		fwrite_return = fwrite(*buffer, sizeof(cno_u8_type), sizeof(*buffer), stream);
		if(fwrite_return == sizeof(*buffer)){
			_return = 1;
		} else{
			
			
		
