#include <stdlib.h> //exit, atexit
#include <stdio.h>
/*#include <string.h>
#include <getopt.h> //getopt_long*/

#include "cno.h"
#include "cno_options.h"
#include "cno_config.h"
#include "dreampuff.h"
/*#include "test.h"
#include "configuration.h"
#include "delog.h"
#include "actions.h"
#include "middleware.h"
#include "state.h"
#include "unit.h"
#include "kairos.h"
#include "input.h"
#include "video.h"
#include "logic_main.h"*/


int main(int argc, char *argv[]){
	CNO_Init();
	CNO_Options_GetOpt(argc, argv);
	CNO_LowLevelConfig_Init();
	DreamPuff_Init();
	
	
	/*int i;
	for(i = 0; i < Numberofmutexes; i++){
		CreateMutex(i)
	}
	CreateNewLog();
	InitMiddleWare();

	InitVideo();
	InitInput();

#if USE_GLFW3
	//Init GLFW3
	glfwInit();
	int major, minor, revision;
	glfwGetVersion(&major,&minor,&revision);
	printl(1, "GLFW: %d.%d.%d (compiled) %d.%d.%d (linked)\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION, major, minor, revision);
#elif USE_ALLEGRO5
	//Init Allegro5
	al_init();
	printl(1, "Allegro: %d", ALLEGRO_VERSION_INT);
#endif
	//Init Custom Code
	CriticalVariables.AppRunning = 1;
	CriticalVariables.MainThread = 0;
	CriticalVariables.LogicThread = 0;
	
	Thread_type LogicThread;
	LogicThread = CreateThread(LogicThread,LogicMain)
	
	int font;
	font = LoadFont("Resources/FSMR.ttf", 16);
	int image;
	image = LoadImage("Resources/C3P1.png");
	
	CriticalVariables.MainFrame = 0;
	CriticalVariables.MainThread = 1;
	Timer_type FrameTimer;
	while(CriticalVariables.AppRunning == 1){
		printl(5, "MainFrame: %d Split: %d FPS: %f", CriticalVariables.MainFrame, CriticalVariables.MainSplit, (float)(1000/((CriticalVariables.MainSplit>0)?CriticalVariables.MainSplit:1)));
		ResetTimer(&FrameTimer);
		//usleep(2000000);
		//Input (input/video thread)
		Input();
		//printf("Point.x:%f Point.y:%f Point.z:%f\n", Points.pos.x, Points.pos.y, Points.pos.z);
		//Logic (logic/player thread)
		//Video (input/video thread)
		LockMutex(BlitsMutex)
		ClearBlits();
		AddBlit(image, 0, 0, 0, 0, 0);
		UnlockMutex(BlitsMutex)
		Video();
		//FileIO (fileIO thread)
		//State (logic/player thread)
		CriticalVariables.MainFrame++;
		CriticalVariables.MainSplit = GetTicks(&FrameTimer);
	}
	printf("Exiting cleanly.\n");
	
	JoinThread(LogicThread)
	
	ClearBlits();
	ClearFonts();
	ClearImages();
	QuitInput();
	QuitVideo();
	QuitMiddleWare();
	//SaveConfiguration("current.ini");

#if USE_GLFW3
	glfwTerminate();
#endif// 
// 	lua_close(L);
	QuitDelog();
	for(i = 0; i < Numberofmutexes; i++){
		DestroyMutex(i)
	}
	
	CriticalVariables.MainThread = 2;*/
	C\printf("Main thread terminating\n");
	
	exit(EXIT_SUCCESS);
}
