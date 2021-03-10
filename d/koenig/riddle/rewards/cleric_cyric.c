//cleric_cyric.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("blunt sword");
	set_id(({ "sword", "blunt sword", "black sword", "dark sun's blade" }));
	set_short("%^BOLD%^%^BLACK%^The Dark %^WHITE%^Sun's%^BLACK%^ Sword%^RESET%^");
	set_obvious_short("A black long sword");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Made of blackened steel, this metal blade is shaped to look like a long sword.  The %^WHITE%^bone%^BLACK%^ hilt of the blade has been carved into a twisting spiral shape, with a %^WHITE%^silver%^BLACK%^ jawless skull set into the bottom.  The blade of the sword is long and narrow, typical of long swords, though this one seems to carry a curious trait.  The edge of the blade has not been sharpened. In fact the design of the blade itself seems as if the creator intended for this sword to provide blunt damage, instead of the typical slashing.  A geometrical pattern of squares and circles has been etched into the steel blade.  A most curious weapon.

AVATAR
	);
	set_weight(6);
	set_lore(
@AVATAR
The Dark Sun's Blade was made by a maurader priest of Cyric's faith around the year 634.  The cleric, who's name has alread been forgotten, so wished to emulate his Dark Lord in combat.  Tired of the use of maces and flails to strike the message of Cyric into the hearts of others, he began to take up the art of weaponsmithing.  With his new found skills he began to fashion a sword that is a copy of the divine blade the Dark Sun is said to wield in battle.  The cleric though did not seem to get to use the blade for very long, as he meet with a messy end at the hand of a small band of Tormtars in the Daggerdale area.  His blade was thought destroyed, but it would seem they thought wrong.

AVATAR
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^MAGENTA%^You unwield the blade, but keep such a sacred treasure close.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 285){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" twists their black sword around to bash into "+targ->QCN+" again, as a cruel delight shines in their eyes.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You twist the Dark Sun's Blade back around again to strike "+targ->QCN+" twice.");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" twists their black sword around to bash into you again, as a cruel delight shines in their eyes.");
		return roll_dice(3,4)+-1;	}
}