//cno_options.c
#include "cno_options.h"

#if CNO_ALLOW_OPTIONS

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

#if (CNO_OPTIONS == CNO_OPTIONS_GETOPT) && CNO_HAVE_GETOPT
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
#elif CNO_HAVE_ARGP && (CNO_OPTIONS == CNO_OPTIONS_ARGP)
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
#endif //CNO_OPTIONS

cno_u8_type CNO_Options_Process(int argc, char *argv[]){
#if CNO_ALLOW_PRINTF
	cno_u8_type i;
	for(i = 0; i < argc; i++){
		CNO_printf("%d: %s\n", i, argv[i]);
	}
#endif //CNO_ALLOW_PRINTF
#if CNO_HAVE_GETOPT && (CNO_OPTIONS == CNO_OPTIONS_GETOPT)
	CNO_Options_GetOpt(argc, argv);
#elif CNO_HAVE_ARGP && (CNO_OPTIONS == CNO_OPTIONS_ARGP)
	CNO_Options_ARGP(argc, argv);
#else
	return 0;
#endif //CNO_OPTIONS
	return 1;
}
#endif //CNO_ALLOW_OPTIONS
