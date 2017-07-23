//cno_build_info.c

#include "cno_build_info.h"

#include "cno_build.h"

#if CNO_HAVE_STDIO
#include <stdio.h>//sprintf
#endif //CNO_HAVE_STDIO

cno_u8_type CNO_Build_Info_Init(){
#if CNO_HAVE_STDIO
	CNO_sprintf(CNO_Build_String, "%s v%d.%d (%s-%s-%s-%s-%s-%s)", CNO_BUILD_NAME, CNO_BUILD_VERSION_MAJOR, CNO_BUILD_VERSION_MINOR, CNO_BUILD_GOAL, CNO_BUILD_ARCHITECTURE, CNO_BUILD_SYSTEM, CNO_BUILD_COMPILER, CNO_BUILD_DATE, CNO_BUILD_COMMIT);
#if CNO_ALLOW_PRINTF
	CNO_printf("%s\n",CNO_Build_String);
#endif //CNO_ALLOW_PRINTF
	return 1;
#endif //CNO_HAVE_STDIO
	return 0;
}
