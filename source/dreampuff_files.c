//dreampuff_files.c

#include "dreampuff_files.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_HAVE_TINYFILES
#define TINYFILES_IMPL
#include "tinyfiles.h"
#endif //CNO_HAVE_TINYFILES

cno_u8_type DreamPuff_Files_ListFiles(cno_object_type *list, cno_cstring_type directory){
#if CNO_HAVE_TINYFILES && CNO_HAVE_PARSON
	cno_directory_type dir;
	tfDirOpen(&dir,directory);
	cno_log(4, "%d %s %s", *list, "directorypath", dir.path);
	json_object_set_string(*list, "directorypath", dir.path);
	cno_value_type arrayvalue = json_value_init_array();
	cno_array_type array = json_value_get_array(arrayvalue);
	cno_u16_type i;
	i = 0;
	while(dir.has_next){
		cno_log(5,"%d",i++);
		cno_value_type filevalue = json_value_init_object();
		cno_object_type fileobject = json_value_get_object(filevalue);
		cno_tinyfile_type file;
		tfReadFile(&dir, &file);
		cno_log(5,"p: %s n: %s e: %s s: %d", file.path, file.name, file.ext, file.size);
		json_object_set_string(fileobject,"path",file.path);
		json_object_set_string(fileobject,"name",file.name);
		json_object_set_string(fileobject,"ext",file.ext);
		json_object_set_boolean(fileobject,"is_regular",file.is_reg);
		json_object_set_boolean(fileobject,"is_directory",file.is_dir);
		json_object_set_number(fileobject,"size",file.size);
		json_array_append_value(array,filevalue);
		tfDirNext(&dir);
	}
	tfDirClose(&dir);
	json_object_set_value(*list, "files", arrayvalue);
	cno_log(1,"%s",json_serialize_to_string(arrayvalue));
	return 1;
#endif //CNO_HAVE_TINYFILES
	return 0;
}
