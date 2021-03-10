#include <std.h>
#include <daemons.h>
inherit MONSTER;

int dlevel;

create() {
    ::create();
	set_name("mage");
	set_id( ({ "orc", "orc mage","mage" }) );
	set_race("orc");
	set_gender("male");
	set_short("An orc mage");
	set_long(
@KAI
This is the heart of all the orc evil in this place.  An orc mage towering
over you, his hair wild and eyes furious.  His vicious snarling of
various ancient spells sends shivers down your spine.
KAI
);
	dlevel = random(3) + 10;
	set_level(dlevel);
	set_body_type("human");
  	set("aggressive",5);
  	set_alignment(9);
  	set_size(2);
   	set_stats("intelligence",18);
   	set_stats("wisdom",18);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",16);
   	set_stats("constitution",13);
	set_class("mage");
	set_mlevel("mage",dlevel);
	set_guild_level("mage",dlevel);
   	set_spells(({
   		"magic missile",
   		"scorcher",
   		"sleep",
   		"chill touch",
   		"lightning bolt",
   		"color spray"
   	}));
   	set_spell_chance(90);
	set_hd(dlevel, 6);
//   	set_exp(dlevel * 50);
   	set_exp(dlevel * 100);
   	set_max_hp(20+(dlevel * (random(10) + 1)));
    	set_hp(query_max_hp());
  		new("/d/common/obj/armour/robe")->move(TO);
  		command("wear robe");
	add_money("silver",random(5) * dlevel);
	add_money("gold",random(25) * dlevel);
}
