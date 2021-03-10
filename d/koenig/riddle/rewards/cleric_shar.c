//cleric_shar.c - Designed by Shar, coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("chakram");
	set_id(({ "chakram", "black disk", "chakram of night's secrets" }));
	set_short("%^BOLD%^%^BLACK%^Chakram of %^RESET%^%^MAGENTA%^Night's%^BOLD%^%^BLACK%^ Secrets%^%^RESET%^");
	set_obvious_short("A chakram made of jet");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Pure black jet has been shaped into this round disk, called a chakram.  The jet has been polished to a high sheen, giving it a slick and wet apperance.  The chakram is an exotic weapon that few ever master or try to learn.  By throwing the disk in combat, the wielder hopes to stike their target with the blunt weapon. It takes time to practice aiming the disk, but once mastered one can easily strike from a safe distance.  This chakram features a handguard in the middle of the disk, with a slick soft leather wrapped around it.  The outer edge of the chakram is set with round %^RESET%^%^MAGENTA%^amethyst%^BOLD%^%^BLACK%^ gems, into the jet.

AVATAR
	);
	set_weight(4);
	set_lore(
@AVATAR
The Chakram of Night's Secrets is a weapon that was once used by a woman named Elthezel Urnigarlou.  Elthezel mastered the use of the chakram in combat, as to strike at her foes from a safe distant.  It is rumored that Elthezel had her favorite chakram enchanted as to always return to her when thrown, so she would never be without her favorite weapon.  Elthezel though did manage to lose her favorite weapon and her life on the night of 21 Autumnstime, 618 when she encounterd a band of intoxicated women driven mad.

AVATAR
	);
   set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,4);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You release your hold of the chakram, keeping the sacred weapon of %^RESET%^%^MAGENTA%^Shar%^BOLD%^%^BLACK%^ close by.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^After tossing the chakram at "+targ->QCN+" it returns to "+ETOQCN+" 's hand.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^After tossing the chakram at "+targ->QCN+" it returns to your hand!");
	tell_object(targ,"%^BOLD%^%^BLACK%^After tossing the chakram at you it returns to "+ETOQCN+" 's hand.");
      if(random(1000) < 250){
         tell_object(ETO,"%^BOLD%^%^MAGENTA%^The chakram glows with a "+
            "violet aura as a solid blow is landed on "+targ->QCN+"!");
         tell_object(targ,"%^BOLD%^%^MAGENTA%^A disk glowing with a violet aura "+
            "stikes you soundly, chilling you to your very core.");
         tell_room(environment(query_wielded()),"%^BOLD%^%^MAGENTA%^After "+ETOQCN+" "+
            "hefts the chakram with all "+ETO->QP+" "+
            "might at "+targ->QCN+", the disk begins to shed a violet glow "+
            "just before contact.",({ETO,targ}));
  	   return roll_dice(3,4)+-1;
	}
}