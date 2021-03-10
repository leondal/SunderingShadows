#include <std.h>
#include <daemons.h>
inherit MONSTER;

create() {
    	::create();
   	set_name("lizard");
   	set_id( ({ "lizard","iguana"}) );
   	set_short("a lizard");
   	set_level(3);
   	set_long("This is a small violent lizard, snapping wildly at you.\n");
   	set_race("lizard");
    	set_gender(random(2)?"male":"female");
   	set_body_type("quadruped");
   	set_wielding_limbs(({"mouth"}));
   	set_alignment(2);
   	set("aggressive",20);
   	set_size(1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",5);
   	set_stats("charisma",3);
   	set_stats("dexterity",18);
   	set_stats("constitution",14);
   	set_hd(3,6);
    	set_max_hp(random(20) + 20);
      set_hp(query_max_hp());
   	set_max_level(6);
   	new("/d/shadow/mon/obj/fangs")->move(TO);
   	command("wield fangs in mouth");
   	//set_exp(100);
    set_exp(500);
    	set_emotes(2,({
		"Lizard hisses and lunges at you.\n",
		"Lizard licks its eye.\n",
		"Lizard moves around slowly.\n",
		"Lizard claws at the ground.\n",
		"Lizard whips his tail around agitatedly.\n"
    	}),1);
}

