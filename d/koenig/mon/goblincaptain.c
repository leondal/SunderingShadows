#include <std.h>
#include <daemons.h>
inherit MONSTER;

int dlevel;

create() {
    	::create();
	set_name("goblin");
	set_id( ({ "goblin", "captain"," goblin captain" }) );
	set_race("goblin");
	set_gender("male");
	set_short("A goblin captain");
	set_long("A very slimy and stinky goblin captain.\n");
	dlevel = random(3) + 6;
	set_level(dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(1);
   	set_stats("intelligence",6 + dlevel);
   	set_stats("wisdom",4 + dlevel);
   	set_stats("strength",13 + dlevel);
   	set_stats("charisma",3);
   	set_stats("dexterity",8 + dlevel);
   	set_stats("constitution",7);
	set_hd(dlevel, 8);
   	set_max_hp(15+(dlevel * (random(10) + 2)));
    	set_hp(query_max_hp());
   	set_max_level(8);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new("/d/common/obj/weapon/dagger")->move(TO);
      		command("wield dagger");
        	new("/d/common/obj/armour/leather")->move(TO);
      		command("wear leather");
	add_money("silver",random(2) * dlevel);
	add_money("copper",random(5) * dlevel);
	add_money("electrum",random(2) * dlevel);
	//set_exp(dlevel * 25);
   	set_exp(dlevel * 100);
    	set_emotes(2,({
		"Goblin stumbles around.\n",
		"Goblin picks his nose.\n",
		"Goblin eyes you warily.\n",
		"Goblin scurries about the room.\n",
		"Goblin jumps up and down.\n",
		"Goblin growls at you in a laughable high pitched voice.\n"
    	}),0);
}
