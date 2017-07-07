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

[element]: minimal, comprehensive, off
scaleable radius
12 slots
fade: auto, toggle, off
Status (TL), game time/location/direction/weather (TC), Navigation/Alert (TR) connectivity and wall time
Mission info, , timers/splits
Count, subtitles, weapon info
Inventory/Command (BL), Contextual (BC), Enemy Info (BR)/picture-in-picture

Display
Graphics
Sound
Text
Input
Controls
Network
System
Game

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
independent/social
technical/humane
lawful/populist
idealism/realism
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

DreamPuff-Competitive/Open-Server/Client-Deamon/NativeExecutable/Embedded-Console/Electron/etc binary-x86_64-macOS-clang-date-commit

cno_u8_type CNO_Build_Info_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_BUILD_INFO_H
