//dreampuff_json.c

#include "dreampuff_json.h"

#include "cno_config.h"
#include "cno_log.h"

cno_u8_type DreamPuff_JSON_Load(cno_object_type *object, cno_cstring_type jsonfilename){
#if CNO_HAVE_PARSON
	cno_value_type rootvalue;
	rootvalue = json_parse_file_with_comments(jsonfilename);
	if(rootvalue != NULL){
		*object = json_value_get_object(rootvalue);
		return 1;
	}
#endif //CNO_HAVE_PARSON
	return 0;
}
