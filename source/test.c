filecommenttm(source/test.c,)

#include "cno_build.h"
#include "cno_string.h"
#include "cno_filestream.h
#include "cno_time.h"

CSI(C\H\STDIO,<stdio.h>)

int main(int argc, char *argv[]){
	c\string\ty time_string = CNO_StringFromCurrent();
	c\filestream\ty filestream;
	CNO_FileStream_AppendPlus(filestream, "test.log");
	CNO_fprintf(filestream, "Time is %s\n", time_string);
	CNO_FileStream_Sync(filestream);
	CNO_FileStream_Close(filestream);
	return 0;
}