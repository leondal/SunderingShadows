//Octothorpe (1/22/09)
//Underdark Mining Caverns, Flowstone Elemental

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit WEAPONLESS;

int timer;

void create(){
   ::create();
   set_name("flowstone elemental");
   set_id(({"flowstone elemental","elemental","flowstone"}));
   set_short("%^RESET%^bulbous fl%^BOLD%^o%^RESET%^wst%^BOLD%^o%^RESET%^"+
      "ne elemental");
   set_long("%^RESET%^This creature is about three feet tall, and is nearly "+
     "as wide. Stubby appendages that appear to be arms and legs "+
     "can be identified on the elemental if you use your imagination. "+
     "Based on its dimensions, your first impression might be that this "+
     "elemental cannot move with great alacrity, nor could it be that "+
     "dangerous...");
   set_race("flowstone elemental");
   set_alignment(5);
   set_gender("neuter");
   set_body_type("human");
   set_hd(17,1+random(2));
   set_overall_ac(-8);
   set_size(1);
   set_max_level(20);
   set_max_hp(100+random(95));
   set_hp(query_max_hp());
   set_property("swarm",1);
   set("aggressve",15);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_damage(2,10);
   set_stats("strength",18);
   set_stats("dexterity",8);
   set_stats("constitution",19);
   set_stats("intelligence",5);
   set_stats("wisdom",11);
   set_stats("charisma",11);
   set_new_exp(17,"low");
}

