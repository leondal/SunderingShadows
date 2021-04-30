//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09

#include <std.h>
#include "../valley.h"
inherit FM_WANDER;

void create(){
      object ob;
	::create();
	set_name("skeleton");
	set_id(({"skeleton","monster","undead"}));
	set_short("A glaring skeleton");
	set_long(
	"A pale skeletal figure stands before you. The skeleton"+
	" was once a human, but now no skin, muscles, or any other"+
	" remanent of humanity save the bones. The eye"+
	" sockets are black and empty, yet the beast can obviously"+
	" see by some magical means, the same way it can move"+
	" about. It glares at you balefully."
	);
	set_gender("male");
	set_race("skeleton");
	set_body_type("human");
	set_size(2);
	set_property("undead",1);
	set_hd(13,3);
    set_max_level(18);
	set_level(13);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",13);
	set_stats("charisma",1);
	set_stats("strength",15);
	set_max_hp(random(25)+150);
	set_hp(query_max_hp());
	set_overall_ac(0);
    set_sight_bonus(2);
//        set_exp(9500);
	set_new_exp(15,"normal");
	set("aggressive",25);
	set_property("swarm",1);
	set_wielding_limbs(({"right hand","left hand"}));
	new(OBJ+"rsword")->move(TO);
	command("wield sword");
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}
