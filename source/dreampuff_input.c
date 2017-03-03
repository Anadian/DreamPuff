//dreampuff_input.c

#include "dreampuff_input.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_HAVE_SDL2
#include <SDL2/SDL.h>
SDL_Event previousevent;
#endif //CNO_HAVE_SDL2

#include "dreampuff_core.h" //DreamPuff_Engine.running, DreamPuff_Engine.sleeping
#include "dreampuff_actions.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //sprintf
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STRING
#include <string.h> //strcpy
#endif //CNO_HAVE_STRING
#if CNO_HAVE_STRETCHYBUFFER
#include "stretchy_buffer.h"
#endif //CNO_HAVE_STRETCHYBUFFER

cno_u8_type DreamPuff_Input_SDL(){
#if CNO_HAVE_SDL2 && CNO_HAVE_STDIO && CNO_HAVE_STRETCHYBUFFER && CNO_HAVE_STRING
	SDL_Event event;
	cno_u8_type eventsimilarity;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				DreamPuff_Engine_Stop();
				cno_log(4, "Quit event %d %d", event.quit.type, event.quit.timestamp);
				break;
			case SDL_WINDOWEVENT:
				eventsimilarity = 0;
				if(event.window.windowID == previousevent.window.windowID) eventsimilarity++;
				if(event.window.event == previousevent.window.event) eventsimilarity++;
				if(eventsimilarity <= 1){
					cno_log(5,"Window event %d window %d event %d timestamp %d", event.window.type, event.window.windowID, event.window.event, event.window.timestamp);
					//2 disable rendering, 3 enable rendering, 7 hardpause, 9 hard unpause, 12 soft unpause, 13 soft pause
					previousevent = event;
				}
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				eventsimilarity = 0;
				if(event.key.type == previousevent.key.type) eventsimilarity++;
				if(event.key.windowID == previousevent.key.windowID) eventsimilarity++;
				if(event.key.keysym.scancode == previousevent.key.keysym.scancode) eventsimilarity++;
				if(event.key.state == previousevent.key.state) eventsimilarity++;
				if(eventsimilarity <= 3){
					cno_log(4,"Key event %d window %d key %d state %d timestamp %d", event.key.type, event.key.windowID, event.key.keysym.scancode, event.key.state, event.key.timestamp);
					DreamPuff_Event_type internalevent;
					CNO_sprintf(internalevent.code, "K%d", event.key.keysym.scancode);
					if(event.key.state == SDL_PRESSED) internalevent.value = 1;
					else if(event.key.state == SDL_RELEASED) internalevent.value = -1;
					internalevent.time = event.key.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				eventsimilarity = 0;
				if(event.button.type == previousevent.button.type) eventsimilarity++;
				if(event.button.windowID == previousevent.button.windowID) eventsimilarity++;
				if(event.button.which == previousevent.button.which) eventsimilarity++;
				if(event.button.button == previousevent.button.button) eventsimilarity++;
				if(event.button.state == previousevent.button.state) eventsimilarity++;
				if(eventsimilarity <= 4){
					cno_log(4,"Mouse button event %d window %d which %d button %d state %d timestamp %d", event.button.type, event.button.windowID, event.button.which, event.button.button, event.button.state, event.button.timestamp);
					//if(event.button.which != SDL_TOUCH_MOUSEID)
					DreamPuff_Event_type internalevent;
					CNO_sprintf(internalevent.code, "MB%d", event.button.button);
					if(event.button.state == SDL_PRESSED) internalevent.value = 1;
					else if(event.button.state == SDL_RELEASED) internalevent.value = -1;
					internalevent.time = event.button.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_MOUSEMOTION:
				eventsimilarity = 0;
				if(event.motion.type == previousevent.motion.type) eventsimilarity++;
				if(event.motion.windowID == previousevent.motion.windowID) eventsimilarity++;
				if(event.motion.which == previousevent.motion.which) eventsimilarity++;
				if(event.motion.x == previousevent.motion.x) eventsimilarity++;
				if(event.motion.y == previousevent.motion.y) eventsimilarity++;
				if(event.motion.xrel == previousevent.motion.xrel) eventsimilarity++;
				if(event.motion.yrel == previousevent.motion.yrel) eventsimilarity++;
				if(event.motion.state == previousevent.motion.state) eventsimilarity++;
				if(eventsimilarity <= 7){
					cno_log(5,"Mouse motion event %d window %d which %d x %d y %d xrel %d yrel %d state %d timestamp %d", event.motion.type, event.motion.windowID, event.motion.which, event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel, event.motion.state, event.motion.timestamp);
					DreamPuff_Event_type internalevent;
					CNO_strcpy(internalevent.code, "MX");
					internalevent.value = event.motion.xrel;
					internalevent.time = event.motion.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					CNO_strcpy(internalevent.code, "MY");
					internalevent.value = event.motion.yrel;
					internalevent.time = event.motion.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_MOUSEWHEEL:
				eventsimilarity = 0;
				if(event.wheel.type == previousevent.wheel.type) eventsimilarity++;
				if(event.wheel.windowID == previousevent.wheel.windowID) eventsimilarity++;
				if(event.wheel.which == previousevent.wheel.which) eventsimilarity++;
				if(event.wheel.x == previousevent.wheel.x) eventsimilarity++;
				if(event.wheel.y == previousevent.wheel.y) eventsimilarity++;
				if(event.wheel.direction == previousevent.wheel.direction) eventsimilarity++;
				if(eventsimilarity <= 5){
					cno_log(5,"Mouse wheel event %d window %d which %d x %d y %d direction %d timestamp %d", event.wheel.type, event.wheel.windowID, event.wheel.which, event.wheel.x, event.wheel.y, event.wheel.direction, event.wheel.timestamp);
					DreamPuff_Event_type internalevent;
					CNO_strcpy(internalevent.code, "WX");
					internalevent.value = event.wheel.x;
					internalevent.time = event.wheel.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					CNO_strcpy(internalevent.code, "WY");
					internalevent.value = event.wheel.y;
					internalevent.time = event.wheel.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_JOYBUTTONDOWN:
			case SDL_JOYBUTTONUP:
				eventsimilarity = 0;
				if(event.jbutton.type == previousevent.jbutton.type) eventsimilarity++;
				if(event.jbutton.which == previousevent.jbutton.which) eventsimilarity++;
				if(event.jbutton.button == previousevent.jbutton.button) eventsimilarity++;
				if(event.jbutton.state == previousevent.jbutton.state) eventsimilarity++;
				if(eventsimilarity <= 3){
					cno_log(4,"Joystick button event %d which %d button %d state %d timestamp %d", event.jbutton.type, event.jbutton.which, event.jbutton.button, event.jbutton.state, event.jbutton.timestamp);
					DreamPuff_Event_type internalevent;
					CNO_sprintf(internalevent.code, "J%dB%d", event.jbutton.which, event.jbutton.button);
					if(event.jbutton.state == SDL_PRESSED) internalevent.value = 1;
					else if(event.jbutton.state == SDL_RELEASED) internalevent.value = -1;
					internalevent.time = event.jbutton.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_JOYAXISMOTION:
				eventsimilarity = 0;
				if(event.jaxis.type == previousevent.jaxis.type) eventsimilarity++;
				if(event.jaxis.which == previousevent.jaxis.which) eventsimilarity++;
				if(event.jaxis.axis == previousevent.jaxis.axis) eventsimilarity++;
				if(event.jaxis.value == previousevent.jaxis.value) eventsimilarity++;
				if(eventsimilarity <= 3){
					cno_log(5,"Joystick axis event %d which %d axis %d value %d timestamp %d", event.jaxis.type, event.jaxis.which, event.jaxis.axis, event.jaxis.value, event.jaxis.timestamp);
					DreamPuff_Event_type internalevent;
					CNO_sprintf(internalevent.code, "J%dA%d", event.jaxis.which, event.jaxis.axis);
					internalevent.value = event.jaxis.value;
					internalevent.time = event.jaxis.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_JOYHATMOTION:
				eventsimilarity = 0;
				if(event.jhat.type == previousevent.jhat.type) eventsimilarity++;
				if(event.jhat.which == previousevent.jhat.which) eventsimilarity++;
				if(event.jhat.hat == previousevent.jhat.hat) eventsimilarity++;
				if(event.jhat.value == previousevent.jhat.value) eventsimilarity++;
				if(eventsimilarity <= 3){
					cno_log(5,"Joystick hat event %d which %d axis %d value %d timestamp %d", event.jhat.type, event.jhat.which, event.jhat.hat, event.jhat.value, event.jhat.timestamp);
					DreamPuff_Event_type internalevent;
					CNO_sprintf(internalevent.code, "J%dH%d", event.jhat.which, event.jhat.hat);
					internalevent.value = event.jhat.value;
					internalevent.time = event.jhat.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_JOYBALLMOTION:
				eventsimilarity = 0;
				if(event.jball.type == previousevent.jball.type) eventsimilarity++;
				if(event.jball.which == previousevent.jball.which) eventsimilarity++;
				if(event.jball.ball == previousevent.jball.ball) eventsimilarity++;
				if(event.jball.xrel == previousevent.jball.xrel) eventsimilarity++;
				if(event.jball.yrel == previousevent.jball.yrel) eventsimilarity++;
				if(eventsimilarity <= 4){
					cno_log(5,"Joystick ball event %d which %d ball %d x %d y %d timestamp %d", event.jball.type, event.jball.which, event.jball.ball, event.jball.xrel, event.jball.yrel, event.jball.timestamp);
					DreamPuff_Event_type internalevent;
					CNO_sprintf(internalevent.code, "J%dB%dX", event.jball.which, event.jball.ball);
					internalevent.value = event.jball.xrel;
					internalevent.time = event.jball.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					CNO_sprintf(internalevent.code, "J%dB%dY", event.jball.which, event.jball.ball);
					internalevent.value = event.jball.yrel;
					internalevent.time = event.jball.timestamp;
					sb_push(DreamPuff_Events, internalevent);
					previousevent = event;
				}
				break;
			case SDL_JOYDEVICEADDED:
			case SDL_JOYDEVICEREMOVED:
				eventsimilarity = 0;
				if(event.jdevice.type == previousevent.jdevice.type) eventsimilarity++;
				if(event.jdevice.which == previousevent.jdevice.which) eventsimilarity++;
				if(eventsimilarity <= 1){
					cno_log(3,"Joystick device event %d which %d timestamp %d", event.jdevice.type, event.jdevice.which, event.jdevice.timestamp);
					previousevent = event;
				}
				break;
			default:
				break;
		}
	}
	//DreamPuff_Input_ProcessEvents();
	return 1;
#endif //CNO_HAVE_SDL2
	return 0;
}
cno_u8_type DreamPuff_Input_Real(){
	DreamPuff_Input_SDL();
	DreamPuff_Actions_Update();
	return 0;
}

