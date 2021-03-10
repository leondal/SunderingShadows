#include <std.h>
#include <daemons.h>
inherit MONSTER;

int dlevel;

create() {
    	::create();
	set_name("goblin");
	set_id( ({ "goblin" }) );
	set_race("goblin");
	set_gender("male");
	set_short("A young goblin");
     	set_long("A very ugly and stinky goblin.\n");
	dlevel = random(3) + 5;
	set_level(dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(1);
   	set_stats("intelligence",(6 + dlevel));
   	set_stats("wisdom",4);
   	set_stats("strength",(10 + dlevel));
   	set_stats("charisma",3);
   	set_stats("dexterity",(8 + dlevel));
   	set_stats("constitution",7);
	set_hd(dlevel, 8);
   	set_max_hp(15+(dlevel * (random(10) + 1)));
    	set_hp(query_max_hp());
   	set_max_level(7);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new("/d/common/obj/weapon/shortsword")->move(TO);
       command("wield sword");
	add_money("silver",random(5) * dlevel);
	add_money("copper",random(10) * dlevel);
   	//set_exp(dlevel * 20);
	set_exp(dlevel * 100);
    	set_emotes(2,({
		"Goblin stumbles around.\n",
		"Goblin picks his nose.\n",
		"Goblin eyes you warily.\n",
		"Goblin scurries about the room.\n",
		"Goblin jumps up and down.\n"
    	}),0);
}
