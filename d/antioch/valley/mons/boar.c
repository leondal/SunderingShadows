//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
      object ob;
   ::create();
   set_name("boar");
   set_short("An angry wild boar");
   set_id(({"boar","monster","wild boar","angry boar","angry wild boar","animal"}));
   set_long("The boar is quite large with two sharp tusks protruding"+
   " from his mouth. He smells rather bad and is covered in course,"+
   " black hair. He is constantly tossing his head back and forth,"+
   " sniffing the air with his snout. He seems quite agitated about"+
   " something and more than willing to charge whatever he comes"+
   " across.");
   set_race("boar");
   set_gender("male");
   set_body_type("quadruped");
   set_hd(15,6);
   set("aggressive",25);
   set_property("swarm",1);
   set_level(15);
   set_class("fighter");
   set_mlevel("fighter",15);
   set_hp(random(25)+95);
//   set_exp(2200);
   set_new_exp(15,"normal");
   set_max_level(20);
   set_damage(1,10);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_overall_ac(5);
   set_alignment(5);
   add_limb("mouth","head",0,0,0);
   add_limb("tusks","mouth",0,0,0);
   set_attack_limbs(({"tusks","mouth"}));
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
