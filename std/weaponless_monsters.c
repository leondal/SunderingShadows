/*The inclusion of execute_attack in this file caused problems with feats because it apparently overrides combat. After testing, I have removed the execute_attack function in this file. If this causes unforeseen problems, there is a backup of the original in /std/weaponless_monsters.circe ~Circe~ 2/12/13*/
//For hand to hand monsters

// folded this into /std/monster.c
// if there are any problems, see /std/monster.bak and /std/weaponless_monsters.bak -Ares

#include <std.h>
#include <daemons.h>

inherit MONSTER;
