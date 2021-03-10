//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
      object ob;
   ::create();
   set_name("bear");
   set_short("A brown bear");
   set_id(({"monster","bear","brown bear","animal"}));
   set_long("This is a large, shaggy brown bear. His fur is long and"+
   " a bit unkempt, you can see berry juice and honey matted in some"+
   " places. His eyes are a gentle brown, and it is clear he just"+
   " wants to be left alone. His size is incredible, and not all of"+
   " it is fat. You can see black claws at the ends of his paws and"+
   " with a few good swipes this creature could probably take your"+
   " head off.");
   set_gender("male");
	set_race("bear");
	set_body_type("quadruped");
	set_hd(15,8);
	set_max_level(20);
	set_alignment(5);
	set_overall_ac(6);
	set_size(3);
	set_max_hp(random(60)+100);
	set_hp(query_max_hp());
	set_level(15);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("strength",20);
	add_limb("mouth","head",0,0,0);
	set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
	set_attacks_num(3);
	set_base_damage_type("slashing");
	set_damage(1,8);
	set("aggressive",10);
	set_property("swarm",1);
//   set_exp(3500);
     set_new_exp(15,"low");
    set_max_level(20);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
