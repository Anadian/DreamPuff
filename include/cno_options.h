//cno_options.h

#ifndef CNO_OPTIONS_H
#define CNO_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_OPTIONS_ENGINE == CNO_OPTIONS_ENGINE_GETOPT

typedef enum CNO_Option_Arguments_enum{
	CNO_Option_Arguments_None=0,
	CNO_Option_Arguments_Required,
	CNO_Option_Arguments_Optional,
	NumberofCNO_Option_Arguments
} CNO_Option_Arguments_type;
typedef struct CNO_Option_struct{
	cno_cstring_type name;
	cno_u8_type value;
	CNO_Option_Arguments_type arguments; 
	cno_cstring_type hint;
	cno_cstring_type description;
	cno_u8_type hits;
	cno_cstring_type *argument;
} CNO_Option_type;

static CNO_Option_type CNO_Options[] = {
		{"version",'V',CNO_Option_Arguments_None,"\0","Display version information.",0,NULL},
		{"help",'h',CNO_Option_Arguments_None,"\0","Display this help text.",0,NULL},
		{"verbose",'v',CNO_Option_Arguments_Optional,"UINT:0-5","Sets debug verbosity to the given unsigned integer: 0 being silent; 5 being maximum logging.",0,NULL},
		{"all", 'a', CNO_Option_Arguments_None,"\0","Acknowledge invisible files",0,NULL},
		{"ansi",'A',CNO_Option_Arguments_None,"\0","Use ANSI/xterm text colouring.",0,NULL},
		{"aboutbackground",'b',CNO_Option_Arguments_None,"\0","Display information about background process.",0,NULL},
		{"startbackground",'B',CNO_Option_Arguments_None,"\0","Start background process (daemon).",0,NULL},
		{"configuration",'c',CNO_Option_Arguments_None,"\0","Print configuration information and exit.",0,NULL},
		{"configfile",'C',CNO_Option_Arguments_Required,"FILE","Use the given file for configuration.",0,NULL},
		{"debug",'d',CNO_Option_Arguments_None,"\0","More debug stuff.",0,NULL},
		{"dryrun",'D',CNO_Option_Arguments_None,"\0","Describe what this software would do, and what files it would change, without actually doing or changing anything.",0,NULL},
		{"error",'e', CNO_Options_Arguments_Required,"STREAM","Redirect stderr to the given stream; exempli gratia, STDOUT or a the name of a file.",0,NULL},
		{"force",'f',CNO_Option_Arguments_None,"\0","Harness an energy which flows through the universe in order to do things without asking the user for permission.",0,NULL},
		{"fail",'F',CNO_Option_Arguments_None,"\0","Don't take rejection so easily: exit at the first sign of something being wrong.",0,NULL},
		{"gui",'g',CNO_Option_Arguments_Optional,"\0","Opens a window; good for letting the air out.",0,NULL},
		{"interactive",'i',CNO_Option_Arguments_None,"\0","Offloads all the hard decision making onto the user.",0,NULL},
		{"input",'I',CNO_Option_Arguments_Required,"FILE","Uses the given file instead of STDIN.",0,NULL},
		{"stopbackground",'k',CNO_Option_Arguments_None,"\0","Politely stop the background process (daemon).",0,NULL},
		{"killbackground",'K',CNO_Option_Arguments_None,"\0","Forcefully terminate the background process (daemon); in essence: kill it!",0,NULL},
		//{"long",'l',CNO_Option_Arguments_Optional,"\0","List?",0,NULL},
		{"newdefaults",'n',CNO_Option_Arguments_None,"\0","Create new default files.",0,NULL},
		{"stdout",'o',CNO_Option_Arguments_Required,"STREAM","STDOUT, STDERR, FILE, or /dev/null: oh, so many choices.",0,NULL},
		{"output",'O',CNO_Option_Arguments_Required, "FILE","Tells the program to \"put out\" to the given file: whatever that means.",0,NULL},
		{"preprocess",'p',CNO_Option_Arguments_None,"\0","But where's postprocess?",0,NULL},
		{"prefix",'P',CNO_Option_Arguments_Required,"DIRECTORY","Adds the given directory to the list of directories which contain directories, each containing list of directories to be searched to find files which list where to find the directories containing the needed files.",0,NULL},
		{"quiet",'q',CNO_Option_Arguments_None,"\0","... please.",0,NULL},
		{"silence",'s',CNO_Option_Arguments_None,"\0","Tells the software to shut up! Doubly redundant since \"-v 0\" and \"-q\" both get the same result.",0,NULL},
		{"source",'S',CNO_Option_Arguments_Required,"FILE","Reluctantly obeys the orders contained in the given file.",0,NULL},
		{"tell",'t',CNO_Option_Arguments_None,"\0","Will try to talk to you more.",0,NULL},
		{"user",'u',CNO_Option_Arguments_Required,"USERNAME", "Exempli gratia: local user -> \"luser\".",0,NULL},
		{"update",'U',CNO_Option_Arguments_None,"\0","Breaks things.",0,NULL},
		{"execute",'x',CNO_Option_Arguments_Required,"COMMAND","Kills the given commanding officer.",0,NULL},
		{"exact",'X',CNO_Option_Arguments_Required,"Whaaaa?","Does something VERY specific: we just don't know what.",0,NULL},
		{"yes",'y',CNO_Option_Arguments_None,"\0","Impersonates Jim Carrey's character in the movie Yes Man.",0,NULL},
};
#endif //CNO_ALLOW_OPTIONS

c\u8\ty CNO_Options_Init();
cno_s8_type CNO_Options_Process(int argc, char *argv[]);
c\u8\ty C\Options_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_OPTIONS_H
