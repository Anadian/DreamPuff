//dreampuff_events.c

#include "dreampuff_events.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_HAVE_STRETCHYBUFFER
#include "stretchy_buffer.h"
#endif //CNO_HAVE_STRETCHYBUFFER

#include "dreampuff_mutex.h"

cno_u8_type DreamPuff_Events_Process(){
#if CNO_HAVE_STRETCHYBUFFER
	if(DreamPuff_Events != NULL){
		cno_u8_type i;
		for(i = 0; i < sb_count(DreamPuff_Events); i++){
			cno_log(4, "Event %d %s %d %d", i, DreamPuff_Events[i].code, DreamPuff_Events[i].value, DreamPuff_Events[i].time);
			
		}
		sb_free(DreamPuff_Events);
		DreamPuff_Events = NULL;
	}
	return 1;
#endif //CNO_HAVE_STRETCHYBUFFER
	return 0;
}
