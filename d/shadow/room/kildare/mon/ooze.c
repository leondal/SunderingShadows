#include <std.h>
#include "../kildare.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("black pudding");
	set_id(({"black pudding","pudding","ooze","puddle","kildare_mon"}));
	set_short("A harmless puddle");
	set_long("%^BOLD%^%^BLACK%^This is a small puddle of black "+
         "goo that nearly fades into the dark surface of the "+
         "rock floor.  Surely it is harmless.%^RESET%^");
	set_race("ooze");
	set_gender("neuter");
	set_body_type("snake");
      remove_limb("mouth");
      remove_limb("head");
      remove_limb("tail");
      add_limb("right puddle","torso",0,0,0);
      add_limb("left puddle","torso",0,0,0);
	set_hd(12,4);
	set_max_level(15);
	set_size(1);
	set_overall_ac(-4);
	set("aggressive",25);
	set_property("swarm",1);
	set_alignment(5);
	set_level(12);
	set_class("fighter");
	set_mlevel("fighter",12);
	set_attack_limbs(({"right puddle","left puddle"}));
	set_attacks_num(4);
      set_hit_funcs((["right puddle":(:TO,"acid":), "left puddle":(:TO,"acid":)]));
	set_funcs(({"split"}));
	set_func_chance(15);
	set_damage(1,6);
	set_base_damage_type("bludgeoning");
	set_exp(2500);
      set_hp(random(75)+150);
      set_max_hp(query_hp());
	set_emotes(10,({
         "%^BOLD%^%^WHITE%^The ooze solidifies and strikes out!%^RESET%^",
         "%^BOLD%^%^WHITE%^The ooze seems to melt into the floor before returning to attack!%^RESET%^"
	}),1);
}

int acid(object targ){
   if(!random(6)){
      tell_object(targ,"%^BOLD%^%^GREEN%^The acid of the ooze burns "+
         "your skin!%^RESET%^");
      tell_room(ETO,"%^BOLD%^%^GREEN%^The acid of the ooze burns into "+
         ""+targ->QCN+"'s skin!%^RESET%^",targ);
      targ->do_damage(targ->return_target_limb(),(6+random(5)));
   }
   return 3;
}

void die(object obj) {
      "/d/common/daemon/randstuff_d"->find_stuff(TO,"random",random(5)+1);
	tell_room(ETO,"%^BOLD%^%^BLACK%^As the black pudding dies, "+
         "its body disperses, leaving behind something.%^RESET%^");
    	::die(obj);
}

void split(){
   tell_room(ETO,"%^BOLD%^%^CYAN%^Suddenly, the black pudding "+
      "splits, creating an oozling!%^RESET%^");
   new(MON"oozling")->move(ETO);
   return;
}