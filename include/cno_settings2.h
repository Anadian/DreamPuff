//cno_settings.h

#ifndef CNO_SETTINGS_H
#define CNO_SETTINGS_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#if (CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX) && (!defined(CNO_SETTINGS_MATCH_VALIDATION_REGEX) || !defined(CNO_SETTINGS_MATCH_REGEX_NMATCH))
#define CNO_SETTINGS_MATCH_VALIDATION_REGEX ":([-0-9A-Za-z_ ]*)?:([0-9A-Za-z_]+)?:(([-0-9A-Za-z]+)(=([0-9A-Za-z]))?)?:(0|(([NIRBWAUFDnirbwaufd])[^!?=;]*([!?])(=(((\|)|(([-0-9A-Za-z_.\/\\ ]+)([!?])?)))+)?));"
#define CNO_SETTINGS_MATCH_REGEX_NMATCH 18
#endif //(CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX) && (!defined(CNO_SETTING_VALIDATION_REGEX) || !defined(CNO_SETTING_REGEX_NMATCH))
// Conversion regex: /{":([^:]*):([^:]*):([^:=]*)(=([A-Za-z]))?:([0NIRBWAUFD][!?]?)(=([^;]*))?;","(.*)"},/{CNO_Setting_Type_,"\1","\2",'\5',"\3",'\6',NULL,"\9",NULL,0,0,0,"\8"},/

typedef enum CNO_Value_Type_enum{
	CNO_Value_Flag='0',
	CNO_Value_Natural='N',
	CNO_Value_Integer='I',
	CNO_Value_Real='R',
	CNO_Value_Boolean='B',
	CNO_Value_Word='W', //[A-Za-z0-9_]
	CNO_Value_ASCII='A',
	CNO_Value_UTF8='U',
	CNO_Value_File='F', //file/directory/url
	CNO_Value_Discrete='D'
} CNO_Value_Type\t;
typedef struct CNO_Setting_struct {
	cno_cstring_type section;
	cno_cstring_type config_name;
	cno_u8_type option_key;
	cno_cstring_type option_name;
	CNO_Value_Type_type value_type;
	cno_cstring_type hint;
	cno_cstring_type description;
	cno_cstring_type argument;
	cno_u8_type hits;
	union{
		cno_u8_type value; //natural/boolean
		cno_s32_type value; //integer
		cno_f32_type value; //real
		cno_cstring_type value; //word/ascii/file/discrete
		cno_utf8_type value; //utf8
	};
	union{
		cno_u8_type default_value; //natural/boolean
		cno_s32_type default_value; //integer
		cno_f32_type default_value; //real
		cno_cstring_type default_value; //word/ascii/file/discrete
		cno_utf8_type default_value; //utf8
	};
	cno_cstring_type valid_values;
} CNO_Setting_type; //system defaults => user config => options => -C if specified
	
/*
/*tier 1 ;
tier 2 :
tier 3 =
tier 4 | :[-0-9A-Za-z_ ]:[0-9A-Za-z_]:[-0-9A-Za-z]=[0-9A-Za-z]:[0-9A-Za-z!?]=[-0-9A-Za-z!?_ ];

number 0-?
true,on,enabled,yes=1
false,off,disabled,no=0
file/directory
string,subset,ascii,utf8,discrete,fd
input:controller engine:D!=none|sdl-joystick!|sdl-controller|xinput|libusb|libgamepad||Engine:Define which backend API (engine), if any, to use for reading joystick/gamepad/controller input.|sdl-joystick:
debug:verbosity|verbose=v:N?=3!|5?|0-5

{"\0","\0",'V',"version",'0',"\0","Display version information.","\0",0,0,0,"\0"},
{"\0","\0",'h',"help",'0',"\0","Display this help text.","\0",0,0,0,"\0"},
{"\0","\0",'a',"all",'0',"\0","Acknowledge invisible files","\0",0,0,0,"\0"},
{"\0","\0",'b',"about-background",'0',"\0","Display information about background process.","\0",0,0,0,"\0"},
{"\0","\0",'B',"start-background",'0',"\0","Start background process (daemon).","\0",0,0,0,"\0"},
{"\0","\0",'c',"configuration",'0',"\0","Print configuration information and exit.","\0",0,0,0,"\0"},
{"\0","\0",'C',"configfile",'F',"File","Use the given file for configuration.","\0",0,0,0,"\0"},
//{"\0","\0",'D',"dryrun",'0',"\0","Describe what this software would do, and what files it would change, without actually doing or changing anything.","\0",0,0,0,"\0"},
{"\0","\0",'f',"force",'0',"\0","Harness an energy which flows through the universe in order to do things without asking the user for permission.","\0",0,0,0,"\0"},
{"\0","\0",'F',"fail",'0',"\0","Don't take rejection so easily: exit at the first sign of something being wrong.","\0",0,0,0,"\0"},
{"\0","\0",'G',"global-colours",'B',"\0","Use global terminal colour system.","\0",0,0,0,"\0"},
{"\0","\0",'i',"interactive",'0',"\0","Offloads all the hard decision making onto the user.","\0",0,0,0,"\0"},
{"\0","\0",'I',"input",'F',"File","Uses the given file instead of STDIN.","\0",0,0,0,"\0"},
{"\0","\0",'k',"stop-background",'0',"\0","Politely stop the background process (daemon).","\0",0,0,0,"\0"},
{"\0","\0",'K',"kill-background",'0',"\0","Forcefully terminate the background process (daemon); in essence: kill it!","\0",0,0,0,"\0"},
{"\0","\0",'l',"long",'0',"\0","\0","\0",0,0,0,"\0"},
{"\0","\0",'L',"link",'F',"\0","Link a dynamic (.so) library; continues even if linking is unsuccessful.","\0",0,0,0,"\0"},
{"\0","\0",'n',"dryrun",'0',"\0","Describe what this software would do, and what files it would change, without actually doing or changing anything.","\0",0,0,0,"\0"},
{"\0","\0",'N',"newdefaults",'0',"\0","Create new default files.","\0",0,0,0,"\0"},
{"\0","\0",'O',"output",'F',"File","Tells the program to \"put out\" to the given file: whatever that means.","\0",0,0,0,"\0"},
{"\0","\0",'p',"preprocess",'0',"\0","But where's postprocess?","\0",0,0,0,"\0"},
{"\0","\0",'P',"prefix",'F',"Directory","Adds the given directory to the list of directories which contain directories, each containing list of directories to be searched to find files which list where to find the directories containing the needed files.","\0",0,0,0,"\0"},
{"\0","\0",'q',"quiet",'0',"\0","... please.","\0",0,0,0,"\0"},
{"\0","\0",'r',"recursive",'0',"\0","Search directories recursively.","\0",0,0,0,"\0"},
{"\0","\0",'R',"require",'F',"\0","Link a dynamic (.so) library; exits if linking is unsuccessful.","\0",0,0,0,"\0"},
{"\0","\0",'s',"silence",'0',"\0","Tells the software to shut up! Doubly redundant since \"-v 0\" and \"-q\" both get the same result.","\0",0,0,0,"\0"},
{"\0","\0",'S',"source",'F',"File","Reluctantly obeys the orders contained in the given file.","\0",0,0,0,"\0"},
{"\0","\0",'t',"test",'0',"\0","Run automated test.","\0",0,0,0,"\0"},
{"\0","\0",'u',"user",'W',"Username","Exempli gratia: local user -> \"luser\".","\0",0,0,0,"\0"},
{"\0","\0",'U',"update",'0',"\0","Breaks things.","\0",0,0,0,"\0"},
{"\0","\0",'x',"execute",'D',"Command","Kills the given commanding officer.","\0",0,0,0,"\0"},
{"\0","\0",'X',"exact",'D',"\0","Whaaaa?: Does something VERY specific: we just don't know what.","\0",0,0,0,"\0"},
{"\0","\0",'y',"yes",'0',"\0","Impersonates Jim Carrey's character in the movie Yes Man.","\0",0,0,0,"\0"},
{"audio","enabled",'A',"audio",'B',"Boolean","Enable audio.","false",0,0,1,"true|false"},
{"audio","channels",'\0',"\0",'N',"Number","Max number of audio channels to use.","\0",0,0,2,"[0,32]"},
{"audio","samplerate",'\0',"\0",'N',"Number","The sample rate, specified in Hz, to use for audio playback. 8000, 11025, 16000, 22050, 32000, 441000, 48000, or 96000 recommended.","\0",0,0,48000,"[0,160_000]"},
{"debug","enabled",'d',"debug",'B',"Boolean","Enable debugging.","true",0,0,0,"true|false"},
{"debug","verbosity",'v',"verbose",'N',"Number","Sets debug verbosity to the given unsigned integer: 0 being silent; 5 being maximum logging. Defaults to 3, if omitted, and 5, if specified without an argument.","5",0,0,3,"[0,5]"},
{"debug","standard_output",'o',"stdout",'F',"Stream","stdout, stderr, file, or /dev/null: oh, so many choices.","\0",0,0,"stdout","\0"},
{"debug","standard_error",'e',"error",'F',"Stream","Redirect stderr to the given stream; exempli gratia, stdout or a the name of a file.","\0",0,0,"stderr","\0"},
{"debug","file",'\0',"\0",'B',"Boolean","Enable logging to a file.","\0",0,0,1,"true|false"},
{"debug","filename",'\0',"\0",'F',"\0","File name: The name of the file to log to.","\0",0,0,"cno.log","\0"},
{"\0","dialogs",'\0',"\0",'B',"Boolean","Sets whether to allow using external file dialogs.","\0",0,0,1,"true|false"},
{"\0","environment",'\0',"\0",'B',"Boolean","Sets whether to look for environment variables while initialising.","\0",0,0,1,"true|false"},
{"input","keyboard_mode",'\0',"\0",'D',"String","Sets the keyboard mode; in essence, how this software interprets keyboard input.","\0",0,0,"scancode","scancode|keycode|text"}, //scancode, keycode, text
{"input","text_mode",'\0',"\0",'D',"String","Sets whether to use the OS-defined (\"hardware\") keyboard or an internal, virtual (\"software\") keyboard for text input.","\0",0,0,"hardware","software|hardware"}, //software, hardware
{"input","mouse_relative_motion",'\0',"\0",'B',"Boolean","Accept the mouse's relative motion as an input source?","\0",0,0,1,"true|false"},
{"input","mouse_buttons",'\0',"\0",'B',"Boolean","Accept mouse button events as an input source?","\0",0,0,1,"true|false"},
{"input","mouse_wheel",'\0',"\0",'B',"Boolean","Accept mouse wheel events as a valid input source?","\0",0,0,0,"true|false"},
{"input","controller_engine",'\0',"\0",'D',"String","|sdl-joystick: Use SDL\'s native joystick engine; works well with joysticks of all shapes and size","\0",0,0,"sdl-joystick","none|sdl-joystick|sdl-controller|xinput|libusb|libgamepad"}, //none, sdl-joystick, sdl-controller, xinput, libusb, libgamepad
{"input","joystick_buttons",'\0',"\0",'B',"Boolean","Sets whether to accept joystick button events as an input source.","\0",0,0,1,"true|false"},
{"input","joystick_axis",'\0',"\0",'B',"Boolean","Sets whether to accept joystick axis/analog events as a valid input source.","\0",0,0,1,"true|false"},
{"input","joystick_hat",'\0',"\0",'B',"Boolean","Sets whether to accept joystick hat/pad events as a valid input source.","\0",0,0,1,"true|false"},
{"input","joystick_ball",'\0',"\0",'B',"Boolean","Set whether to accept joystick ball events as an input source.","\0",0,0,1,"true|false"},
{"input","joystick_axis_deadzone",'\0',"\0",'N',"Number","Sets the dead zone for all joysticks' axes; in essence, it's the minimum, absolute value an axis must possess (read) in to be used as an event.","\0",0,0,800,"[0,32_767]"},
{"input","joystick_axis_peak",'\0',"\0",'N',"Number","Sets the peak for joysticks' axes; in essence, the value that should be considered max when reading an axis event.","\0",0,0,32000,"[0,32_767]"},
{"input","touch_mode",'\0',"\0",'D',"String","Sets whether touch events should be interpreted has mouse clicks/motion or handled separately.","\0",0,0,"mouse","mouse|touch"}, //mouse, touch
{"\0","net",'\0',"\0",'B',"Boolean","Enable networking functionality.","\0",0,0,1,"true|false"},
{"sdl2","sdl2_enabled",'\0',"\0",'B',"Boolean","Allow the use of SDL2 for video/threads/input-backend API.","\0",0,0,1,"true|false"},
{"sdl2","sdl2_ttf_enabled",'\0',"\0",'B',"Boolean","Use, SDL2-extension, SDL2_TTF for font rendering.","\0",0,0,1,"true|false"},
{"sdl2","sdl2_gfx_enabled",'\0',"\0",'B',"Boolean","Allow the use, SDL2-extension, SDL2_GFX for software rendering of primitives and graphical effects.","\0",0,0,0,"true|false"},
{"sdl2 image","enabled",'\0',"\0",'B',"Boolean","Use, SDL2-extension, SDL2_Image for image loading.","\0",0,0,1,"true|false"},
{"sdl2 image","jpg",'\0',"\0",'B',"Boolean","Allow SDL2_Image to load JPEG files.","\0",0,0,0,"true|false"},
{"sdl2 image","png",'\0',"\0",'B',"Boolean","Allow SDL2_Image to load PNG files.","\0",0,0,1,"true|false"},
{"sdl2 image","tif",'\0',"\0",'B',"Boolean","Allow SDL2_Image to load TIF files.","\0",0,0,0,"true|false"},
{"sdl2 mixer","enabled",'\0',"\0",'B',"Boolean","Use, SDL2-extension, SDL2_Mixer for audio.","\0",0,0,1,"true|false"},
{"sdl2 mixer","flac",'\0',"\0",'B',"Boolean","Allow SDL2_Mixer to load FLAC audio files.","\0",0,0,0,"true|false"},
{"sdl2 mixer","mod",'\0',"\0",'B',"Boolean","Allow SDL2_Mixer to load MOD audio files.","\0",0,0,0,"true|false"},
{"sdl2 mixer","mp3",'\0',"\0",'B',"Boolean","Allow SDL2_Mixer to load MP3 audio files.","\0",0,0,1,"true|false"},
{"sdl2 mixer","ogg",'\0',"\0",'B',"Boolean","Allow SDL2_Mixer to load OGG audio files.","\0",0,0,1,"true|false"},
{"threads","enabled",'\0',"\0",'B',"Boolean","Allow the use of multithreading.","\0",0,0,1,"true|false"},
{"threads","max_threads",'\0',"\0",'N',"Number","Sets the maximum number of threads.","\0",0,0,8,"[0,8]"},
{"threads","logic",'\0',"\0",'B',"Boolean","Conduct logic on its own thread.","\0",0,0,1,"true|false"},
{"threads","network",'\0',"\0",'B',"Boolean","Conduct networking on its own thread.","\0",0,0,1,"true|false"},
{"video","enabled",'g',"gui",'B',"Boolean","Enable video. (Opens a window; good for letting the air out.)","false",0,0,1,"true|false"},
{"video","save_screenshot_bmp",'\0',"\0",'B',"Boolean","Save screenshots as bitmap image files.","\0",0,0,0,"true|false"},
{"video","save_screenshot_png",'\0',"\0",'B',"Boolean","Save screenshots as PNG image files.","\0",0,0,1,"true|false"},
{"video","driver",'\0',"\0",'N',"Number","Use the video driver, corresponding to the given number, for all video rendering.","\0",0,0,0,"[0,8]"},
{"video","display",'\0',"\0",'N',"Number","Prefer the display, corresponding to give number, for creating windows and rendering fullscreen.","\0",0,0,0,"[0,8]"},
{"video","displaymode",'\0',"\0",'N',"Number","Derive resolution, colour depth, and fullscreen rules from the display-mode which corresponds to the given number.","\0",0,0,0,"[0,16]"},
{"video","x_offset",'\0',"\0",'I',"Integer","The x position of the window in pixels.","\0",0,0,0,"[-32_787,32_787]"},
{"video","y_offset",'\0',"\0",'I',"Integer","The y position of the window in pixels.","\0",0,0,0,"[-32_787,32_787]"},
{"video","width",'\0',"\0",'N',"Number","The width (horizontal size) of the window in pixels.","\0",0,0,640,"[0,65_535]"},
{"video","height",'\0',"\0",'N',"Number","The height (vertical size) of the window in pixels.","\0",0,0,480,"[0,65_535]"},
{"video","bits_per_pixel",'\0',"\0",'N',"Number","The colour depth of window/display in bits per pixel; not to be confused with bytes per pixel.","\0",0,0,32,"[0,32]"},
{"video","exclusive_fullscreen",'\0',"\0",'B',"Boolean","Whether to prefer exclusive (\"real\") fullscreen (changing the desktop display mode to rendering resolution) over windowed/borderless (\"fake\") fullscreen.","\0",0,0,0,"true|false"},
{"video","framerate",'\0',"\0",'N',"Number","How many times the render area should be refreshed (re-rendered) in a second (hertz); also commonly known as frames per second (FPS) or refresh rate. 0 will disable frame limiting altogether allowing the screen to be rendered as many times-a-second as it can (unlimited frames per second).","\0",0,0,0,"[0,120]"},
{"video","resizable",'\0',"\0",'B',"Boolean","Allows windows to be resized but pulling on their edge.","\0",0,0,1,"true|false"},
{"video","borderless",'\0',"\0",'B',"Boolean","Makes windows borderless, essentially, removing the titlebar and the close/minimize buttons, showing only the rendering area.","\0",0,0,0,"true|false"},
{"video","disable_screensaver",'\0',"\0",'B',"Boolean","Explicitly disable any screensavers while application has focus; useful if you using sdl-joystick.","\0",0,0,1,"true|false"},
{"video","software_bitmaps",'\0',"\0",'B',"Boolean","Store images (bitmaps) in a software format (on CPU/RAM) as opposed to the default hardware format (GPU/vRAM).","\0",0,0,0,"true|false"},
{"video","software_effects",'\0',"\0",'B',"Boolean","Render graphical effects on the CPU (software style) as opposed to the, default, GPU (hardware-accelerated rendering).","\0",0,0,0,"true|false"},
{"video","software_render",'\0',"\0",'B',"Boolean","Store the render buffer in RAM (software-style CPU blitting) as opposed to the default, hardware-accelerated, texture format.","\0",0,0,0,"true|false"},
{"directories","portable",'\0',"\0",'B',"Boolean","Only use directory containing this executable/binary for storing and retrieving data: portable-style ./; as opposed to unix-style: /usr/local/* and ~/*.","\0",0,0,1,"true|false"},
{"directories","engine_data",'\0',"\0",'F',"Directory","The directory, in which, the engine data can be found.","\0",0,0,"./engine","\0"},
{"directories","user_data",'\0',"\0",'F',"Directory","The directory, in which, user data should be saved.","\0",0,0,"./data","\0"},*/

cno_u8_type CNO_Settings_Init(CNO_Setting_type *settings);
cno_u8_type CNO_Settings_Default(CNO_Settings_type *settings);
cno_u8_type CNO_Settings_GetOpt(CNO_Settings_type *settings, int argc, char *argv[]);
cno_u8_type CNO_Settings_Save(CNO_Settings_type *settings, cno_cstring_type filename);
cno_u8_type CNO_Settings_Load(CNO_Settings_type *settings, cno_cstring_type filename);
cno_u8_type CNO_Settings_Quit(CNO_Setting_type *settings);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_SETTINGS_H
