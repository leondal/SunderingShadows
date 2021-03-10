//ranger_sune.c - Reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("sune bow");
   set_id(({"ivory and gold bow","bow","longbow","long bow","heartwarden's bow","ivory bow"}));
   set_obvious_short("%^BOLD%^%^WHITE%^An ivory and %^YELLOW%^"+
		"gold%^BOLD%^%^WHITE%^ bow%^RESET%^");
   set_short("%^RESET%^%^RED%^Heartwarden's %^BOLD%^%^WHITE%^B%^YELLOW%^o"+
		"%^BOLD%^%^WHITE%^w%^RESET%^");
   set_long(
@CYTHERA
%^BOLD%^%^WHITE%^Fashioned out of ivory, this slender long bow gracefully curls inwards at either end.  Gilded %^YELLOW%^gold%^BOLD%^%^WHITE%^ bands wrap around the body of the ivory bow, adding an aesthetically appealing touch.  A %^RESET%^%^RED%^deep crimson%^BOLD%^%^WHITE%^ leather band wraps around the center of the bow, creating a soft handhold.  The ivory bow has been strung with a thin, but extremely strong, string of braided %^RESET%^%^RED%^deep crimson%^BOLD%^%^WHITE%^ and %^YELLOW%^gold%^BOLD%^%^WHITE%^ threads.  When released the string almost seems to sing in a crystal clear melody.%^RESET%^
CYTHERA
   );
   set_lore(
@CYTHERA
The Heartwardens were a small band of rangers dedicated to Sune Firehair.  The rangers venerated Sune for the sights of beauty the found in the natural world.  Serene groves bursting with life, the way a brook weaved through a dense forest, and other such locations brimming with the beauty of nature were seen as sacred places to the ranger.  Wishing to protect nature's beauty, the Heartwardens began to police the forests.  They often came into battle with agents of Malar, Auril, and Talos, the Lord of Fury.  This sacred bow, it was said, was only given to those rangers who fought with passion and bravery in the name of Sune Firehair.  The rangers in time also began to provide safe passage to young lovers fleeing to find better lives together.
CYTHERA
   );
   	set_property("lore difficulty",12);
	set_unwield("%^RED%^The warmth radiating from the bow leaves as you unwield the bow.");
}