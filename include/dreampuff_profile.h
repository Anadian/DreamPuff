//dreampuff_profile.h

#ifndef DREAMPUFF_PROFILE_H
#define DREAMPUFF_PROFILE_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_UTF8
#include "utf8.h"
#endif //CNO_HAVE_UTF8
#if CNO_HAVE_UUID
#include <uuid/uuid.h>
#endif //CNO_HAVE_UUID
#if CNO_HAVE_PARSON
#include "parson.h"
#endif //CNO_HAVE_PARSON

typedef struct DreamPuff_Profile_struct{
	cno_uuid_type uuid;
	cno_utf8_type name;
	cno_cstring_type filename;
	cno_u64_type creationtime;
	cno_u64_type lastsavetime;
	
	//stats
	//configuration
	//account
} DreamPuff_Profile_type;

DreamPuff_Profile_type DreamPuff_Profile;

cno_u8_type DreamPuff_Profile_Load(cno_cstring_type filename);
cno_u8_type DreamPuff_Profile_Save(cno_cstring_type filename);
cno_u8_type DreamPuff_Profile_New(cno_utf8_type name);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_PROFILE_H
