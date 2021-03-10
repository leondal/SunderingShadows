//cleric_istishia.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("chain flail");
	set_id(({ "flail", "chain", "chain of the singing dolphins" }));
	set_short("%^BOLD%^%^CYAN%^Chain of the %^WHITE%^Singing%^CYAN%^ Dolphins%^RESET%^");
	set_obvious_short("An electrum chain flail");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^What looks at first to be a chain flail minus the handle, you quickly realize this is instead something quite different than your normal flail.  Miniature electrum links are joined together to create a four-and-a-half foot long chain.  The metal gleams from lots of polishing, though that does little to hide the ribbons of %^BLUE%^azure blue%^CYAN%^ and %^RESET%^%^CYAN%^aquamarine%^BOLD%^ that travel across the links.  Each end of the chain holds a weighted figurine, made of %^WHITE%^silver%^CYAN%^.  The figurines are carved to look like curved dolphins, as if they were leaping from the sea.  On a closer inspection you notice a series of holes have been carved into the dolphin figurines, similar to that on a flute.  You might be able to use such an odd weapon similar to a flail, you believe, using one of the weighted dolphins to strike at your target.

AVATAR
	);
	set_weight(4);
	set_lore(
@AVATAR
The Chain of the Singing Dolphin was a gift given to the faith of Istishia by a community of merfolk who live below the seas.  The chain, it is said was a relic gifted to the church after a series of long battles that plagues the merfolk by the hands of a band of Talosians, who wished to bring chaos and destruction to not only those above the waves, but below as well.  A small band of clerics were able to stop the actions of the Talosians from craking the earth open and flooding the seas with molten lava.  The Prince of the Merfolk, Thuraganel, was so impressed with the cleric's determination to aid them and the sacrifices they made willingly that he had the chain commishioned as his eternal thanks.

AVATAR
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("flail");
	set_size(2);
	set_wc(1,8);
	set_large_wc(2,4);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int unwield_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" unwraps the electrum chain from their forearm.",ETO);
	tell_object(ETO,"%^CYAN%^You unwrap the chain from your forearm.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" whirls one end of the electrum chain in the air, causing the chain to almost sing before they strike "+targ->QCN+" with a fluid grace.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Whirling one end of the chain into the air, the %^CYAN%^dolphin figurine%^WHITE%^ seems to almost sing before you strike "+targ->QCN+" with a fluid grace.");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" whirls one end of the electrum chain in the air, causing the chain sing a high pitched song before they strike at you with a fluid grace.");
		return roll_dice(2,4)+3;	}
}