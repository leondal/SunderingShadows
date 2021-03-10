//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("ice headband");
	set_id(({ "headband", "headband of the winter's chill" }));
	set_short("%^BOLD%^%^WHITE%^Headband of %^CYAN%^Winter's Chill%^RESET%^");
	set_obvious_short("A white headband");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This headband is about two inches wide and cut into a rectangular shape.  What looks to be silk at first actually turns out to be woven crystals of ice, so tightly woven that they seem like silk.  The headband carries a chilling aura about it, causing a fine vapor to rise from it.  The ice crystals in some places are so tightly packed that they have a slight %^CYAN%^blue%^WHITE%^ tint to them.  It seems as if a magical force keeps the ice crystals held together and always cold, they never seem to melt.

AVATAR
	);
	set_lore(
@AVATAR
The Headband of Winter's Chill carries with it a brutal legend.  It is said bands of barbarians to the north wear such headbands as they wander through the artic lands.  The headband some speculate grants one who wears it with a protection from the winter air, allowing the barbarians to move about nearly naked if not fully.  With these headbands in place the "Winter Wolves" as the barbarian rogues are called, are able to perform savage and brutal raids against caravana and anyone unlucky enough to be caught out in a blizzard.  The Winter Wolves are known to prey on boarder towns, to deliver Auril's chilling message to those that think they are immune to the cold or the ways of winter.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" removes the white headband from their head with a slight shiver.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You untie the headband and can't help but to give a slight shiver.");
	return 1;
}
