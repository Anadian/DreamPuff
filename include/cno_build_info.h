//cno_build_info.h: Runtime readable build information

#ifndef CNO_BUILD_INFO_H
#define CNO_BUILD_INFO_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

cno_u8_type CNO_Build_String[CNO_BUFFER_MAXSIZE];

/*

HUD placement:
status:
name, level, state (if noteworthy)
hp,
ep,

[element]:off, minimal, standard (only for the HUD itself), comprehensive, custom
scaleable radius
12 slots
fade: auto, toggle, off
Status (TL), game time/location/direction/weather (TC), Navigation/Alert (TR) connectivity and wall time
Mission info (tutorial hints),  (beacon), controller state
count, reticle, timers/splits
hotkey, subtitles, weapon info/equipment mapping
Inventory/Command (BL), Contextual (BC), Enemy Info (BR)/picture-in-picture
[OSC]???

hint/tutorials: off, optional, automatic

AI:
Reaction 0-10
Accuracy(skill) 0-10
Knowledge 0-10 //2 points for mechanics, map, location, equipment, opponents
Priority lazy, vengeance, equalizer
Strategy methodical, oddball
Attention precise, general
Caution risky, safe	//stealth v aggression

Display
Sound
Text
Input
Controls
Camera
Network
Graphics
System
Game

Display:
driver
display
display mode
exclusive fullscreen
xoffset
yoffset
width
height
framerate
vsync
[borderless]
[[resizable]]
disable screensaver
software-to-hardware scale
scale-to-any-resolution, scale-to-nearest-aspect, no-scaling
[viewport scale if any or nearest-aspect]

Sound: (unless -A)
master volume
gameplay volume
cutscene volume
menu volume
Event music
diagestic music
ui music
ambience
ui sound effects
diagestic sound effects
miscellaneous sound effects
[categorical muting]
voice language
dialog voice
barks and gameplay-relevant voice
chitchat voice
players voice
game menu volume reduction
channels
samplerate
3D sound (hardware accelerated)
sound-modifying effects
streaming preload
mic sensitivity

Text:
text language
speed
scroll
gameplay subtitles (lang)
font-size
format (colours)
cutscene subtitles (lang)
font-size
format
menu-text (lang)
font-size
format
ui-text (lang)
font-size
format

Input:
source toggles
key mode (scancode/keycode)
disable keyboard/mouse while controller connected
mouse mode (toggles for motion, buttons and wheels)
mouse sensitivity
mouse wheel inversion
touch mode (mouse/finger)
controller mode: 
xinput
joystick
[joystick deadzone]
[joystick peak]
game-controller
libusb
libgamepad
soft pause for lack of input
devices

Camera:
disable mouse camera when controller connected
TPS: x/y-invert, sensitivity, speed, correction (off, minimal, modest, zealous), wall clipping, targeting, distance?
gallery: x/y-invert, sensitivity, speed, no-move-box width/height, move-box width/height
OTS (over-the-shoulder): x/y-invert, sensitivity, speed
FPS: x/y-invert, sensitivity, speed, correction, FOV
ADS (aim-down-site): x/y-invert, sensitivity, speed, correction,

//aim point
//view point
//rot point

Network:
Online
Account
Encrypt save data

Graphics:
Gamma correction
Effects
Quality
Content
HUD

System:
autosave 
softpause on focus lost
Loading-and-freeing/memory usage, preload-everything, preload everything and free as needed, load as needed but don't free until quit, high/medium/low memory usage
Decompress game data
Mods

elements:
water //slow / douse
fire //burn / melt
ice //freeze / strengthen
wind //throw / throw/ware
earth //high damage / ground
electricity //crit / conduct
water

augments:
holy //strong against mystical / weak against realistic
dark //strong against realistic / weak against mystic
plasma //strong against
fungus
herbal

attack styles:
impale/penetrate //effective against biotic enemies and realistic enemies
slash/burn //all-around
bash/blunt //effective against mystical enemies and armored enemies
shoot //short, medium, long, penetration,
cast //AoE, persistence, homing?
throw //arc, variance, delay?

penetrate v. bash
speed v. power

actions:
swing,
stab,
block,
aim/targetting?,
throw,
evade,
climb,
grab,
sneak,
cast,
hack (mechanical skill)

stats:
strength (swing, stab, block, throw, climb, grab) v. dexterity
constitution (HP, resistance, knockback) v. agility
intelligence (MP, magic, block, stab?, sneak, cast)
agility (EP, swing, throw, evade, climb, grab, sneak)
dexterity (skill (SP), aim, hack, grab, block, climb, sneak)

strength/dexterity
constitution/agility
utility/mastery
combat/stealth
independent/collaborative 
technical/social
lawful/populist
idealist/realist
analytical/intuitive
stoical/emotional
rational/altruistic
secular/spiritual
competitive/cooperative


resources (social favours)
knowledge,

debuffs:
slow
burn
syphon
freeze
poison


attack, element1 element2, DMG, stun, speed, super cost, super DMG, super stun, range (long medium short)
medium and long are weaker against heavy enemies; short range weapons deal less damage to far away targets
combos: start, hits, finish; low DMG high stun attacks start combo, high DMG low stun attacks finish combos
knockback is derived from damage
speed and stun are related

enemy, element1 element2, HP, class, EXP, gold
*/

//DreamPuff-Competitive/Open-Server/Client-Deamon/NativeExecutable/Embedded-Console/Electron/etc binary-x86_64-macOS-clang-date-commit

cno_u8_type CNO_Build_Info_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_BUILD_INFO_H
