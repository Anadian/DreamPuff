//cno_options.h

#ifndef CNO_OPTIONS_H
#define CNO_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_GETOPT
#include "getopt.h"
typedef struct option CNO_GNU_Option_type;

typedef struct CNO_Option_struct{
	CNO_GNU_Option_type option;
	cno_cstring_type hint;
	cno_cstring_type description;
} CNO_Option_type;

static CNO_Option_type CNO_Options[] = {
		{{"version", no_argument, 0, 'V'}, "\0", "Display version information."},
		{{"help", no_argument, 0, 'h'}, "\0", "Display this help text."},
		{{"verbose", optional_argument, 0, 'v'}, "UINT:0-5", "Sets debug verbosity to the given unsigned integer: 0 being silent; 5 being maximum logging."},
		{{"ansi", no_argument, 0, 'a'}, "\0", "Use ANSI/xterm text colouring."},
		{{"aboutbackground", no_argument, 0, 'b'}, "\0", "Display information about background process."},
		{{"startbackground", no_argument, 0, 'B'}, "\0", "Start background process (daemon)."},
		{{"configuration", no_argument, 0, 'c'}, "\0", "Print configuration information and exit."},
		{{"configfile", required_argument, 0, 'C'}, "FILE", "Use the given file for configuration."},
		{{"debug", no_argument, 0, 'd'}, "\0", "More debug stuff."},
		{{"dryrun", no_argument, 0, 'D'}, "\0", "Describe what this software would do, and what files it would change, without actually doing or changing anything."},
		{{"force", no_argument, 0, 'f'}, "\0", "Harness an energy which flows through the universe in order to do things without asking the user for permission."},
		{{"fail", no_argument, 0, 'F'}, "\0", "Don't take rejection so easily: exit at the first sign of something being wrong."},
		{{"gui", optional_argument, 0, 'g'}, "\0", "Opens a window; good for letting the air out."},
		{{"interactive", no_argument, 0, 'i'}, "\0", "Offloads all the hard decision making onto the user."},
		{{"input", required_argument, 0, 'I'}, "FILE", "Uses the given file instead of STDIN."},
		{{"stopbackground", no_argument, 0, 'k'}, "\0", "Politely stop the background process (daemon)."},
		{{"killbackground", no_argument, 0, 'K'}, "\0", "Forcefully terminate the background process (daemon); in essence: kill it!"},
		{{"list", optional_argument, 0, 'l'}, "\0", "List?"},
		{{"newdefaults", no_argument, 0, 'n'}, "\0", "Create new default files."},
		{{"stdout", required_argument, 0, 'o'}, "STREAM", "STDOUT, STDERR, FILE, or /dev/null: oh, so many choices."},
		{{"output", required_argument, 0, 'O'}, "FILE", "Tells the program to \"put out\" to the given file: whatever that means."},
		{{"preprocess", no_argument, 0, 'p'}, "\0", "But where's postprocess?"},
		{{"prefix", required_argument, 0, 'P'}, "DIRECTORY", "Adds the given directory to the list of directories which contain directories, each containing list of directories to be searched to find files which list where to find the directories containing the needed files."},
		{{"silence", no_argument, 0, 's'}, "\0", "Tells the software to shut up! Redundant since \"-v 0\" gets the same result."},
		{{"source", required_argument, 0, 'S'}, "FILE", "Reluctantly obeys the orders contained in the given file."},
		{{"tell", no_argument, 0, 't'}, "\0", "Will try to talk to you more."},
		{{"user", required_argument, 0, 'u'}, "USERNAME", "Exempli gratia: local user -> \"luser\"."},
		{{"update", no_argument, 0, 'U'}, "\0", "Breaks things."},
		{{"execute", required_argument, 0, 'x'}, "COMMAND", "Kills the given commanding officer."},
		{{"exact", required_argument, 0, 'X'}, "Whaaaa?", "Does something VERY specific: we just don't know what."},
		{{"yes", no_argument, 0, 'y'}, "\0", "Impersonates Jim Carrey's character in the movie Yes Man."},
		//{"actions", required_argument, 0, 'a'},
		{{0,0,0,0}, "\0", "\0"}
};
/*
typedef enum CNO_Option_Flag_enum{
	CNO_Option_Version,
	CNO_Option_Help,
	CNO_Option_Verbose,
	CNO_Option_Config,
	//CNO_Option_Actions,
	Number_of_CNO_Options
} CNO_Option_Flag_type;

typedef struct CNO_Option_Plus_struct{
	CNO_Option_type option;
	cno_u8_type hint[16];
	cno_u8_type description[1024];
} CNO_Option_Plus_type;

cno_cstring_type CNO_Option_Flag_Verbose;
cno_cstring_type CNO_Option_Flag_Configfile;

CNO_Option_Plus_type CNO_Options_Plus[Number_of_CNO_Options];
*/
#endif //CNO_HAVE_GETOPT

cno_s8_type CNO_Options_GetOpt(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_OPTIONS_H
