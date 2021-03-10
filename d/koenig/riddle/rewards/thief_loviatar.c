//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("black leather boots");
	set_id(({ "boots", "spiked leather boots", "black leather boots", "leather boots" }));
	set_short("%^BOLD%^%^WHITE%^Sp%^RED%^i%^WHITE%^k%^RED%^e%^WHITE%^d %^BLACK%^Black Leather Boots%^RESET%^");
	set_obvious_short("A pair of black leather boots");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These boots have a wicked air to them.  The main part of the boots is made of a soft black leather that still has plenty of give.  The boots are fashioned to be about knee length and look as if they would mold to the wearer's leg.  The boots have then been decorated with %^WHITE%^steel spikes%^BLACK%^.  Across the toe of the boot a row of short spikes rise up, though they never get bigger than a quarter of an inch.  A row of spikes on a leather band cross the back of the boot, across the heel.  Wider fatter spikes have been set into the leather up the sides of the boot in an orderly fashion.  A rounded disk of leather finishes off the tops of the boots, with a series of spikes that rise up.   The leather disk looks as if it attaches to one's leg by way of a leather strap, that is attached to the main body of the boots.  Some of the spikes look as if they have %^RESET%^%^RED%^dried blood%^BOLD%^%^BLACK%^ on them.

AVATAR
	);
	set_lore(
@AVATAR
These spiked boots are prized by followers of Loviatar, no doubt for thier sinister apperance.  The boots seem to be attributed to one man of the faith Elemor Ralethan, a half-elven male who mastered a flashy form of combat that utalized the spikes on the boots to his advantage.  Elemor found delight in the pain he was able to administer with these boots.  

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the black leather boots with much effort, slicing their hand on one of the spikes in the process.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You pull the boots off with much effort, cutting yourself on one of the spikes.");
	ETO->do_damage("torso",random(4));
	return 1;
}
