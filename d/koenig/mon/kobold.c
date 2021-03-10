#include <std.h>
#include <daemons.h>
inherit MONSTER;

int dlevel;

create() {
    	::create();
	set_name("kobold");
	set_id( ({ "kobold" }) );
	set_race("kobold");
	set_gender("male");
	set_short("A dirty kobold");
	set_long("A very dirty and smelly kobold\n");
	dlevel = random(3) + 4;
	set_level(dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(1);
   	set_stats("intelligence",6 + dlevel);
   	set_stats("wisdom",4);
   	set_stats("strength",8 + dlevel);
   	set_stats("charisma",3);
   	set_stats("dexterity",9);
   	set_stats("constitution",11);
	set_hd(dlevel, 8);
   	set_max_hp(15+(dlevel * (random(10) + 1)));
    	set_hp(query_max_hp());
   	set_hp(query_max_hp());
   	set_max_level(7);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new("/d/common/obj/weapon/dagger")->move(TO);
      		command("wield dagger");
	add_money("silver",random(5) * dlevel);
	add_money("copper",random(10) * dlevel);
	//set_exp(dlevel * 20);
   	set_exp(dlevel * 100);
    	set_emotes(2,({
		"Kobold looks around quickly.\n",
		"Kobold scratches himself absentmindedly.\n",
		"Kobold eyes you warily.\n",
		"Kobold sniffs the air.\n",
		"Kobold yips in his high pitched voice.\n"
    	}),0);
}
