//dreampuff_input.c

#include "dreampuff_input.h"

#include "cno_config.h"
#include "cno_log.h"

#if CNO_HAVE_SDL2
#include <SDL2/SDL.h>
SDL_Event previousevent;
#endif //CNO_HAVE_SDL2

#include "dreampuff_core.h" //DreamPuff_Engine.running, DreamPuff_Engine.sleeping

cno_u8_type DreamPuff_Input_SDL(){
#if CNO_HAVE_SDL2
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
					cno_log(4,"Window event %d window %d event %d timestamp %d", event.window.type, event.window.windowID, event.window.event, event.window.timestamp);
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
	return 1;
#endif //CNO_HAVE_SDL2
	return 0;
}

