#include "/d/dagger/aketon/short.h"

inherit WEAPONLESS;

create() {
   ::create();
   set_name("maxian");
   set_id( ({"maxian","treasurer"}) );
   set("short","Maxian the Aketon treasurer");
   set("long","Maxian is an elf with a medium build. He wears a suit and a tie. "
      "Sitting behind the desk he is busy calculating the funds that the "
      "city has now, and planning the expenditure of the city in the "
      "future.");
   set_gender("male");
   set_race("elf");
   set_body_type("humanoid");
   add_limb("left hand","torso",0,0,0);
   add_limb("right hand","torso",0,0,0);
   set_attack_limbs( ({"left hand","right hand"}) );
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_damage(3,8);
   set_hd(20,8);
   set_hp(200);
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",20);
   set_guild_level("fighter",20);
   set_alignment(5);
   set("aggressive",0);
   set_exp(1000);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_property("no death",1);
   set_property("no steal",1);
   set_overall_ac(8);
   add_money("gold",500+random(100));
   add_money("silver",500+random(100));
}
