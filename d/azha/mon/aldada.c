// Lord Agrib al-Dada, Chancellor of Azha
// Thorn@ShadowGate
// 12/19/95
// Azha Keep
// aldada.c

#include <std.h>

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Lord al-Dada");
	set_id(({ "aldada", "chancellor", "lord", "al-dada" }));
	set_short("Lord Agrib al-Dada, Chancellor of Azha");
	set_long(
@TSARVEN
	Lord al-Dada holds the key post of Chancellor of Azha Province.  In
this capacity, he runs the day to day operations of the provincial
bureaucracy. Writing reports and important orders, he takes orders
only from the Governor himself.  If he does his job well, he can one
day look forward to his own governorship, or even a position as an
imperial vizier.
TSARVEN
	);
	set_class("mage");
	level = 1;
	set_level(level);
	set_stats("strength", 10);
	set_stats("constitution", 12);
	set_stats("wisdom", 15);
	set_stats("charisma", 10);
	set_stats("intelligence", 16);
	set_stats("dexterity", 12);
	new("/d/azha/obj/t_key.c")->move(TO);
	new("/d/azha/equip/dada_robe.c")->move(TO);
	force_me("wear robe");
}

	
