//cleric_mask.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("sai");
	set_id(({"sai","dagger"}));
	set_short("%^RESET%^%^CYAN%^Sai of the East%^RESET%^");
	set_obvious_short("A sai");
	set_long(
@AVATAR
%^CYAN%^This strange weapon, called a sai, is shaped almost like a dagger, though it has two curved prongs on each side of the central shaft.  The center shaft is made of metal, and seems quite solid.  Unlike a typical dagger though this shaft of metal is blunt and rounded.  The prongs on each side of the "blade" curve out slightly and are blunt at well.  The handhold of the sai is wraped with an exotic %^BOLD%^silk%^RESET%^%^CYAN%^.

AVATAR
	);
	set_weight(3);
	set_value(900);
	set_lore(
@AVATAR
The Sai of the East is a weapon from a distant land.  The sai looks like a dagger but only is blunt.  There are some rumors of monks who use the sai with deadly accuracy, though are these just legends?

AVATAR
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^CYAN%^You release your hold of the sai");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" twists their sai to the side, striking "+targ->QCN+" twice!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You twist the sai to the side, causing one of the curved prongs to strike "+targ->QCN+"");
	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" twists their sai to the side, striking you twice!");
		return roll_dice(1,4)+1;	}
}