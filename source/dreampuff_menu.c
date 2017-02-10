//dreampuff_menu.c

#include "dreampuff_menu.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_HAVE_ERRNO
#include <errno.h>
#endif //CNO_HAVE_ERRNO

cno_u8_type DreamPuff_Menu_Load(cno_cstring_type menu){
#if CNO_HAVE_PARSON
	JSON_Value *rootvalue;
	cno_log(4, "Parsing %s", menu);
	rootvalue = json_parse_file_with_comments(menu);
	if(rootvalue != NULL){
		//JSON_Object *rootobject;
		DreamPuff_Menu = json_value_get_object(rootvalue);
		/*cno_cstring_type title;
		title = json_object_get_string(rootobject, "title");
		cno_u16_type numberofentries;
		numberofentries = json_object_get_number(rootobject, "numberofentries");
		JSON_Array *entries;
		entries = json_object_get_array(rootobject, "entries");
		cno_u16_type i;
		for(i = 0; i < numberofentries; i++){
			JSON_Object *entry;
			entry = json_array_get_object(entries, i);*/
		return 1;
	}
	cno_log(2,"Error: couldn't parse %s", menu);
#if CNO_HAVE_ERRNO
	cno_log(2,"errno %d", errno);
#endif //CNO_HAVE_ERRNO
#endif //CNO_HAVE_PARSON
	return 0;
}
			
