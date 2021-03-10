//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
      object ob;
   ::create();
   set_name("fox");
   set_short("A sly fox");
   set_id(({"monster","fox","sly fox","animal"}));
   set_long("This sly little animal is covered in bright red fur,"+
   " making it hard to blend in with anything. Instead it relies on"+
   " its wits to hide itself from predators, often burrowing under"+
   " ground to escape the creatures chasing it. Its face and chest"+
   " are white in color, it has a black nose that delicately sniffs"+
   " the air from time to time, and its triangular ears are also"+
   " tipped in black. It has a long bushy tail and is cute in addition"+
   " to being quite cunning.");
   set_gender("male");
   set_race("fox");
   set_body_type("quadruped");
	set_hd(10,8);
	set_max_level(20);
   set_size(1);
   set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_damage(1,6);
   set_overall_ac(2);
	set_max_hp(random(30)+90);
	set_hp(query_max_hp());
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",10);
//	set_exp(1100);
	set_new_exp(10,"normal");
	set_property("swarm",1);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
