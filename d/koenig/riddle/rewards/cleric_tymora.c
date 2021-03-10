//cleric_tymora.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("silver coin");
	set_id(({ "coin", "silver coin", "brilliant silver coin", "jornax's lucky coin" }));
	set_short("%^BOLD%^%^BLUE%^Jornax's %^WHITE%^Lu%^BLUE%^c%^WHITE%^ky Coin%^RESET%^");
	set_obvious_short("A brilliant silver coin");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This silver coin is not like any normal coin you have seen before.  The coin glitters brightly with a brilliant radiance, always seeming as if it was fresh from the mint.  On one side of the coin is the image of a jovial female human with short hair and a mischevious smile on her lips, winking up at you.  The opposite side of the coin bears the image of a plump female halfling with the same short hair and that same infectious smile on her lips.  The coin has some heft to it, heavier than any coin you have felt before.

AVATAR
	);
	set_weight(4);
	set_lore(
@AVATAR
This is one of the many lucky coins from a halfling by the name of Jornax.   Jornax some would say was a superstious man, always making sure to perform the needed rites when some unlucky totem crossed his path.  It was not uncommon to see Jornax wearing a horseshoe around his neck, always travelling with at least 3 live rabbits ("for one rabbit's foot is lucky but twelve times as many must be even luckier" he would often say) and numerous other lucky trinkets. Though his luckiest charm was always a bag of silver coins he found one day at the foot of his bed.  Jornax was said to have used his halfling skills at rock throwing with these coins, and no matter how many he threw they always seemed to return to him.

AVATAR
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(1);
	set_wc(1,3);
	set_large_wc(1,3);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" tucks the %^BOLD%^%^WHITE%^silver coin%^BLUE%^ away, placing it in a secure spot.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You tuck the %^WHITE%^silver coin%^BLUE%^ away, keeping such a lucky trinket close by.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" flips a silver coin towards "+targ->QCN+", hitting them soundly with it.  The coin bounces off of "+targ->QCN+" and falls back into "+ETOQCN+"'s hands.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You flip the coin towards "+targ->QCN+", hitting them soundly with the coin.  By %^BLUE%^luck%^WHITE%^ the coin bounces off of them and falls back into your hand.");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" flips a silver coin at you, hitting you soundly with it.  The coin bounces off of you and falls back into "+ETOQCN+"'s hands.");
      if(random(1000) < 250){
         tell_object(ETO,"%^YELLOW%^The coin flashes brilliantly "+
            "as it bounces off "+targ->QCN+"!");
         tell_object(targ,"%^YELLOW%^A silver coin strikes you soundly, "+
            "flashing with a brilliant light!");
         tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+"'s "+
            "coin flashes with a brilliant light as it strikes "+
            ""+targ->QCN+"!",({ETO,targ}));
  	   return roll_dice(3,4)+-1;
	}
}