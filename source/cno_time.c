//cno_time.c: Time retieval functions

#include "cno_time.h"

#include "cno_build.h"

#if CNO_HAVE_STRING
#include <string.h> //strcpy, strcat
#endif //CNO_HAVE_STRING


#if CNO_HAVE_TIME
#include <time.h> //time, gmtime, strftime
#endif //CNO_HAVE_TIME

cno_time_type CNO_Time_Unix(){
#if CNO_HAVE_TIME
	return CNO_time(NULL);
#endif //CNO_HAVE_TIME
	return 0;
}

cno_u8_type CNO_Time_Calendar(cno_u8_type *buffer){
#if CNO_HAVE_TIME
	return strftime(buffer, sizeof(buffer), "%H%M%S", gmtime(CNO_Time_Unix()));
#endif //CNO_HAVE_TIME
	return 0;
}

cno_u8_type CNO_Time_Concise(cno_u8_type *buffer){
#if CNO_HAVE_TIME
	return strftime(buffer, sizeof(buffer), "%Y%m%dT%H%M%S", gmtime(CNO_Time_Unix()));
#endif //CNO_HAVE_TIME
	return 0;
}

cno_u8_type CNO_Time_Full(cno_cstring_type buffer){
#if CNO_HAVE_TIME && CNO_HAVE_STRING
	cno_time_type unixtime = CNO_time(NULL);
	cno_calendartime_type *calendartime = CNO_gmtime(&unixtime);
	cno_u8_type datebuffer[16];
	cno_u8_type timebuffer[16];
	cno_u8_type finalbuffer[32];
	CNO_strftime(datebuffer, sizeof(datebuffer), "%Y-%m-%d", calendartime);
	//CNO_printf("%s\n", datebuffer);
	CNO_strftime(timebuffer, sizeof(timebuffer), "%H:%M:%S", calendartime);
	//CNO_printf("%s\n", timebuffer);
	CNO_strcpy(finalbuffer, datebuffer);
	CNO_strcat(finalbuffer, "T");
	CNO_strcat(finalbuffer, timebuffer);
	CNO_strcat(finalbuffer, "Z");
	CNO_printf("%s\n", finalbuffer);
	CNO_strcpy(buffer, finalbuffer);
	return 1;
#endif //CNO_HAVE_TIME && CNO_HAVE_STRING
	return 0;
}
