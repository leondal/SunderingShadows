// Debugging daemon for easy on-off of debug code.
// Garrett started to do this Dec,2003.

#include <std.h>
inherit DAEMON ;

//int combat_hand() {return 1;}
//int dodge_attack_incr() {return 1;}
//int parry_attack_incr() {return 1;}
//int tell() { return 1;}

int grafitti() {return 1;}
int user_new_light() { return 1;}
int perma_death_d() {return 1;}
int funcptr_enabled() { return 1; }
//int monster_new_light() { return 1;}
//int calc_message() {return 1;}

//int battle_new_round() {return 1;}
//int battle_identify_round() { return 1;}
//int scramble_change() { return 1;}
int spell_adminblock() { return 0; }
