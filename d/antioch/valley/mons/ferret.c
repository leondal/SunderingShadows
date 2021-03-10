//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
      object ob;
   ::create();
   set_name("ferret");
   set_short("A quick brown weasel");
   set_id(({"ferret","monster","weasel","brown weasel","quick weasel","quick brown weasel"}));
   set_long("The ferret is definitely a type of weasel, with a thin"+
   " body, long tail, and quick movements it is constantly darting"+
   " about. It is cute in an odd and rather ugly sort of way, kind"+
   " of like how some people consider certain rats cute. It is in"+
   " need of a bath, but you don't think it would appreciate you"+
   " getting close enough to give it one, it seems quite timid.");
   set_race("weasel");
   set_gender("male");
   set_body_type("quadruped");
	set_hd(10,8);
	set_max_level(20);
   set_size(1);
   set_attack_limbs(({"right forepaw","left forepaw","mouth","animal"}));
   set_attacks_num(4);
   set_base_damage_type("slashing");
   set_damage(1,4);
   set_overall_ac(0);
	set_max_hp(random(20)+70);
	set_hp(query_max_hp());
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",10);
//	set_exp(900);
	set_new_exp(10,"low");
	set_property("swarm",1);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
