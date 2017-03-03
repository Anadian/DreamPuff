//dreampuff_actions.c

#include "dreampuff_actions.h"

#include "cno_config.h"
#include "cno_log.h"

#include "dreampuff_input.h"
#include "dreampuff_mutex.h"

#if C\H\PARSON
#include "parson.h"
#endif //C\H\PARSON
#if CNO_HAVE_STRETCHYBUFFER
#include "stretchy_buffer.h"
#endif //CNO_HAVE_STRETCHYBUFFER
#if CNO_HAVE_STRING
#include "string.h"
#endif //CNO_HAVE_STRING

c\u8\ty DP\ActionPad_Init(){
	DP\ActionPads = NULL;
	
	
cno_u8_type DreamPuff_Actions_Update(){
#if CNO_HAVE_STRETCHYBUFFER
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Actions_Mutex);
	cno_u8_type i,j,k;
	for(i = 0; i < sb_count(DreamPuff_ActionPads); i++){
		for(j = 0; j < NumberofDreamPuff_Actions; j++){
			if(DreamPuff_ActionPads[i].actionstates[j] > 0) DreamPuff_ActionPads[i].actionstates[j]++;
			else if(DreamPuff_ActionPads[i].actionstates[j] < 0) DreamPuff_ActionPads[i].actionstates[j]--;
		}
	}
	if(DreamPuff_Events != NULL){
		for(i = 0; i < sb_count(DreamPuff_Events); i++){
			for(j = 0; j < sb_count(DreamPuff_ActionPads); j++){
				for(k = 0; k < NumberofDreamPuff_Actions; k++){
					if( (DreamPuff_ActionPads[j].actioncodes[k].primaryenabled && (CNO_strcmp(DreamPuff_ActionPads[j].actioncodes[k].primarycode, DreamPuff_Events[i].code) == 0)) || (DreamPuff_ActionPads[j].actioncodes[k].secondaryenabled && (CNO_strcmp(DreamPuff_ActionPads[j].actioncodes[k].secondarycode, DreamPuff_Events[i].code) == 0)) || (DreamPuff_ActionPads[j].actioncodes[k].tertiaryenabled && (CNO_strcmp(DreamPuff_ActionPads[j].actioncodes[k].tertiarycode, DreamPuff_Events[i].code) == 0)) ){
						DreamPuff_ActionPads[j].actionstates[k] = DreamPuff_Events[i].value;
					}
				}
			}
		}
		sb_free(DreamPuff_Events);
		DreamPuff_Events = NULL;
	}		
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Actions_Mutex);
	return 1;
#endif //CNO_HAVE_STRETCHYBUFFER
	return 0;
}
cno_s32_type DreamPuff_Actions_GetState(cno_u8_type actionpad, DreamPuff_Action_Name_type actionname){
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Actions_Mutex);
	cno_s32_type returnvalue;
	returnvalue = DreamPuff_ActionPads[actionpad].actionstates[actionname];
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Actions_Mutex);
	return returnvalue;
}
