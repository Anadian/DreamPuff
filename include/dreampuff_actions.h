//dreampuff_actions.h

#ifndef DREAMPUFF_ACTIONS_H
#define DREAMPUFF_ACTIONS_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

typedef enum DreamPuff_InputSource_enum{
	DreamPuff_InputSource_Local=0,
	DreamPuff_InputSource_Replay,
	DreamPuff_InputSource_Online,
	NumberofDreamPuff_InputSources
} DreamPuff_InputSource_type;
typedef enum DreamPuff_Action_Name_enum{
	DreamPuff_Action_Menu_Up=0, //static
	DreamPuff_Action_Menu_Down, //static
	DreamPuff_Action_Menu_Left, //static
	DreamPuff_Action_Menu_Right, //static
	DreamPuff_Action_Menu_Accept, //static A
	DreamPuff_Action_Menu_Cancel, //static B
	DreamPuff_Action_Menu_Auxilary, //X
	DreamPuff_Action_Menu_Default, //Y
	DreamPuff_Action_Menu_PanLeft, //LB
	DreamPuff_Action_Menu_PanRight, //RB
	DreamPuff_Action_Menu_QuickScroll,
	DreamPuff_Action_Gameplay_SystemMenu, //static
	DreamPuff_Action_Gameplay_Up,
	DreamPuff_Action_Gameplay_Down,
	DreamPuff_Action_Gameplay_Left,
	DreamPuff_Action_Gameplay_Right,
	//aim
	DreamPuff_Action_Gameplay_Interact,
	DreamPuff_Action_Gameplay_Jump,
	DreamPuff_Action_Gameplay_Attack,
	DreamPuff_Action_Gameplay_Special,
	DreamPuff_Action_Gameplay_Guard,
	//stance
	DreamPuff_Action_Gameplay_Modifier,
	DreamPuff_Action_Gameplay_GameplayMenu,
	DreamPuff_Action_Gameplay_Inventory, //I Up
	DreamPuff_Action_Gameplay_Map, //M Down
	DreamPuff_Action_Gameplay_Status, //O Left
	DreamPuff_Action_Gameplay_HelpLog, //P Right
	DreamPuff_Action_Gameplay_Options,
	DreamPuff_Action_Cutscene_SystemMenu, //static
	DreamPuff_Action_Cutscene_AdvanceText, 
	DreamPuff_Action_Cutscene_FastAdvanceText,
	DreamPuff_Action_System_Quit, //Command+Q, Alt+F4
	DreamPuff_Action_System_SoftReset, //F2
	DreamPuff_Action_System_SoftPause, //F1
	DreamPuff_Action_System_QuickSave, //F5
	DreamPuff_Action_System_QuickLoad, //F7
	DreamPuff_Action_System_Fullscreen, //Alt+Return
	DreamPuff_Action_System_Screenshot, //F12
	DreamPuff_Action_Modifier_Control,
	DreamPuff_Action_Modifier_Alt,
	DreamPuff_Action_Modifier_Meta,
	DreamPuff_Action_Modifier_Shift,
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
	cno_u8_type enabled;
	DreamPuff_InputSource_type inputsource;
	DreamPuff_Action_Code_type actioncodes[NumberofDreamPuff_Actions];
	cno_s32_type actionstates[NumberofDreamPuff_Actions];
} DreamPuff_ActionPad_type;

DreamPuff_ActionPad_type DreamPuff_ActionPads[4];

//DreamPuff_Replay_Record();
//DreamPuff_Replay_Pause();
//DreamPuff_Replay_Unpause();
//DreamPuff_Replay_Stop();
//DreamPuff_Playback_Begin();
//DreamPuff_Playback_Pause();
//DreamPuff_Playback_Unpause();
//DreamPuff_Playback_End();

cno_u8_type DreamPuff_ActionPad_Default(cno_u8_type actionpad);
cno_u8_type DreamPuff_ActionPad_Save(cno_u8_type actionpad, cno_cstring_type filename);
cno_u8_type DreamPuff_ActionPad_Load(cno_u8_type actionpad, cno_cstring_type filename);

cno_u8_type DreamPuff_Actions_Update();
cno_s32_type DreamPuff_Actions_GetState(cno_u8_type actionpad, DreamPuff_Action_Name_type actionname);
cno_u16_type DreamPuff_Actions_GetPrompt(cno_u8_type actionpad, DreamPuff_Action_Name_type actionname);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_ACTIONS_H
