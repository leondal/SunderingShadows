#include <std.h>
#include "../antioch.h"
inherit INTERACTIVE;

void create()
{
	::create();
        set_nwp("forage",10,500);
	remove_std_db();
	remove_dbs(({"miscvendors"}));
   remove_random_act_dbs(({"miscvendorsrandom"}));
   set_items_allowed("misc");
	set_name("Andrerrard");
	set_short("Andrerrard, rations shop keeper");
	set_id(({"shop keeper","Andrerrard","andrerrard","andy","gstorekeeper"}));
	set_long(
	"Andrerrard looks like a retired woodsman. His black hair is pulled back"+
	" in a pony tail and his green eyes still have a kind sparkle to them."+
	" He's wearing a green tunic with brown leggings and thick black boots."+
	" His pose is easy, and he looks very strong. He has decided to open up"+
	" his own rations shop here in Antioch, providing his services to the"+
	" passing travelers. Although the food is much better up at the inn, the"+
	" food Andrerrard sells will last on the road." 
	);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_alignment(1);
	set_hd(20,5);
	set_max_hp(150+random(20));
	set_overall_ac(-7);
	set_class("mage");
	set_class("fighter");
	set_mlevel("mage",20);
	set_mlevel("fighter",20);
	set_level(20);
	set_stats("intelligence",18);
	set_stats("strength",20);
	set_stats("charisma",8);
	set_stats("constitution",15);
	set_stats("dexterity",10);
	set_stats("wisdom",12);
	set_exp(100);
	set_spells(({
	"hideous laughter",
	"magic missile",
	"acid arrow",
	"chain lightning",
	"phantom guardians",
	"fireball",
	"monster summoning vii",
	"web",
	"meteor swarm",
	"hold person",
	}));
	set_spell_chance(50);
	set_storage_room(ROOMDIR+"ration.c");
	set("aggressive",0);
	add_money("copper",random(100));
	force_me("speech say calmly");
}
