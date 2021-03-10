#include <std.h>
#include "../antioch.h"
inherit MONSTER;

void create()
{
	::create();
	set_name("bank guard");
	set_short("A bank guard");
	set_id(({"guard","bank guard"}));
	set_long(
	"This bank guard looks rather bored with his job. Most of the time he's sitting"+
	" on his stool and seems to be staring at nothing in particular. Sometimes you"+
	" even think he might be catching a little nap. He does eye everyone that walks"+
	" in here with a careful eye, however, so maybe his appearant laziness is decieving."
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
	"The bank guard begins to snore a little.",
	"The bank guard leans back on his stool.",
	"The bank guard yawns as he looks around.",
	"The bank guard eyes you carefully.",
	"The bank guard walks back and forth across the room.",
	"The bank guard leans against the wall and sighs.",
	"The bank guard checks the time again.",
	}),0);
	set_exp(100);
	set_property("swarm",1);
	set_property("full attacks",1);
	set("aggressive",0);
   new("/d/common/obj/weapon/longsword")->move(TO);
	force_me("wield sword");
}
