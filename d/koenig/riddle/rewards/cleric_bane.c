//cleric_bane.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("morning star");
	set_id(({ "morning star", "scepter", "star", "scepter of the tyrant's reign" }));
	set_short("%^BOLD%^%^BLACK%^Scepter of the %^GREEN%^Tyrant's%^BLACK%^ Reign%^RESET%^");
	set_obvious_short("A morning star");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Fashioned out of steel, this ornate morning star looks lavish and rich.  The long steel handle is carved with images of eyes peering out of the blackened steel.  The eyes are actually made of %^GREEN%^emeralds%^BLACK%^  and %^GREEN%^bl%^RED%^ood%^GREEN%^stones%^BLACK%^, giving an eerie life like glimmer to them.  Inlays of %^YELLOW%^gold%^BLACK%^ and %^WHITE%^platinum%^BLACK%^ bands wrap around the cylindrial handle. A large square cut %^GREEN%^emerald%^BLACK%^ is set into the bottom of the handle, clutched by three black talons. The top of the morning star is set with a solid sphere, made up of %^YELLOW%^gold%^BLACK%^ and %^WHITE%^platinum%^BLACK%^, the metals set in a rigid orderly pattern.  Blackened steel spikes rise out of the gilded sphere, sharpened to fine deadly points.

AVATAR
	);
	set_weight(7);
	set_lore(
@AVATAR
The Scepter of the Tyrant's Reign is veiwed as many as the divine symbol of The Black Hand's right to rule the lands.  It is said the Tyrant allows only those who are of noble blood to even wield the scepter effectively.  There is a history that each tyrant, warlord, or nobleman who's managed to carve out a bloody dynasty in these lands has come about due to the scepter's arrival in their hands.

AVATAR
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You unwield the morning star, keeping such a lavish treasure close.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+" tears into "+targ->QCN+" with a forceful blow.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^You tear into "+targ->QCN+" with a brutal blow, showing them just who is in charge here.");
	tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" tears into you with a forceful blow.");
		return roll_dice(3,4)+-1;	}
}