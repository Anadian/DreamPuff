//cno_file.h

#ifndef CNO_FILE_H
#define CNO_FILE_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

cno_u8_type CNO_File_Open(cno_file_type *file, cno_cstring_type mode, cno_string_type filename);
#define CNO_File_Read(file,filename) CNO_File_Open(file, "rb", filename);
#define CNO_File_ReadPlus(file,filename) CNO_File_Open(file, "r+b", filename);
#define CNO_File_Write(file,filename) CNO_File_Open(file, "wb", filename);
#define CNO_File_WritePlus(file,filename) CNO_File_Open(file, "w+b", filename);
#define CNO_File_Append(file,filename) CNO_File_Open(file, "ab", filename);
#define CNO_File_AppendPlus(file,filename) CNO_File_Open(file, "a+b", filename);
cno_u8_type CNO_File_Sync(cno_file_type *file);
cno_u8_type CNO_File_Close(cno_file_type *file);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_FILE_H
