#include <std.h>
#include <daemons.h>
#include "./melnmarn.h";
inherit MONSTER;

int dlevel;

create() {
    	::create();
   	set_name("bat");
   	set_id( ({ "giantbat","bat", "giant bat" }) );
   	set_short("A giant bat");
   	set_long("A giant bat.\n");
    	set_gender(random(2)?"male":"female");
   	dlevel = random(3) + 3;
   	set_level(dlevel);
   	set_race("bat");
   	set_body_type("fowl");
   	set_alignment(2);
   	set_hd(dlevel,6);
   	set("aggressive",20);
   	set_size(2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",3);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_hp(10+(dlevel * (random(10) + 2)));
    	set_hp(query_max_hp());
   	set_max_level(7);
   	//set_exp(dlevel*20);
   	set_exp(dlevel * 100);
    	set_emotes(1,({
		"Bat squeaks.\n",
		"Bat flaps around wildly.\n",
		"Bat swoops at your head.\n"
    	}),0);
}

