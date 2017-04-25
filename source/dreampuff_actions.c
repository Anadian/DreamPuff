//dreampuff_actions.c

#include "dreampuff_actions.h"

#include "cno_config.h"
#include "cno_log.h"

#include "dreampuff_input.h" //DreamPuff_Events
#include "dreampuff_mutex.h"
#include "dreampuff_files.h"

#if CNO_HAVE_PARSON
#include "parson.h"
#endif //CNO_HAVE_PARSON
#if CNO_HAVE_STRETCHYBUFFER
#include "stretchy_buffer.h"
#endif //CNO_HAVE_STRETCHYBUFFER
#if CNO_HAVE_STRING
#include "string.h"
#endif //CNO_HAVE_STRING

cno_u8_type ActionPadDirectory[CNO_Filename_Size];

cno_u8_type DreamPuff_ActionPad_Default(cno_u8_type actionpad){
#if CNO_HAVE_STRING && CNO_HAVE_PARSON
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Actions_Mutex);
	cno_u8_type defaultactionpadpath[CNO_Filename_Size];
	CNO_strcpy(defaultactionpadpath,ActionPadDirectory);
	CNO_strcat(defaultactionpadpath,CNO_DS);
	CNO_strcat(defaultactionpadpath,"default.dreampuffactionpad");
	cno_value_type defaultactionpadvalue = json_parse_file_with_comments(defaultactionpadpath);
	if(defaultactionpadvalue != NULL){
		cno_object_type defaultactionpadobject = json_value_get_object(defaultactionpadvalue);
		cno_array_type defaultactionpadarray = json_object_get_array(defaultactionpadvalue, "actions");
		cno_u8_type i;
		for(i = 0; i < NumberofDreamPuff_Actions; i++){
			cno_object_type actionobject = json_array_get_object(defaultactionpadarray, i);
			//cno_cstring_type primary, secondary, tertiary;
			//cno_u8_type primaryenabled, secondaryenabled, tertiaryenabled;
			CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[i].primarycode, json_object_get_string(actionobject, "primarycode");
			DreamPuff_ActionPads[actionpad].actioncodes[i].primaryenabled = json_object_get_boolean(actionobject, "primaryenabled");
			CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[i].secondarycode, json_object_get_string(actionobject, "secondarycode");
			DreamPuff_ActionPads[actionpad].actioncodes[i].secondaryenabled = json_object_get_boolean(actionobject, "secondaryenabled");
			CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[i].tertiarycode, json_object_get_string(actionobject, "tertiarycode");
			DreamPuff_ActionPads[actionpad].actioncodes[i].tertiaryenabled = json_object_get_boolean(actionobject, "tertiaryenabled");
			DreamPuff_ActionPads[actionpad].actionstates[i] = 0;
		}
		DreamPuff_ActionPads[actionpad].inputsource = DreamPuff_InputSource_Local;
		DreamPuff_ActionPads[actionpad].enabled = 1;
	} else{
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Up].primarycode, "K82"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Up].primaryenabled = 1; //static
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Up].secondarycode, "K26"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Up].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Up].tertiarycode, "J0A1-"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Up].tertiaryenabled = 1;
 
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Down].primarycode, "K81"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Down].primaryenabled = 1; //static
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Down].secondarycode, "K22"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Down].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Down].tertiarycode, "J0A1+"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Down].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Left].primarycode, "K80"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Left].primaryenabled = 1; //static
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Left].secondarycode, "K4"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Left].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Left].tertiarycode, "J0A0-"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Left].tertiaryenabled = 1;
		
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Right].primarycode, "K79"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Right].primaryenabled = 1; //static
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Right].secondarycode, "K7"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Right].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Right].tertiarycode, "J0A0+"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Right].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Accept].primarycode, "K40"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Accept].primaryenabled = 1; //static
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Accept].secondarycode, "K44"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Accept].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Accept].tertiarycode, "J0B1"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Accept].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Cancel].primarycode, "K41"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Cancel].primaryenabled = 1; //static
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Cancel].secondarycode, "K42"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Cancel].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Cancel].tertiarycode, "J0B2"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Cancel].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Default].primarycode, "K17"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Default].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Default].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Default].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Default].tertiarycode, "J0B0"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_Default].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_More].primarycode, "K16"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_More].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_More].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_More].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_More].tertiarycode, "J0B3"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Menu_More].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_SystemMenu].primarycode, "K41"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_SystemMenu].primaryenabled = 1; //staic
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_SystemMenu].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_SystemMenu].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_SystemMenu].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_SystemMenu].tertiaryenabled = 1;
		
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Up].primarycode, "K26"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Up].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Up].secondarycode, "K82"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Up].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Up].tertiarycode, "J0A1-"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Up].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Down].primarycode, "K22"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Down].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Down].secondarycode, "K81"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Down].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Down].tertiarycode, "J0A1+"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Down].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Left].primarycode, "K4"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Left].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Left].secondarycode, "K80"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Left].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Left].tertiarycode, "J0A0-"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Left].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Right].primarycode, "K7"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Right].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Right].secondarycode, "K79"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Right].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Right].tertiarycode, "J0A0+"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Right].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Interact].primarycode, "K15"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Interact].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Interact].secondarycode, "K6"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Interact].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Interact].tertiarycode, "J0B0"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Interact].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Jump].primarycode, "K44"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Jump].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Jump].secondarycode, "K82"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Jump].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Jump].tertiarycode, "J0B1"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Jump].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Attack].primarycode, "K13"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Attack1].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Attack].secondarycode, "K29"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Attack1].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Attack].tertiarycode, "J0B2"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Attack1].tertiaryenabled = 1;
		
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Special].primarycode, "K14"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Special].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Special].secondarycode, "K27"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Special].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Special].tertiarycode, "J0B3"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Special].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Guard].primarycode, "K225"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Guard].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Guard].secondarycode, "K229"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Guard].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Guard].tertiarycode, "J0B4"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Guard].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Alt].primarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Alt].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Alt].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Alt].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Alt].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Alt].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_GameplayMenu].primarycode, "K43"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_GameplayMenu].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_GameplayMenu].secondarycode, "K19"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_GameplayMenu].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_GameplayMenu].tertiarycode, "J0B6"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_GameplayMenu].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Inventory].primarycode, "K12"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Inventory].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Inventory].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Inventory].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Inventory].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Inventory].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Map].primarycode, "K16"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Map].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Map].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Map].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Map].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Map].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Options].primarycode, "K18"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Options].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Options].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Options].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Options].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Gameplay_Options].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_SystemMenu].primarycode, "K41"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_SystemMenu].primaryenabled = 1; //static
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_SystemMenu].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_SystemMenu].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_SystemMenu].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_SystemMenu].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_AdvanceText].primarycode, "K44"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_AdvanceText].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_AdvanceText].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_AdvanceText].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_AdvanceText].tertiarycode, "J0B1"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_AdvanceText].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_FastAdvanceText].primarycode, "K9"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_FastAdvanceText].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_FastAdvanceText].secondarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_FastAdvanceText].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_FastAdvanceText].tertiarycode, "J0B2"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Cutscene_FastAdvanceText].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Quit].primarycode, "Alt+K61"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Quit].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Quit].secondarycode, "Meta+K20"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Quit].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Quit].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Quit].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftReset].primarycode, "K59"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftReset].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftReset].secondarycode, "Alt+K21"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftReset].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftReset].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftReset].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftPause].primarycode, "K51"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftPause].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftPause].secondarycode, "Alt+K19"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftPause].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftPause].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_SoftPause].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickSave].primarycode, "K62"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickSave].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickSave].secondarycode, "Alt+K14"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickSave].secondaryenabled = 0;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickSave].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickSave].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickLoad].primarycode, "K64"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickLoad].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickLoad].secondarycode, "Alt+K15"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickLoad].secondaryenabled = 0;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickLoad].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_QuickLoad].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Fullscreen].primarycode, "Alt+K40"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Fullscreen].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Fullscreen].secondarycode, "Meta+K9"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Fullscreen].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Fullscreen].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Fullscreen].tertiaryenabled = 1;

		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Screenshot].primarycode, "K69"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Screenshot].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Screenshot].secondarycode, "Alt+K6"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Screenshot].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Screenshot].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_System_Screenshot].tertiaryenabled = 1;
		
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Control].primarycode, "K224"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Control].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Control].secondarycode, "K228"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Control].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Control].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Control].tertiaryenabled = 1;
	
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Alt].primarycode, "K226"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Alt].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Alt].secondarycode, "K230"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Alt].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Alt].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Alt].tertiaryenabled = 1;
		
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Meta].primarycode, "K227"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Meta].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Meta].secondarycode, "K231"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Meta].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Meta].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Meta].tertiaryenabled = 1;
		
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Shift].primarycode, "K225"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Shift].primaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Shift].secondarycode, "K229"); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Shift].secondaryenabled = 1;
		CNO_strcpy(DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Shift].tertiarycode, ""); DreamPuff_ActionPads[actionpad].actioncodes[DreamPuff_Action_Modifier_Shift].tertiaryenabled = 1;
		
		DreamPuff_ActionPads[actionpad].inputsource = DreamPuff_InputSource_Local;
		DreamPuff_ActionPads[actionpad].enabled = 1;
	}
	DreamPuff_Mutex_Unlock_By_Name(DreamPuff_Actions_Mutex);
#endif //CNO_HAVE_STRING && CNO_HAVE_PARSON
	return 0;
}

cno_u8_type DreamPuff_ActionPad_Init(){
#if CNO_HAVE_STRETCHYBUFFER && CNO_HAVE_PARSON && CNO_HAVE_STRING
	DreamPuff_Mutex_Lock_By_Name(DreamPuff_Actions_Mutex);
	DreamPuff_ActionPads = NULL;
	cno_u8_type actionpaddirectory[CNO_Filename_Size];
	CNO_strcpy(actionpaddirectory, CNO_LowLevelConfig.directories.userdata);
	CNO_strcat(actionpaddirectory, "ActionPads");
	
	
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
