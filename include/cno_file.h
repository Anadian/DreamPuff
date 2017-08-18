/**
*	@file cno_filesystem.h
*	@brief Abstractions for reading and files, indexing directories, and interacting with archives.
*	@author Anadian
*	@copyright MIT License
*/

#ifndef CNO_FILESYSTEM_H
#define CNO_FILESYSTEM_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#include "cno_string.h"
#include "cno_json.h"

#if !defined(cno_filestream_type)
#define cno_filestream_type FILE* //cno_file_type is a macro not a typedef
#endif //cno_filestream_type

//Types:
//streams stdio.h
//buffers stdlib.h malloc and free
//directories parson and tinyfiles
//archives libarchive

cno_u8_type CNO_FileSystem_Stream_Open(cno_file_type *file, cno_cstring_type mode, cno_string_type filename);
#define CNO_File_Read(file,filename) CNO_FileSystem_OpenStream(file, "rb", filename);
#define CNO_File_ReadPlus(file,filename) CNO_FileSystem_OpenStream(file, "r+b", filename);
#define CNO_File_Write(file,filename) CNO_FileSystem_OpenStream(file, "wb", filename);
#define CNO_File_WritePlus(file,filename) CNO_FileSystem_OpenStream(file, "w+b", filename);
#define CNO_File_Append(file,filename) CNO_FileSystem_OpenStream(file, "ab", filename);
#define CNO_File_AppendPlus(file,filename) CNO_FileSystem_OpenStream(file, "a+b", filename);
cno_u8_type CNO_FileSystem_Stream_Sync(cno_file_type *file);
cno_u8_type CNO_FileSystem_Stream_Close(cno_file_type *file);
cno_u8_type CNO_FileSystem_Buffer_Read(c\u8\ty *buffer, c\cstring\ty filename);
c\u8\ty C\FS\Buffer_Write(c\u8\ty *buffer, c\cstring\ty filename);
c\u8\ty C\FS\Directory_JSON(cno_value_type *json_value, c\cstring\ty directoryname);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_FILE_H
