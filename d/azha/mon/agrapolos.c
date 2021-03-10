// Janis Agrapolos, Castellan of Azha
// Thorn@ShadowGate
// 12/19/95
// Azha Keep
// agrapolos.c

#include <std.h>

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Agrapolos");
	set_id(({ "agrapolos", "castellan", "janis" }));
	set_short("Janis Agrapolos, Castellan of Azha");
	set_long(
@TSARVEN
	Janis Agrapolos is a man of a pale complexion, like most natives of
Azha province.  He is an elderly man, and his scars tell of a time
when he used to be a warrior instead of a steward. As Castellan of
Azha Keep, he directs the servants and supervises repairs and
maintanence for the fortress.  No one knows these buildings and walls 
better than he.
TSARVEN
	);
	set_body_type("human");
	set_class("fighter");
	level = 3;
	set_level(level);
	set_stats("strength", 13);
	set_stats("constitution", 11);
	set_stats("wisdom", 15);
	set_stats("charisma", 10);
	set_stats("intelligence", 13);
	set_stats("dexterity", 11);
	new("/d/azha/obj/keep_key.c")->move(TO);
	new("/d/azha/equip/agra_staff.c")->move(TO);
	force_me("wield staff in right hand and left hand");
}

	
