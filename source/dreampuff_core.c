//dreampuff_core.c

#include "dreampuff_core.h"

#include "cno_config.h"
#include "cno_log.h"

#include "dreampuff_middleware.h"
#include "dreampuff_video.h"
#include "dreampuff_input.h"
#include "dreampuff_threads.h"
#include "dreampuff_mutex.h"

#if 0 //filetest
#define DreamPuff_FILESTEST
#include "dreampuff_files.h"
#include "parson.h"
#endif 

DreamPuff_Engine_type DreamPuff_Engine;

cno_u8_type DreamPuff_Engine_IsRunning(){
	cno_u8_type rv;
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Engine_Mutex);
	rv = DreamPuff_Engine.running;
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Engine_Mutex);
	return rv;
}
cno_u8_type DreamPuff_Engine_IsSleeping(){
	cno_u8_type rv;
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Engine_Mutex);
	rv = DreamPuff_Engine.running;
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Engine_Mutex);
	return rv;
}	
cno_u8_type DreamPuff_Engine_Sleep(){
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Engine_Mutex);
	DreamPuff_Engine.sleeping = 1;
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Engine_Mutex);
	return 0;
}
cno_u8_type DreamPuff_Engine_Wake(){
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Engine_Mutex);
	DreamPuff_Engine.sleeping = 0;
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Engine_Mutex);
	return 0;
}
cno_u8_type DreamPuff_Engine_Stop(){
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Engine_Mutex);
	DreamPuff_Engine.running = 0;
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Engine_Mutex);
	return 0;
}
cno_u8_type DreamPuff_Init(){
	if(CNO_LowLevelConfig.debug.enabled){
		CNO_NewGlobalLog();
		cno_log(1, "Test %d %c %s %f", 234, 'a', "yo", 0.112);
	}
	DreamPuff_MiddleWare_Init();
	DreamPuff_Video_Init();
	DreamPuff_Engine.running = 1;
	DreamPuff_Engine.sleeping = 0;
	DreamPuff_Engine.mode = DreamPuff_Mode_Menu;
	DreamPuff_Threads_Init();
#ifdef DreamPuff_FILESTEST
	cno_value_type listvalue = json_value_init_object();
	cno_object_type list = json_value_get_object(listvalue);
	DreamPuff_Files_ListFiles(&list, "./");
#endif //DreamPuff_FILESTEST
	return 0;
}
cno_u8_type DreamPuff_Input(){
	return DreamPuff_Input_SDL();
}
cno_u8_type DreamPuff_Net(){
	return 0;
}
cno_u8_type DreamPuff_Logic(){
	//dp_log(1, "Yo from Main thread.");
	return 0;
}
cno_u8_type DreamPuff_FileIO(){
	return 0;
}
cno_u8_type DreamPuff_Video(){
	return 0;
}
cno_u8_type DreamPuff_Audio(){
	return 0;
}
cno_u8_type DreamPuff_Quit(){
	DreamPuff_Threads_Quit();
	DreamPuff_Video_Quit();
	DreamPuff_MiddleWare_Quit();
	return 0;
}
