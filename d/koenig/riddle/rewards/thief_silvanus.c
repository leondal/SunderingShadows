//thief_silvanus.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("leaf boots");
	set_id(({ "boots", "leafwalker boots", "boots of the leafwalkers" }));
	set_short("%^RESET%^%^GREEN%^Boots of the Leafwalkers%^RESET%^");
	set_obvious_short("A pair of soft boots made from leaves");
	set_long(
@AVATAR
%^GREEN%^Crafted from oak leaves, these soft boots look very comfortable.  The tops of the boots rise up to a rounded point in the front.  The toes of the boots also feature a rounded slightly pointed edge, giving them an almost fey like quality.  The oak leaves look extremely hardy and green, never wilting of changing their color.  The soles of each boot is finished off with compressed oak leaves to form a soft padding.

AVATAR
	);
	set_lore(
@AVATAR
The Boots of the Leafwalkers are attributed to a band of faeries who followed the Oak Father.  It is said that with these boots these fey creatures where able to move about the tree tops with ease, and without disturbing a single leaf.  The fey are known for their mischevious nature and love of playing tricks on mortal folk, from elves to humans.  The Leafwalkers were no diffrent and with these boots it is said they were able to frighten and spook travelers who got to close to their ancient grove.  If these boots are a relic of the famous Leafwalkers or just a copy it is hard to tell.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" removes a pair of leaf boots very slowly, almost as if they did not want to take the off.",ETO);
	tell_object(ETO,"%^GREEN%^You remove the boots and find that you already miss the soft comfort the boots provided.");
	return 1;
}
