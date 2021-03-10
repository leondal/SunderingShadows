//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("riding boots");
	set_id(({ "boots", "leather boots", "earthwalker's boots" }));
	set_short("%^RESET%^%^ORANGE%^Earthwalker's Boots%^RESET%^");
	set_obvious_short("A pair of dirty brown leather boots");
	set_long(
@AVATAR
%^ORANGE%^These riding boots are made from a thick leather.  Looking well worn, the boots have a thick sole with a slight platform of about half an inch.  The hard leather boots are covered with dirt and cacked on mud that looks as if it will never come off.  %^RESET%^Steel%^ORANGE%^ buckles help to keep the boots firmly planted on one's feet, and once on they look as if they are not going anywhere.

AVATAR
	);
	set_lore(
@AVATAR
The Earthwalker's Boots are rare artifacts that come to us from a band of thieves and bandits dedicated to Grumbar.  The theives were rumored to be masters of escape, being able to outslip any patrol after them.  Some legends lay claim that the thieves could walk through earth as if it was nothing, allowing them to slip into places from underground and escape again the same way.  What ever happened to the Earthwalkers, as they came to be known no one knows, or at least no one that is talking.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" unfastens the buckles on their boots and removes them",ETO);
	tell_object(ETO,"%^ORANGE%^You remove yourself from the boots and can't help but feel naked");
	return 1;
}
