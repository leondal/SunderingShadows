//thief_torm.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("yellow boots");
	set_id(({ "boots", "boots of the lion" }));
	set_short("%^YELLOW%^Boots of the Lion%^RESET%^");
	set_obvious_short("A pair of tawny yellow leather boots");
	set_long(
@AVATAR
%^YELLOW%^These riding boots are made from the hide of a lion.  The golden tawny fur has been treated as to never loose it's luster and shine.  The riding boots come to mid-shin and feature slighty hard soles, but with some give.  The lion is seen as Torm's totem animal, and many say that Torm rides into battle on the back of a golden lion called Nobanion when he must do battle. The tops of the boots are trimed with a shaggy golden fur, possibly the mane of the lion.  The leather is well cared for and the boots seem nearly flawless.

AVATAR
	);
	set_lore(
@AVATAR
The Boots of the Lion are a prized item by the faith of Torm.  The boots are rumored to give the faithful of Torm the strength and courage of a lion when worn, but only those faithful to Torm.  There are rumors that anyone who tires to wear the boots and unworthy to do so find themselves missing a leg or two, as if the boots ate their limb!

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" pulls off the lionskin boots and places them in a safe place.",ETO);
	tell_object(ETO,"%^YELLOW%^You remove the boots, but take care to keep the safe.  Such a rare gift should be cherished.");
	return 1;
}
