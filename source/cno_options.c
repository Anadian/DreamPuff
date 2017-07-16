//cno_options.c
#include "cno_options.h"

//#if CNO_ALLOW_OPTIONS

#include "cno_build_info.h"

#if CNO_HAVE_STRING
#include <string.h> //strcpy
#endif //CNO_HAVE_STRING
#if CNO_HAVE_STDIO
#include <stdio.h> //printf
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STDLIB
#include <stdlib.h> //exit, atoi
#endif //CNO_HAVE_STDLIB

#if (CNO_OPTIONS_ENGINE == CNO_OPTIONS_ENGINE_GETOPT) && CNO_HAVE_GETOPT
#include <getopt.h> //getopt_long

cno_s8_type CNO_Options_GetOpt(int argc, char *argv[]){
	char c;
	int long_option_index;
	long_option_index = 0;
	
	while( ((c = getopt_long(argc,argv,"Vhv::c:a:", CNO_GNU_Long_Options, &long_option_index)) != -1) && (c != 255)){
	
#if CNO_ALLOW_PRINTF
		CNO_printf("%d: %c \n", long_option_index, c);
#endif //CNO_ALLOW_PRINTF

		switch(c){
			case 'V':
#if CNO_ALLOW_PRINTF
				CNO_printf("%s\n",CNO_Build_String);
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
				exit(EXIT_SUCCESS);				
#endif //CNO_ALLOW_EXIT
				break;
			case 'h':
#if CNO_ALLOW_PRINTF
				printf("Basic Usage:\n  %s [OPTIONS]\nOptions:  Note: (argument) means the argument(s) is/are optional while [argument] means the argument is required.\n", CNO_BUILD_NAME);
				int i;
				for(i = 0; i < (Number_of_CNO_Options); i++){
					CNO_printf("  %c, %s %s: %s\n", CNO_Options[i].val, CNO_Options[i].name, CNO_Options_Plus[i].hint, CNO_Options_Plus[i].description);
				}
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
				exit(EXIT_SUCCESS);
#endif //CNO_ALLOW_EXIT
				break;
			case 'v': 
				CNO_Options_Plus[CNO_Option_Verbose].flag = 1;
				CNO_Options_Argument_Verbose = (optarg == NULL)?(5):(atoi(optarg));
				break;
			case 'c':
				if(optarg == NULL){
#if CNO_ALLOW_PRINTF
					printf("Error '-c' invoked without an argument\n");
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
					exit(EXIT_FAILURE);
#endif //CNO_ALLOW_EXIT
				} else{
					CNO_Options_Plus[CNO_Option_Config].flag = 1;
					strcpy(CNO_Options_Argument_Config,optarg);
				}
				break;
			default:
#if CNO_ALLOW_PRINTF
				printf("Error %c not recognised as an option.", c);
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
				exit(EXIT_FAILURE);
#endif //CNO_ALLOW_EXIT
		}
	}
	return 0;
}
#elif CNO_HAVE_ARGP && (CNO_OPTIONS_ENGINE == CNO_OPTIONS_ENGINE_ARGP)
#include <argp.h> //argp_parse

error_t CNO_ARGP_Parser(int key, char *arg, struct argp_state *state){
	cno_u8_type numberofknownoptions;
	numberofknownoptions = (sizeof(CNO_Options) / sizeof(CNO_Option_type))
#if CNO_ALLOW_PRINTF
	CNO_printf("Number of known options: %d\n", numberofknownoptions);
#endif //CNO_ALLOW_PRINTF
	s8 success;
	success = 0;
	cno_u8_type i;
	for(i = 0; i < numberofknownoptions; i++){
		if(key == CNO_Options[i].value){
			CNO_Options[i].hits += 1;
			if( (CNO_Options[i].arguments == CNO_Option_Arguments_Required) || (CNO_Options[i].arguments == CNO_Option_Arguments_Optional) ){
#if CNO_HAVE_STRING
				CNO_strcpy(CNO_Options[i].argument,arg);
#endif //CNO_HAVE_STRING
			}
			success = key;
			i = numberofknownoptions;
		}
	}
	if(success == 0) return ARGP_ERR_UNKNOWN;
	else return success;
}
cno_u8_type CNO_Options_ARGP(int argc, char *argv[]){
	cno_u8_type numberofoptions;
	numberofoptions = (sizeof(CNO_Options) / sizeof(CNO_Option_type));
#if CNO_ALLOW_PRINTF
	CNO_printf("Number of known options: %d\n", numberofoptions);
#endif //CNO_ALLOW_PRINTF
	struct argp_option CNO_ARGP_Options[numberofoptions+1];
	cno_u8_type i;
	for(i = 0; i < numberofoptions; i++){
		CNO_ARGP_Options[i].name = CNO_Options[i].name;
		CNO_ARGP_Options[i].key = CNO_Options[i].value; 
		if(CNO_Options[i].arguments == CNO_Option_Arguments_Optional) CNO_ARGP_Options[i].flags = OPTION_ARG_OPTIONAL;
		else CNO_ARGP_Option[i].flags = 0;
		CNO_ARGP_Options[i].arg = CNO_Options[i].hint;
		CNO_ARGP_Options[i].doc = CNO_Options[i].description;
		CNO_ARGP_Options[i].group = 0;
	}
	struct argp CNO_ARGP;
	CNO_ARGP.options = CNO_ARGP_Options;
	CNO_ARGP.parser = CNO_ARGP_Parser;
	return argp_parse(&CNO_ARGP, argc, argv, 0, 0, 0);
}
#elif C\H\COMMANDER && (C\OPTIONS_ENGINE == C\OPTIONS_ENGINE_COMMANDER)
#include "commander.h"
c\u8\ty C\Options_Commander(int argc, char *argv[]){
	command_t commander;
	command_init(&commander, CNO_BUILD_NAME, CNO_Build_String);
	command_option(&commander,"-V","--version","Display version information.",NULL); //::0;
	//command_option(&commander,"-h","--help","Display this help text.",NULL); //::0;
	command_option(&commander,"-a","--all","Acknowledge invisible files",NULL); //::0;
	command_option(&commander,"-A","--ansi [boolean]","Boolean: Use ANSI/xterm text colouring.",NULL); //debug:ANSI_Text_Colouring:B?=true?|false!;
	command_option(&commander,"-b","--about-background","Display information about background process.",NULL); //::0;
	command_option(&commander,"-B","--start-background","Start background process (daemon).",NULL); //::0;
	command_option(&commander,"-c","--configuration","Print configuration information and exit.",NULL); //::0;
	command_option(&commander,"-C","--configfile <file>","File: Use the given file for configuration.",NULL); //::F!;
	command_option(&commander,"-D","--dryrun","Describe what this software would do, and what files it would change, without actually doing or changing anything.",NULL); //::0;
	command_option(&commander,"-f","--force","Harness an energy which flows through the universe in order to do things without asking the user for permission.",NULL); //::0;
	command_option(&commander,"-F","--fail","Don't take rejection so easily: exit at the first sign of something being wrong.",NULL); //::0;
	command_option(&commander,"-g","--gui","Opens a window; good for letting the air out.",NULL); //::0;
	command_option(&commander,"-G","--global-colours [boolean]","Use global terminal colour system.",NULL); //::B!;
	command_option(&commander,"-i","--interactive","Offloads all the hard decision making onto the user.",NULL); //::0;
	command_option(&commander,"-I","--input <file>","File: Uses the given file instead of STDIN.",NULL); //::F!;
	command_option(&commander,"-k","--stop-background","Politely stop the background process (daemon).",NULL); //::0;
	command_option(&commander,"-K","--kill-background","Forcefully terminate the background process (daemon); in essence: kill it!",NULL); //::0;
	command_option(&commander,"-l","--long","",NULL); //::0;
	command_option(&commander,"-L","--link <library>","Link a dynamic (.so) library; continues even if linking is unsuccessful.",NULL); //::F!;
	command_option(&commander,"-N","--newdefaults","Create new default files.",NULL); //::0;
	command_option(&commander,"-O","--output <file>","File: Tells the program to \'put out\' to the given file: whatever that means.",NULL); //::F!;
	command_option(&commander,"-p","--preprocess","But where's postprocess?",NULL); //::0;
	command_option(&commander,"-P","--prefix <directory>","Directory: Adds the given directory to the list of directories which contain directories, each containing list of directories to be searched to find files which list where to find the directories containing the needed files.",NULL); //::F!;
	command_option(&commander,"-q","--quiet","... please.",NULL); //::0;
	command_option(&commander,"-r","--recursive","Search directories recursively.",NULL); //::0;
	command_option(&commander,"-R","--require <library>","Link a dynamic (.so) library; exits if linking is unsuccessful.",NULL); //::F!;
	command_option(&commander,"-s","--silence","Tells the software to shut up! Doubly redundant since \'-v 0\' and \'-q\' both get the same result.",NULL); //::0;
	command_option(&commander,"-S","--source <file>","File:Reluctantly obeys the orders contained in the given file.",NULL); //::F!;
	command_option(&commander,"-t","--test","Run automated test.",NULL); //::0;
	command_option(&commander,"-u","--user <username>","Username: Exempli gratia: local user -> \'luser\'.",NULL); //::W!;
	command_option(&commander,"-U","--update","Breaks things.",NULL); //::0;
	command_option(&commander,"-x","--execute <command>","Command: Kills the given commanding officer.",NULL); //::D!;
	command_option(&commander,"-X","--exact <command>","Whaaaa?: Does something VERY specific: we just don't know what.",NULL); //::D!;
	command_option(&commander,"-y","--yes","Impersonates Jim Carrey's character in the movie Yes Man.",NULL); //::0;
	command_option(&commander,"-d","--debug [boolean]","Boolean: Enable debugging.",NULL); //debug:enabled:B?=true?|false!;
	command_option(&commander,"-v","--verbose [value]","Number: Sets debug verbosity to the given unsigned integer: 0 being silent; 5 being maximum logging. Defaults to 3, if omitted, and 5, if specified without an argument.",NULL); //debug:verbosity:N?=3!|5?|0-5;
	command_option(&commander,"-o","--stdout <file>","Stream: STDOUT, STDERR, FILE, or /dev/null: oh, so many choices.",NULL); //debug:standard_output:F!=STDOUT!;
	command_option(&commander,"-e","--error <file>","Stream: Redirect stderr to the given stream; exempli gratia, STDOUT or a the name of a file.",NULL); //debug:standard_error:F!=STDERR!;
	command_parse(&commander, argc, argv);
	command_free(&commander);
	return 0;
}
#endif //CNO_OPTIONS_ENGINE

cno_u8_type CNO_Options_Process(int argc, char *argv[]){
#if CNO_ALLOW_PRINTF
	cno_u8_type i;
	for(i = 0; i < argc; i++){
		CNO_printf("%d: %s\n", i, argv[i]);
	}
#endif //CNO_ALLOW_PRINTF
#if CNO_HAVE_GETOPT && (CNO_OPTIONS_ENGINE == CNO_OPTIONS_ENGINE_GETOPT)
	CNO_Options_GetOpt(argc, argv);
#elif CNO_HAVE_ARGP && (CNO_OPTIONS_ENGINE == CNO_OPTIONS_ENGINE_ARGP)
	CNO_Options_ARGP(argc, argv);
#elif C\H\COMMANDER && (CNO_OPTIONS_ENGINE == CNO_OPTIONS_ENGINE_COMMANDER)
	CNO_Options_Commander(argc, argv);
#else
	return 0;
#endif //CNO_OPTIONS
	return 1;
}
#endif //CNO_ALLOW_OPTIONS
