//dreampuff_profile.c

#include "dreampuff_profile.h"

#include "cno_config.h"
#include "cno_log.h"
#include "cno_time.h"

#if CNO_HAVE_STRING
#include <string.h> //strcat
#endif //CNO_HAVE_STRING
#if CNO_HAVE_PARSON
#include "parson.h"
#endif //CNO_HAVE_PARSON
#if CNO_HAVE_ERRNO
#include <errno.h>
#endif //CNO_HAVE_ERRNO

cno_u8_type DreamPuff_Profile_Load(cno_cstring_type filename){
#if CNO_HAVE_STDIO
	cno_log(3,"Loading profile %s", filename);
	cno_file_type profile;
	profile = CNO_fopen(filename, "r+");
	if(profile != NULL){
		//dostuff
		return 1;
	} else{
		cno_log(2,"Error loading profile: %s", filename);
#if CNO_HAVE_ERRNO
		cno_log(2,"Errno %d", errno);
#endif //CNO_HAVE_ERRNO
	}
#endif //CNO_HAVE_STDIO
	return 0;
}
cno_u8_type DreamPuff_Profile_New(cno_utf8_type name){
#if CNO_HAVE_UUID
	CNO_uuid_generate(&(DreamPuff_Profile.uuid));
#if CNO_HAVE_UTF8
	utf8cpy(DreamPuff_Profile.name,name);
#if CNO_HAVE_STRING
	CNO_strcpy(DreamPuff_Profile.filename,name);
	CNO_strcat(DreamPuff_Profile.filename,".dpp");
	CNO_Time_Full(DreamPuff_Profile.creationtime);
	cno_log(2,"Creating profile %s (%d: %s) at %s", DreamPuff_Profile.name, DreamPuff_Profile.uuid, DreamPuff_Profile.filename, DreamPuff_Profile.creationtime);
	return 1;
#endif //CNO_HAVE_STRING
#endif //CNO_HAVE_UTF8
#endif //CNO_HAVE_UUID
	return 0;
}
