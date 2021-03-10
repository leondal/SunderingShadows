#include <std.h>
#include "../kildare.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("oozling");
	set_id(({"oozling","kildare_mon"}));
	set_short("An oozling");
	set_long("%^BOLD%^%^BLACK%^This tiny puddle of black goo "+
         "seems to have split off from the larger part.%^RESET%^");
	set_race("ooze");
	set_gender("neuter");
	set_body_type("snake");
      remove_limb("mouth");
      remove_limb("head");
      remove_limb("tail");
      add_limb("right puddle","torso",0,0,0);
      add_limb("left puddle","torso",0,0,0);
	set_hd(6,4);
	set_max_level(15);
	set_size(1);
	set_overall_ac(-2);
	set("aggressive",25);
	set_property("swarm",1);
	set_alignment(5);
	set_level(6);
	set_class("fighter");
	set_mlevel("fighter",6);
	set_attack_limbs(({"right puddle","left puddle"}));
	set_attacks_num(2);
      set_hit_funcs((["right puddle":(:TO,"acid":), "left puddle":(:TO,"acid":)]));
	set_damage(1,6);
	set_base_damage_type("bludgeoning");
	set_exp(100);
      set_hp(random(26)+50);
      set_max_hp(query_hp());
}

int acid(object targ){
   if(!random(5)){
      tell_object(targ,"%^BOLD%^%^GREEN%^The acid of the ooze burns "+
         "your skin!%^RESET%^");
      tell_room(ETO,"%^BOLD%^%^GREEN%^The acid of the ooze burns into "+
         ""+targ->QCN+"'s skin!%^RESET%^",targ);
      targ->do_damage(targ->return_target_limb(),(6+random(13)));
   }
   return 3+random(3);
}