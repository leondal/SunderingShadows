#include <std.h>
#include "../antioch.h"
inherit MONSTER;

void create()
{
	::create();
	set_name("archer");
	set_short("Antioch Archer");
	set_id(({"archer","antioch archer","Antioch archer","Antioch Archer"}));
	set_long(
	"This man is obviously one of the archers that patrols Antioch. He has a quiver"+
	" of bolts on his back and a nasty looking crossbow slung across his shoulder."+
	" There's a scabbard with a sword in it buckled around his waist in case the"+
	" fighting gets too close. He seems to be constantly on guard for any danger."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(20,8);
	set_max_hp(175+random(50));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(-10);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(20);
	set_stats("strength",19);
	set_stats("constitution",17);
	set_stats("dexterity",16);
	set_stats("charisma",12);
	set_stats("wisdom",15);
	set_stats("intelligence",14);
	set_emotes(3,({
	"The archer peers into the distance, looking for any signs of trouble.",
	"The archer checks his crossbow.",
	"The archer adjusts his scabbard.",
	"The archer paces back and forth.",
	}),0);
	set_exp(100);
	set_property("swarm",1);
	set_property("full attacks",1);
	set("aggressive",0);
   new("/d/common/obj/lrweapon/hcrossbow")->move(TO);
	present("crossbow",TO)->set_property("monsterweapon",1);
   new("/d/common/obj/lrweapon/hquarrels")->move(TO);
	present("quarrels",TO)->set_property("monsterweapon",1);
   new("/d/common/obj/weapon/longsword")->move(TO);
	force_me("wield sword");
}
