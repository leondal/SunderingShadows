#include <std.h>
#include "../antioch.h"
inherit TOWNSMAN;

void create()
{
	::create();
	set_name("Mudric");
	set_short("Baron Mudric, royal advisor");
	set_id(({"mudric","Mudric","advisor","third advisor","baron mudric","baron","royal advisor"}));
	set_long(
	"Baron Mudric is one of the king's advisors, he represents the citizens"+
	" of the town. He looks to be in his mid-forties, and quite content with"+
	" life. His blonde beard and hair are kept carefully trimmed. He is"+
	" dressed in a fine blue silk shirt, black trousers, and a pair of black"+
	" leather boots. He is barely over five feet in height and is rather"+
	" stocky. He wears the symbol of Jarmila around his neck and is a very"+
	" devoted cleric. He helps to keep the town's religious spirits high,"+
	" and occasionally will divine for the king on troubling matters."
	);
	set_gender("male");
	set_race("human");
	set_hd(30,6);
	set_alignment(1);
	set_overall_ac(-10);
	set_max_hp(360);
	set_hp(query_max_hp());
	set_class("cleric");
	set_mlevel("cleric",30);
//	set_diety("helm");
//	new("/d/magic/symbols/helm_symbol.c")->move(TO);
	set_level(30);
	set_stats("wisdom",20);
	set_stats("constitution",16);
	set_stats("strength",12);
	set_stats("charisma",17);
	set_stats("dexterity",10);
	set_stats("intelligence",17);
	set_spells(({
	"flame strike",
	"mystic bolt",
	"hold person",
	"limb attack",
	}));
	set_spell_chance(100);
	set_exp(100);
	set("aggressive",0);
	set_property("swarm",1);
}
