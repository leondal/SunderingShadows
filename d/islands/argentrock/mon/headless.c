#include <std.h>
#include "/d/islands/argentrock/argabbr.h"
#include "/d/common/common.h"

inherit MONSTER;

int flag;

create() {
   ::create();
   set_name("headless");
   set_id( ({"headless","humanoid","argmon"}) );
   set_short("%^BOLD%^%^BLACK%^Headless%^RESET%^");
   set_long("This humanoid creature looks exactly like a human except "+
      "that it is without a head! Yet with no eyes it moves around with "+
      "no difficulty, with no ears it hears perfectly well, with no nose "+
      "it still smells the scent of its prey, with no mouth it can eat "+
      "you alive, with no brain it knows how to set up traps. It is a "+
       "condemned creation, and no one will ever know the reason why "+
	   "such creatures "+
       "are allowed to live. Only rumours that they are the creation of"+
	   " the "+
      "daemons to compete with the creation of the gods, human.");
   switch( random(2) ) {
      case 0:
         set_gender("male");
         break;
      case 1:
         set_gender("female");
         break;
   }
   set_race("headless");
   set_body_type("humanoid");
   set_size(2);
   remove_limb("head");
   set_hd(random(5) + 24,8);
   set_hp(random(200) + 200);
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel( "fighter",query_hd() );
   set_guild_level( "fighter",query_hd() );
   set_alignment(6);
   set("aggressive",12);
   //set_exp( 500*query_hd() );
   set_new_exp(31,"normal");
   set_max_level(36);
   add_search_path("/cmds/fighter");
   set_property("weapon resistance",2);
   set_mob_magic_resistance("low");
   set_property("full attacks",1);
   set_property("swarm",1);
   set_overall_ac(-1);
   add_money("gold",random(500) + 800);
   if( !random(3) ) {
      new(OBJ+"jet_scythe2")->move(TO);
      command("wield scythe");
   }else
     RANDGEAR->armor_me(TO, "shield", 20, 2, 75);
	 RANDGEAR->arm_me(TO, "edgeds", 20, 2, 75);


   flag = 0;
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if( !objectp(ETO) )
      return;
   if( (object *)TO->query_attackers() == ({}) ) {
      if(flag >= 3) {
         tell_room(ETO,"The headless disappears into the bushes.");
         TO->move(PATH+"argpath");
         command("drop all");
         command("offerall");
         TO->remove();
         flag = 0;
         return;
      }

      tell_room(ETO,"The headless searches for its prey.");
      flag++;
   }
}
