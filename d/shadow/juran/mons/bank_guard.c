#include <std.h>
#include "../juran.h"
inherit MONSTER;

void create(){
	::create();
	set_name("bank guard");
	set_short("A bank guard");
	set_id(({"monster","guard","bank guard"}));
	set_long(
		"This ogre bank guard looks rather bored with his job. Most of the time "+
		"he's sitting on his stool and seems to be staring at nothing in "+
		"particular. Sometimes you even think he might be catching a "+
		"little nap. He does eye everyone that walks in here with a careful "+
   "eye, however, so maybe his appearant laziness is deceiving."
	);
	set_gender("male");
	set_race("ogre");
	set_body_type("humanoid");
  	set_size(3);
	set_hd(20,8);
	set_max_hp(175+random(50));
	set_hp(query_max_hp());
	set_alignment(9);
	set_overall_ac(-10);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(20);
	set_stats("strength",20);
	set_stats("constitution",20);
	set_stats("dexterity",10);
	set_stats("charisma",5);
	set_stats("wisdom",6);
	set_stats("intelligence",8);
  	set_size(3);
	set_emotes(0,({
		"The bank guard begins to snore like a howling wind.",
		"The bank guard leans back on his huge stool.",
		"The bank guard yawns as he looks around.",
		"The bank guard eyes you carefully.",
		"The bank guard lumbers back and forth across the room.",
		"The bank guard slaps his huge club against his hand casually.",
	}),0);
	set_exp(1000);
	set_property("swarm",1);
	set_property("full attacks",1);
	set("aggressive",0);
   	new("/d/common/obj/weapon/club_lg")->move(TO);
	force_me("wield club");
}
