//thief_beshaba.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("boots");
	set_id(({"boots","boots of the red rat","rat boots","black leather boots","leather boots"}));
	set_short("%^BOLD%^%^BLACK%^Boots of the %^RED%^Red Rat%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A pair of black leather boots%^RESET%^");
	set_long(
@CYTHERA
%^BOLD%^%^BLACK%^Crafted from dark black leather, these soft boots have been embroidered with images of %^BOLD%^%^RED%^red rats%^BOLD%^%^BLACK%^.  Running up the front of the boots are a series of suede laces, allowing the wearer to adjust them as needed.  The thick soles of the leather boots are soft and flexible, but have been padded for protection.  Stitched into the leather is a pattern of %^BOLD%^%^RED%^rats%^BOLD%^%^BLACK%^ that flow downwards, with their long tails whipping behind them.  The %^YELLOW%^yellow%^BOLD%^%^BLACK%^ eyes of the rats give them a deranged appearance.%^RESET%^
CYTHERA
	);
	set_lore(
@CYTHERA
Rats have always been sacred to Beshaba, as minute agents to spread calamity and misfortune to people.  The Red Rat Bastards were a group of rogues that preyed on people in cities and along highways, making sure that the misfortunes of Beshaba were felt by all.  The Rat Bastards, as they were more commonly known, became quite rich in their raids and thievery, to a point where they started to act in the open.  Known for their black boots embroidered with red rats, the Red Rat Bastard's were also rumored to have be lead by a dynasty of wererats.
CYTHERA
	);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your feet feel naked and exposed.");
	return 1;
}
