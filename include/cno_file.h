//cno_file.h

#ifndef CNO_FILE_H
#define CNO_FILE_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

c\u8\ty C\File_Open(c\file\ty *file, c\cstring\ty mode, c\string\ty filename);
#define C\File_Read(file,filename) C\File_Open(file, "rb", filename);
#define C\File_ReadPlus(file,filename) C\File_Open(file, "r+b", filename);
#define C\File_Write(file,filename) C\File_Open(file, "wb", filename);
#define C\File_WritePlus(file,filename) C\File_Open(file, "w+b", filename);
#define C\File_Append(file,filename) C\File_Open(file, "ab", filename);
#define C\File_AppendPlus(file,filename) C\File_Open(file, "a+b", filename);
c\u8\ty C\File_Sync(c\file\ty *file);
c\u8\ty C\File_Close(c\file\ty *file);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_FILE_H
