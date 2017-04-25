//cno_build_info.h: Runtime readable build information

#ifndef CNO_BUILD_INFO_H
#define CNO_BUILD_INFO_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

cno_u8_type CNO_Build_String[CNO_BUFFER_MAXSIZE];

/*
water //slow
fire //burn
ice //freeze
rock //effective against heavy
holy //effective against light
dark //poison
bio //effective against medium

attack, element1 element2, DMG, stun, speed, super cost, super DMG, super stun, range (long medium short)
medium and long are weaker against heavy enemies
combos: start, hits, finish; low DMG high stun attacks start combo, high DMG low stun attacks finish combos
knockback is derived from damage
speed and stun are related

enemy, element1 element2, HP, class, EXP, gold
*/

cno_u8_type CNO_Build_Info_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_BUILD_INFO_H
