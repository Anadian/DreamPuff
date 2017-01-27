//cno_environment.c

#include "cno_environment.h"

#include "cno_build.h"
#include "cno_build_info.h"

#if CNO_HAVE_STDLIB
#include <stdlib.h> //getenv
#endif //CNO_HAVE_STDLIB

#if CNO_HAVE_STRING
#include <string.h> //strcpy
#endif //CNO_HAVE_STRING

#if CNO_HAVE_WHEREAMI
#include "whereami.h"
#endif // CNO_HAVE_WHEREAMI

#if CNO_HAVE_STDIO
#include <stdio.h>
#endif //CNO_HAVE_STDIO

cno_u8_type CNO_Environment_Init(){
#if CNO_HAVE_STDLIB && CNO_HAVE_STRING
	if(getenv("USER") != NULL) strcpy(&(CNO_Environment.username),getenv("USER"));
	else if(getenv("USERNAME") != NULL) strcpy(&(CNO_Environment.username),getenv("USERNAME"));
	else if(getenv("LOGNAME") != NULL) strcpy(&(CNO_Environment.username),getenv("LOGNAME"));
#if CNO_ALLOW_PRINTF
	printf("username: %s\n", CNO_Environment.username);
#endif //CNO_ALLOW_PRINTF
	if(getenv("HOSTNAME") != NULL) strcpy(&(CNO_Environment.hostname),getenv("HOSTNAME"));
#if CNO_ALLOW_PRINTF
	printf("hostname: %s\n", CNO_Environment.hostname);
#endif //CNO_ALLOW_PRINTF
	if(getenv("PWD") != NULL) strcpy(&(CNO_Environment.pwd),getenv("PWD"));
#if CNO_ALLOW_PRINTF
	printf("PWD: %s\n", CNO_Environment.pwd);
#endif //CNO_ALLOW_PRINTF
	if(getenv("HOME") != NULL) strcpy(&(CNO_Environment.home),getenv("HOME"));
#if CNO_ALLOW_PRINTF
	printf("home: %s\n", CNO_Environment.home);
#endif //CNO_ALLOW_PRINTF
#if CNO_HAVE_WHEREAMI
	wai_getExecutablePath(&(CNO_Environment.whereami), sizeof(CNO_Environment.whereami), NULL);
#endif //CNO_HAVE_WHEREAMI
#if CNO_ALLOW_PRINTF
	printf("whereami: %s\n", CNO_Environment.whereami);
#endif //CNO_ALLOW_PRINTF
	return 1;
#else
	return 0;
#endif //CNO_HAVE_STDLIB && CNO_HAVE_STRING
}
