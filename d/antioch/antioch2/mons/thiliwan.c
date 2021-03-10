#include <std.h>
#include "../antioch.h"
inherit TOWNSMAN;

void create()
{
	::create();
	set_name("Thiliwan");
	set_short("Thiliwan, cook of the White Dragon Inn");
	set_id(({"Thiliwan","thiliwan","cook"}));
	set_long(
	"Thiliwan is the renowned cook of the White Dragon Inn. He spends almost"+
	" all his time in the kitchen, occassionaly leaving to collect some"+
	" fresh herbs from his garden. He's wearing a pair of tan trousers and"+
	" a white shirt, an apron covers most of his clothes in the front. He"+
	" is getting older in age, probably in his mid fifties, and is a little"+
	" on the plump side, probably from tasting all of his own delicious foods."+
	" His frame is still set with muscles, it is said he used to be a fighter,"+
	" though he always cooked for the rest of the troops. His brown hair is"+
	" streaked with gray and his brown eyes still hold a warm twinkle. He"+
	" seems like a very kind man."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(30,15);
	set_alignment(1);
	set_max_hp(300+random(50));
	set_hp(query_max_hp());
	set_level(30);
	set_overall_ac(-15);
	set_class("fighter");
	set_mlevel("fighter",30);
	set_stats("strength",25);
	set_stats("consitution",20);
	set_stats("dexterity",12);
	set_stats("charisma",13);
	set_stats("wisdom",16);
	set_stats("intelligence",9);
	set_exp(100);
	set("aggressive",0);
	add_money("silver",random(50));
}

//chat, call guards
