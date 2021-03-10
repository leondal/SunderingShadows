//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
      object ob;
   ::create();
   set_name("cougar");
   set_short("A sleek hunting cat");
   set_id(({"cat","monster","cougar","sleek cat","hunting cat","sleek hunting cat","animal"}));
   set_long("The cat is well muscled and in good shape. It has a sleek"+
   " tan coat with white on its face and chest. Hazel eyes stare at"+
   " you and its whiskers twitch as it sniffs the air. The cougar"+
   " is almost three feet tall, and is about four feet long with a"+
   " darker tail that seems to be three feet in length. You can see"+
   " its muscles tensed and ready to pounce.");
   set_gender("female");
   set_body_type("quadruped");
   set_hd(15,6);
   set_race("cat");
   set("aggressive",15);
   set_property("swarm",1);
   set_level(15);
   set_class("fighter");
   set_mlevel("fighter",15);
   set_hp(random(25)+95);
//   set_exp(2200);
   set_new_exp(15,"low");
   set_max_level(20);
   set_damage(1,8);
   set_stats("strength",18);
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_overall_ac(4);
   set_alignment(5);
   add_limb("tail","torso",0,0,0);
   add_limb("mouth","head",0,0,0);
   set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
