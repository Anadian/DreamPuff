//dreampuff_actions.h

#ifndef DREAMPUFF_ACTIONS_H
#define DREAMPUFF_ACTIONS_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

typedef enum DreamPuff_Action_Name_enum{
	DreamPuff_Action_Menu_Up=0, //static
	DreamPuff_Action_Menu_Down, //static
	DreamPuff_Action_Menu_Left, //static
	DreamPuff_Action_Menu_Right, //static
	DreamPuff_Action_Menu_Accept, //static
	DreamPuff_Action_Menu_Cancel, //static
	DreamPuff_Action_Menu_Default,
	DreamPuff_Action_Menu_More,
	DreamPuff_Action_Gameplay_SystemMenu, //static
	DreamPuff_Action_Gameplay_Up,
	DreamPuff_Action_Gameplay_Down,
	DreamPuff_Action_Gameplay_Left,
	DreamPuff_Action_Gameplay_Right,
	DreamPuff_Action_Gameplay_Interact,
	DreamPuff_Action_Gameplay_Jump,
	DreamPuff_Action_Gameplay_Attack1,
	DreamPuff_Action_Gameplay_Attack2,
	DreamPuff_Action_Gameplay_Special,
	DreamPuff_Action_Gameplay_Guard,
	DreamPuff_Action_Gameplay_Alt,
	DreamPuff_Action_Gameplay_GameplayMenu,
	DreamPuff_Action_Gameplay_Inventory,
	DreamPuff_Action_Gameplay_Map,
	DreamPuff_Action_Gameplay_Options,
	DreamPuff_Action_Cutscene_SystemMenu, //static
	DreamPuff_Action_Cutscene_AdvanceText,
	DreamPuff_Action_Cutscene_FastAdvanceText,
	DreamPuff_Action_System_Quit,
	DreamPuff_Action_System_SoftReset,
	DreamPuff_Action_System_SoftPause,
	DreamPuff_Action_System_QuickSave,
	DreamPuff_Action_System_QuickLoad,
	DreamPuff_Action_System_Fullscreen,
	DreamPuff_Action_System_Screenshot,
	NumberofDreamPuff_Actions
} DreamPuff_Action_Name_type;
typedef struct DreamPuff_Action_Code_struct{
	cno_u8_type primarycode[8];
	cno_u8_type primaryenabled;
	cno_u8_type secondarycode[8];
	cno_u8_type secondaryenabled;
	cno_u8_type tertiarycode[8];
	cno_u8_type tertiaryenabled;
	cno_u16_type prompt; //0 = none
} DreamPuff_Action_Code_type;

typedef struct DreamPuff_ActionPad_struct{
	DreamPuff_Action_Code_type actioncodes[NumberofDreamPuff_Actions];
	cno_s32_type actionstates[NumberofDreamPuff_Actions];
} DreamPuff_ActionPad_type;

DreamPuff_ActionPad_type *DreamPuff_ActionPads;

//DreamPuff_Replay_Record();
//DreamPuff_Replay_Pause();
//DreamPuff_Replay_Unpause();
//DreamPuff_Replay_Stop();
//DreamPuff_Playback_Begin();
//DreamPuff_Playback_Pause();
//DreamPuff_Playback_Unpause();
//DreamPuff_Playback_End();

c\u8\ty DP\ActionPad_Init();
cno_u8_type DreamPuff_ActionPad_Add(c\cstring\ty filename);
cno_u8_type DreamPuff_ActionPad_Configure(cno_u8_type actionpad, cno_cstring_type filename);
cno_u8_type DreamPuff_ActionPad_Clear();
c\u8\ty DP\ActionPad_Quit();
cno_u8_type DreamPuff_Actions_Update();
cno_s32_type DreamPuff_Actions_GetState(cno_u8_type actionpad, DreamPuff_Action_Name_type actionname);
cno_u16_type DreamPuff_Actions_GetPrompt(cno_u8_type actionpad, DreamPuff_Action_Name_type actionname);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_ACTIONS_H
