//cno_build_info.c

#include "cno_build_info.h"

#include "cno_build.h"

#if CNO_HAVE_STDIO
#include <stdio.h>//sprintf
#endif //CNO_HAVE_STDIO

cno_u8_type CNO_Build_Info_Init(){
#if CNO_HAVE_STDIO
	cno_sprintf(CNO_Build_String, "%s v%d.%d (%s %s, %s) %s %s %d", CNO_BUILD_NAME, CNO_BUILD_VERSION_MAJOR, CNO_BUILD_VERSION_MINOR, CNO_BUILD_DATE, CNO_BUILD_TIME, CNO_COMPILER_NAME, CNO_ARCHITECTURE_NAME, CNO_OS_NAME, CNO_DEVICE);
#if CNO_ALLOW_PRINTF
	cno_printf("%s\n",CNO_Build_String);
	//printf("%s v%d.%d (%s %s, %s) %s %s %d\n", CNO_BUILD_NAME, CNO_BUILD_VERSION_MAJOR, CNO_BUILD_VERSION_MINOR, CNO_BUILD_DATE, CNO_BUILD_TIME, CNO_COMPILER, CNO_ARCHITECTURE, CNO_OS_NAME, CNO_DEVICE_TYPE);
#endif //CNO_ALLOW_PRINTF
	return 1;
#endif //CNO_HAVE_STDIO
	return 0;
}
