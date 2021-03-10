#include <std.h>

inherit MONSTER;

void create(){
	object ob;
	::create();
	
	set_name("Merve");
	set_id(({"merve","Merve"}));
	set("short","Merve, the elven registar");
	set_mob_magic_resistance("average");
	set("long",
@OLI
	Merve is a small man with no distinguishing features except for 
the deep furrows in his brow. He is in charge of registering the elves 
who come and go in the city. 
OLI
	);
	set_race("gnome");
	set_alignment(3);
	set_gender("male");
    set_overall_ac(2);
	set_class("mage");
	set_guild_level("mage",18);
	set_stats("strength",19);
	set_stats("dexterity",25);
	set_body_type("human");
	set_hd(16,1);
	set_hp(120);
	set_max_hp(120);
	set_exp(8000);
    set_max_level(17);
	set_spells(({"fire ball",
				"cone of cold",
				"hideous laughter",
				"web",
				"monster summoning ii"
				"lightning bolt"
				}));
	set_spell_chance(102);
	add_money("gold",random(175));
ob=new("/d/common/obj/rand/mage_robes.c");
		if(random(5)){
			ob->set_property("monsterweapon",1);
		}
	ob->move(TO);
   	command("wear robe");
}

void heart_beat(){

	::heart_beat();
	if(query_attackers() == ({}) && query_hp() != query_max_hp())
		if(query_hp() + 3 <= query_max_hp())
			add_hp(3);
		else
			set_hp(query_max_hp());
	}

void set_paralyzed(int time,string message){ return;}

void reset(){
  object ob;
  ::reset();
  if(!present("scroll")){
    ob = new("/d/magic/scroll");
    ob->set_spell(3);
    ob->move(TO);
  }
}
