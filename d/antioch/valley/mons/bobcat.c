//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
      object ob;
   ::create();
   set_name("bobcat");
   set_short("A sleek bobcat");
   set_id(({"monster","cat","sleek bobcat","bobcat","animal"}));
   set_long("The bobcat is a truly remarkable predator. It is the"+
   " ancestor of the common cat and is somewhat larger and much"+
   " more fierce. It has two black tufts extending from the tips of"+
   " its ears. Golden yellow eyes watch you carefully from within"+
   " a typically feline face. Its thick coat is mostly striped to"+
   " blend in with the surrounding forests and fields. Despite its"+
   " resemblance to a cat, it is undoubtedly a skilled hunter.");
   set_race("cat");
   set_gender("female");
   set_body_type("quadruped");
   set_size(1);
   set_hd(15,6);
   set("aggressive",15);
   set_property("swarm",1);
   set_level(15);
   set_class("fighter");
   set_mlevel("fighter",15);
   set_hp(random(25)+95);
//   set_exp(2200);
   set_new_exp(15,"normal");
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
