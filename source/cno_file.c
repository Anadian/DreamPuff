//cno_file.c

#include "cno_file.h"

#if C\H\STDIO
#include <stdio.h> //f*
#endif //C\H\STDIO
#if C\H\ERRNO
#include <errno.h> //errno
#if C\H\STRING
#include <string.h> //strerror
#endif //C\H\STRING
#endif //C\H\ERRNO

c\u8\ty C\File_Open(c\file\ty *file, c\cstring\ty mode, c\cstring\ty filename){
	c\u8\ty _return;
#if C\H\STDIO
	FILE* filehandle;
	filehandle = fopen(filename, mode);
	if(filehandle != NULL){
		_return = 1;
		*file = filehandle;
	} else{
		_return = 0;
		//c\u8\ty message_buffer[CNO_BUFFER_MAXSIZE];
#if C\H\ERRNO && C\H\STRING
		fprintf(stderr, "Couldn't open file '%s': (mode: '%s' errno: %d description: '%s')\n", filename, mode, errno, strerror(errno));
#elif C\H\ERRNO
		fprintf(stderr, "Couldn't open file '%s': (mode '%s' errno: %d)\n", filename, mode, errno);
#else
		fprintf(stderr, "Couldn't open file '%s': (mode: '%s')\n", filename, mode);
#endif //C\H\ERRNO && C\H\STRING
	}
#else
	_return = 0;
#endif //C\H\STDIO
	return _return;
}
c\u8\ty C\File_Sync(c\file\ty *file){
	c\u8\ty _return;
#if C\H\STDIO
	int fflsuh_return;
	fflush_return = fflush(*file);
	if(fflush_return == 0){
		_return = 1;
	} else{
		_return = 0;
	}
#else
	_return = 0;
#endif //C\H\STDIO
	return _return;
}		
c\u8\ty C\File_Close(c\file\ty *file){
	c\u8\ty _return;
#if C\H\STDIO
	int fclose_return;
	fclose_return = fclose(*file);
	if(fclose_return == 0){
		_return = 1;
	} else{
		_return = 0;
	}
#else
	_return = 0;
#endif //C\H\STDIO
	return _return;
}
	