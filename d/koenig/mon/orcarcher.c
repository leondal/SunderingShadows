#include <std.h>
#include <daemons.h>
inherit MONSTER;
int dlevel;

create() {
    	::create();
    	set_name("archer");
    	set_id( ({ "orc", "orc archer", "an archer", "archer" }) );
    	set_race("orc");
    	set_gender("male");
    	set_short("An orc archer");
    	set_long("An ugly yet dextrous orc archer.\n");
    	dlevel = random(3) + 6;
    	set_level(dlevel);
    	set_body_type("human");
    	set_class("fighter");
    	set("aggressive", 0);
    	set_alignment(8);
    	set_size(2);
    	set_stats("intelligence",12);
    	set_stats("wisdom",12);
    	set_stats("strength",10 + dlevel);
    	set_stats("charisma",3 + dlevel);
    	set_stats("dexterity",16);
    	set_stats("constitution",11);
    	set_hd(dlevel, 8);
//    	set_exp(dlevel * 40);
    	set_exp(dlevel * 100);
    	set_hp(query_max_hp());
   	set_max_hp(20+(dlevel * (random(10) + 2)));
   	set_hp(query_max_hp());
   	set_max_level(8);
    	set_wielding_limbs( ({ "right hand", "left hand" }) );
    		new("/d/common/obj/lrweapon/shortbow")->move(TO);
    		command("wield bow in right hand and left hand");
    		new("/d/common/obj/armour/chain")->move(TO);
    		command("wearall");
    		new("/d/common/obj/lrweapon/arrows")->move(TO);
    	add_money("electrum",random(5) * dlevel);
    	add_money("silver",random(5) * dlevel);
    	add_money("gold",random(2) * dlevel);
    	add_money("copper",random(10) * dlevel);
    	set_emotes(2,({
		"Orc looks around quickly.\n",
		"Orc scratches himself absentmindedly.\n",
		"Orc eyes you warily.\n",
		"Orc sniffs the air.\n",
		"Orc checks his gear.\n",
		"Orc counts his coins eagerly.\n"
    	}),0);
}
