#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

void create() {
    	::create();
    	set_name("pig");
    	set_id(({"pig","swine","farm_mon"}));
      set_short("a pig");
      set_long("This fat pig is a mottled pink in appearance, "+
         "covered with short, coarse hair.  Dark black spots "+
         "are scattered along its girth, making it only slightly "+
         "distinct from others of its kind.  The pig seems "+
         "unusually fat, perhaps from a rich diet.  It doesn't "+
         "seem all that aware or interested in anything other "+
         "than eating.");
      set_gender(random(2)?"male":"female");
      set_size(1);
    	set_hd(6,2);
    	set_class("fighter");
    	set_mlevel("fighter",6);
      set_race("pig");
      set_body_type("quadruped");
    	set_stats("intelligence",6);
    	set_stats("wisdom",6);
    	set_stats("strength",12); 
    	set_stats("charisma",3);
    	set_stats("dexterity",10);  
    	set_stats("constitution",13);
	set("aggressive",8);
    	set_alignment(5);
    	set_overall_ac(6);
    	set_exp(250);
    	set_max_hp((random(10)+65));
    	set_hp(query_max_hp());
      set_attack_limbs(({"right forepaw","left forepaw","head"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(10);
      set_funcs(({"stink"}));
      set_func_chance(15);
      set_property("swarm",1);
      add_money("gold",random(16)+15);
}

int stink(object *baddies){
   int i;
   baddies = TO->query_attackers();
   if(!baddies) return 0;
   if(!objectp(TO)) return 0;
   tell_room(ETO,"%^BOLD%^%^MAGENTA%^In its fear, the pig "+
      "suddenly emits a horrendous stench!");
   for(i=0;i<sizeof(baddies);i++){
      if(!objectp(baddies[i])) continue;
      if(!objectp(TO)) continue;
      tell_object(baddies[i],"%^RED%^You gag from the smell!");
      baddies[i]->do_damage(baddies[i]->return_target_limb(),roll_dice(1,6));
   }
   return 1;
}