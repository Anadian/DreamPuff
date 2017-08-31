//cno_build_info.h: Runtime readable build information

#ifndef CNO_BUILD_INFO_H
#define CNO_BUILD_INFO_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

typedef struct CNO_Build_Info_struct{
	cno_u8_type build_string[CNO_BUFFER_MAXSIZE];
	cno_u8_type sdl_version_compiled_major;
	cno_u8_type sdl_version_compiled_minor;
	cno_u8_type sdl_version_compiled_patch;
	cno_u8_type sdl_version_linked_major;
	cno_u8_type sdl_version_linked_minor;
	cno_u8_type sdl_version_linked_patch;
	cno_u8_type sdl_image_compiled_major;
	cno_u8_type sdl_image_compiled_minor;
	cno_u8_type sdl_image_compiled_patch;
	cno_u8_type sdl_image_linked_major;
	cno_u8_type sdl_image_linked_minor;
	cno_u8_type sdl_image_linked_patch;
	cno_u8_type sdl_mixer_compiled_major;
	cno_u8_type sdl_mixer_compiled_minor;
	cno_u8_type sdl_mixer_compiled_patch;
	cno_u8_type sdl_mixer_linked_major;
	cno_u8_type sdl_mixer_linked_minor;
	cno_u8_type sdl_mixer_linked_patch;
	cno_u8_type sdl_ttf_compiled_major;
	cno_u8_type sdl_ttf_compiled_minor;
	cno_u8_type sdl_ttf_compiled_patch;
	cno_u8_type sdl_ttf_linked_major;
	cno_u8_type sdl_ttf_linked_minor;
	cno_u8_type sdl_ttf_linked_patch;
/*

HUD placement:
status:
name, level/lives, state
hp, bar-red, curent/max ±delta
/mp, bar-green, current/max ±delta //not Kirby
//ep, bar-blue, current/max ±delta //not Kirby

EXP, purple-bar
GP, gold, current

[element]:off, minimal, standard (only for the HUD itself), comprehensive, custom
scaleable radius
12 slots
fade for HUD: auto, toggle, off
HUD: all always on, essentials on and fade rest, all fade, toggle, off
fade speed for elemant: fast, medium, slow.
Status (TL), game time/location/direction/weather (TC), Navigation/Alert (TR) connectivity and wall time
Mission info (tutorial hints),  (beacon), controller state
count, reticle, timers/splits
hotkey (ally info), subtitles, weapon info/equipment mapping
Inventory/Command (BL), Contextual (BC), Enemy Info (BR)/picture-in-picture
[OSC]???

hint/tutorials: off, optional, automatic

AI:
Reaction 0-10
Accuracy(skill) 0-10
Knowledge 0-10 //2 points for mechanics, map, location, equipment, opponents
Priority lazy, vengeance, equalizer
Strategy methodical, statistical, oddball
Attention precise, general
Caution risky, safe	//stealth v aggression

Map colours:
player green
allies blue
neutrals yellow
hostile red
unlocked and visited doors blue
unlocked and non-visited doors yellow
locked doors red
red exclamation mark primary objection
yellow exclamation mark secondary objectives
blue exclamation marks completed objects?
yellow question mark secrets non found
blue question marks secrets found
lighter background = higher ground
normal black
water cyan
lava red/pink
buildings brown/grey

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
audio device
master volume
gameplay volume
cutscene/media volume
menu volume
Event music
diagestic music
ui music
ambience
ui sound effects
weapon sound effects
player sound effects
diagestic sound effects
miscellaneous sound effects
[categorical muting]
voice language
dialog voice
barks and gameplay-relevant voice
chitchat voice
players voice
other players voice for mic chat
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

LT: Aim(FPS)/Target(TPS)	RT: Shoot(Ranged weapon)/Block(Melees weapon)
LB: Low Profile Mod (Sneak)	RB: High Profile Mod (Force/Command)/Binoculars
Dpad (Weapons/Inventory/Stance/(hold) menus)

Network:
Online
Account
Encrypt save data

Graphics:
Gamma correction
Effects
Quality:
	Blood off/mild/maximum
	Gameplay/Cutscene Model/Texture quality for Player/Actor/Object/Environment/Shrubbery Very-Low/Low/Medium/High/Very-High
	Texture Effects duration short/medium/forever
	Shadow Quality
	Lighting Quality
	Reflection off/Quality
	Transparency Quality
	Post Effects //bloom, colour adjustments
	Despawn fade delay short/long/forever
	Particle effects low/med/high
	Draw Distance radius small/medium/large/infinite
	Draw-Distance quality-drop-off scale none/linear/exponential
	Texture scaling none/linear/bilinear/...
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
run,
jump,
swim,
swing,
stab,
block,
aim/targetting?,
throw,
evade,
climb,
grab,
sneak,
cast/shoot,
hack (mechanical skill)
converse,
tinker,
sense,
react,
flex,
endure,
persuade,
bluff,

stats:
Character:
strength (swing, stab, block, throw, climb, grab) v. dexterity
constitution (HP, resistance, knockback) v. agility
intelligence (MP, magic, block, stab?, sneak, cast)
agility (EP, swing, throw, evade, climb, grab, sneak) //speed
dexterity (skill (SP), aim, hack, grab, block, climb, sneak) //reduction
Four-wheel vehicle:
Acceleration (strength)
Durability (constitution)
Boost (intelligence)
Top speed (agility)
Handling (dexerity)
Ship:
Attack power
Durability
Boost
Speed
Handling/aiming? //maybe
Projectile weapon:
Dammage
Penetration
Ammo
Speed/Rate of fire
Range
Melee weapon:
Damage
Penetration
Area
Speed
Duration/Technique //movement while swinging, cancelling, et cetera.

or

attack
defence
magic
mobility
reduction

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

Next Level XP Requirement = floor(8*(1.225^CurrentLevel))
5 stats each with 10 skill levels.
Get 64 skill points per level.
Cost of obtaining a given skill level 2^SkillLevel

resources (social favours)
knowledge,

debuffs:
slow
burn
syphon
freeze
poison

Statistics:
Starts (spawns, state, shoot),
Successes (kill, completed uninterrupted, hit)
Time,
Sum (if applicable; distance per character, damage per attack)
Failures (crashes, defeats, counters)
Players have statistics: not characters.
All-Time Total: //Actually saved.
	mode:
		stage
	character:
		state:
			attack
This session:
This stage (for scoring)
Medals:
Perfect: Take no damage.
Pacifist: Cause no harm.
Moral: No kills.
Psycho: Kill everyone.
Stealth: No alarms.
Ghost: No one even noticed you were there.
Speedy: Beat par-time.
Combo: High combo. //Can combo corpse offset streak
Streak: Sustaining a long kill streak.
Sharp: Never miss.
Collector: Find all hidden collectibles.
Methodical: Collect all items.
Conversational: Talk to a lot of people.
Introvert: Talk to no one.
Foresight: Complete an objective before having it assigned.
Completionist: Clear all objectives.
Ascetic: Minimize collectibles and powerups.
Minimal: Use 'minimal' selected equipment.
Zeroest: Complete stage while depraved of any equipment or items.
Utility: Meet the requirements for several medals in one play through.
Clever: Do something exceptionally clever.


attack, element1 element2, DMG, stun, speed, super cost, super DMG, super stun, range (long medium short)
medium and long are weaker against heavy enemies; short range weapons deal less damage to far away targets
combos: start, hits, finish; low DMG high stun attacks start combo, high DMG low stun attacks finish combos
knockback is derived from damage
speed and stun are related

enemy, element1 element2, HP, class, EXP, gold

Difficulty:
Easy: Recommended for novice players or content tourist. Base attack is doubled and defence is quadrupled. Strong regen is available early in the game. Miracles, criticals, item drops all in effect. Resource management is trivial.
Normal: Recommended for modern players. Criticals and item drops are in effect. Modest regen is available about halfway through the game. Resource management is recommend but not strictly necessary.
Hard: Recommended for action-RPG veterans accustom to old-school difficulty or people who have played the game before. Enemies are more plentiful and more aggressive. Bosses have more attacks. Weak regen is available late in the game. Only items are still in effect. Resource management is required.
Very Hard: Recommended for masters of the game. Like Hard mode except attack and defence are both halved, items cost more and there is no regen at all. Neither miracles, criticals, nor item drops are in effect. Optimal resource management is required. Not recommend for first playthroughs.
Impossible: A gimmick difficulty, this mode is like Very Hard except you die in one hit. Optimal resource management probably still won't be enough.
*/

//DreamPuff-thing-major-minor-patch binary-x86_64-macOS-clang-branch-commit

cno_u8_type CNO_Build_Info_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_BUILD_INFO_H
