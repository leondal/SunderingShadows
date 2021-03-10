//ranger_auppenser.c - Reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("auppenser bow");
   set_id(({"blue long bow","bow","longbow","long bow","bow of the serenity","blue bow"}));
   set_obvious_short("%^BOLD%^%^CYAN%^A blue long bow%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Bow of %^BOLD%^S%^RESET%^%^CYAN%^e%^BOLD%^"+
		"%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^i"+
		"%^BOLD%^%^CYAN%^t%^BOLD%^%^CYAN%^y%^RESET%^");
   set_long(
@CYTHERA
%^CYAN%^Fashioned out of rare blue wood, this slender long bow has smooth flowing lines.  Down the front of the bow five %^BOLD%^%^WHITE%^crystals%^RESET%^%^CYAN%^ have been set into the wood.  Emitting a slight humming noise, the crystals stored bits of psionic energy within them.  Gilded %^ORANGE%^copper%^CYAN%^ bands encircle each crystal. The hand hold of the blue wood bow is made from %^BOLD%^%^BLACK%^black leather%^RESET%^%^CYAN%^ giving the user a soft surface to grasp onto.  Strung with a copper laced string, the bow resonates a serene sound when released.  
CYTHERA
   );
   set_lore(
@CYTHERA
Rangers of Auppenser have always been a rare thing, even back when The Lord of Reason's faith was strong.  Though there are a rare few that find their way to the enlightenment that Auppenser teaches his followers.  The rangers of Auppenser use to claim that the Enlightened One opened their minds to see more of the forests, plains, dunes, and other locations that they watched over.  With this enlightenment, the rangers felt they were better in their mission.  Most of the rangers were in a sect called the Roaming Eyes of Auppenser.
CYTHERA
   );
   	set_property("lore difficulty",12);
	set_unwield("%^CYAN%^The serene feeling leaves you as you unwield the bow.");
}