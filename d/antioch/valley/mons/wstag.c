//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit V_WANDER;

void create(){
      object ob;
	::create();
	set_name("wild stag");
	set_id(({"stag","wild stag","monster"}));
	set_short("A wild stag");
	set_long(
	"The stag stands proudly, confident in his reign of the valley,"+
	" awaiting for someone to challenge his position. He is large,"+
	" easily standing six feet tall. His antlers look sharp but"+
	" well accustomed to fights. He stamps his feet and snorts,"+
	" watching you closely."
	);
	set_race("deer");
	set_gender("male");
	set_body_type("equine");
	set_hd(10,8);
	set_max_level(20);
	add_limb("antlers","head",0,0,0);
	set_attack_limbs(({"antlers","right front hoof","left front hoof"}));
	set_attacks_num(3);
	set_base_damage_type("bludgeoning");
	set_damage(1,10);
	set_alignment(8);
	set_overall_ac(7);
	set_max_hp(random(200)+100);
	set_hp(query_max_hp());
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",10);
//	set_exp(2015);
	set_new_exp(10,"normal");
	set_property("swarm",1);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
