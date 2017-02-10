#include <stdlib.h> //exit, atexit
#include <stdio.h>
/*#include <string.h>
#include <getopt.h> //getopt_long*/

#include "cno.h"
#include "cno_options.h"
#include "cno_config.h"
#include "dreampuff.h"

int main(int argc, char *argv[]){
	CNO_Init();
	CNO_Options_GetOpt(argc, argv);
	CNO_LowLevelConfig_Init();
	DreamPuff_Init();
	
	while(DreamPuff_Engine_IsRunning()){
		DreamPuff_Input();
		DreamPuff_Net();
		DreamPuff_Logic();
		DreamPuff_FileIO();
		DreamPuff_Video();
		DreamPuff_Audio();
	}
	
	DreamPuff_Quit();
	CNO_printf("Main thread terminating\n");
	
	exit(EXIT_SUCCESS);
}
