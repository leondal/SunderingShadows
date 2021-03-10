//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("raccoon");
   set_short("A sneaky raccoon");
   set_id(({"raccoon","monster","sneaky raccoon","animal"}));
   set_long("This raccoon obviously thinks it's quite sneaky as it"+
   " carefully moves about, scrounging for food. Its fur is mostly"+
   " a greyish color and it has black stripes down its back and"+
   " over its bushy tail. Its face is mostly white in front with"+
   " a black mask, almost making it look like a thief. It has tiny"+
   " paws with a few black claws on them and some rather sharp"+
   " looking teeth.");
   set_race("racoon");
   set_gender("female");
   set_body_type("quadruped");
	set_hd(10,8);
	set_max_level(20);
   set_size(1);
   set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_damage(1,10);
   set_overall_ac(2);
	set_max_hp(random(30)+90);
	set_hp(query_max_hp());
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",10);
//	set_exp(1100);
	set_new_exp(10,"normal");
	set_property("swarm",1);
}
