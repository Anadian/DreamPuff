//cno_log.c

#include "cno_log.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //sprintf, f*,
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STRING
#include <string.h> //strcat, strcpy
#endif //CNO_HAVE_STRING
#if CNO_HAVE_ERRNO
#include <errno.h> //errno
#endif //CNO_HAVE_ERRNO

// #include "cno_build_info.h"
// #include "cno_time.h"
// 
// #if CNO_LOG_ENGINE == CNO_LOG_ENGINE_ORIGINAL
// #include "cno_config.h"
// 
// cno_u8_type CNO_GlobalLog(cno_cstring_type function, cno_cstring_type format, ...){
// #if CNO_HAVE_STDARG && CNO_HAVE_STRING
// 	if(CNO_LowLevelConfig.debug.enabled){
// 		cno_va_list_type args;
// 		CNO_va_start(args, format);
// 		cno_u8_type buffer[CNO_LowLevelConfig.debug.logmessagebuffersize];
// 		CNO_strcpy(buffer, function);
// 		//CNO_printf("%s, %s\n", buffer, function);
// 		CNO_strcat(buffer, ": ");
// 		cno_u8_type subbuffer[CNO_LowLevelConfig.debug.logmessageargumentbuffersize];
// 		cno_u16_type i;
// 		i = 0;
// 		while(format[i] != '\0'){
// 			//CNO_printf("%c \n", format[i]);
// 			if(format[i] == '%'){
// 				i++;
// 				switch(format[i]){
// 					case 'd':{
// 						int d = CNO_va_arg(args,int);
// 						CNO_sprintf(subbuffer, "%d", d);
// 						CNO_strcat(buffer, subbuffer);
// 						break;
// 					}
// 					case 'c':{
// 						char c = CNO_va_arg(args,char);
// 						CNO_sprintf(subbuffer, "%c", c);
// 						CNO_strcat(buffer, subbuffer);
// 						break;
// 					}
// 					case 's':{
// 						char *string = va_arg(args,char*);
// 						CNO_strcat(buffer, string);
// 						break;
// 					}
// 					case 'f':{
// 						double f = va_arg(args,double);
// 						CNO_sprintf(subbuffer, "%lf", f);
// 						CNO_strcat(buffer, subbuffer);
// 						break;
// 					}
// 					case '%':{
// 						CNO_strcat(buffer, "%");
// 						break;
// 					}
// 					default:
// 						CNO_strcat(buffer, format[i]);
// 						break;
// 				}
// 			} else{
// 				CNO_sprintf(subbuffer, "%c", format[i]);
// 				CNO_strcat(buffer, subbuffer);
// 			}
// 			i++;
// 		}
// 		CNO_va_end(args);
// 		if(CNO_LowLevelConfig.debug.standardoutput) CNO_printf("%s\n", buffer);
// 		CNO_strcat(buffer, "\n");
// #if CNO_HAVE_STDIO
// 		if(CNO_LowLevelConfig.debug.file){
// 			cno_file_type globallog;
// 			globallog = CNO_fopen(CNO_LowLevelConfig.debug.filename, "a");
// 			if(globallog != NULL){
// 				CNO_fputs(buffer, globallog);
// 				CNO_fclose(globallog);
// 				return 1;
// 			} 
// 			else{
// 				CNO_printf("Couldn't open log.");
// #if CNO_HAVE_ERRNO
// 				CNO_printf(" (errno: %d)", errno);
// #endif //CNO_HAVE_ERRNO
// 				CNO_printf("\n");
// 			}
// 		}
// #endif //CNO_HAVE_STDIO
// 	}
// #endif //CNO_HAVE_STDARG && CNO\HAVE_STRING
// 	return 0;
// }
// 
// cno_u8_type CNO_NewGlobalLog(){
// #if CNO_HAVE_STDIO
// 	if(CNO_LowLevelConfig.debug.enabled && CNO_LowLevelConfig.debug.file){
// 		cno_file_type globallog;
// 		globallog = CNO_fopen(CNO_LowLevelConfig.debug.filename, "w");
// 		if(globallog != NULL){
// 			CNO_fputs(CNO_Build_String, globallog);
// 			CNO_fputs("\n", globallog);
// 			cno_u8_type buffer[64];
// 			CNO_Time_Full(buffer);
// 			CNO_fputs(buffer, globallog);
// 			CNO_fputs("\n", globallog);
// 			CNO_fclose(globallog);
// 			return 1;
// 		}
// 		else{
// 			CNO_printf("Couldn't open log.");
// #if CNO_HAVE_ERRNO
// 			CNO_printf(" (errno: %d)", errno);
// #endif //CNO_HAVE_ERRNO
// 			CNO_printf("\n");
// 		}
// 	}
// #endif //CNO_HAVE_STDIO
// 	return 0;
// }
// #else
// cno_u8_type CNO_Log_Init() return 0;
// cno_u8_type CNO_Log_Quit() return 0;
// #endif //CNO_LOG_ENGINE

cno_u8_type CNO_Log_OpenFile_private(cno_file_type *filehandle, CNO_Log_type *log);
cno_u8_type CNO_Log_CloseFile_private(CNO_Log_type *log);

cno_u8_type CNO_Log_Init(/*CNO_Log_type *log, CNO_Log_Priority_type verbosity, cno_u8_type colour, cno_u8_type stream, cno_cstring_type filename*/){
	cno_u8_type _return;
#if CNO_LOG_ENGINE == CNO_LOG_ENGINE_STDIO && !defined(CNO_NO_GLOBAL_STATE)
#if CNO_THREAD_ENGINE != CNO_THREAD_ENGINE_NONE
	CNO_Mutex_Lock(&CNO_Log_Mutex);
#endif //CNO_THREAD_ENGINE != CNO_THREAD_ENGINE_NONE
	CNO_GlobalLog = {verbosity = 5, colour = 1, stream = 2, file = NULL, persist = 0,  overwrite = 0};
	
#else
	_return = 0;
#endif //CNO_LOG_ENGINE == CNO_LOG_ENGINE_STDIO && !defined(CNO_NO_GLOBAL_STATE)
	return _return;
}
cno_u8_type CNO_Log_Set(CNO_Log_type *log, CNO_Log_type value){
	cno_u8_type _return;
#if CNO_LOG_ENGINE == CNO_LOG_ENGINE_STDIO
	CNO_Mutex_Create*log
	*log = value;
	
	
	
