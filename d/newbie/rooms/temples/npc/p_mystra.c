//NPC priest for newbietown temples - describe & name thanks to HM Lliira's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Lucius Del'Frey");
	set_short("Lucius Del'Frey, Mystra's Weavekeeper");
	set_id(({"npc cleric","cleric", "lucius", "Lucius", "priest"}));
	set_long(
@STYX
Lucius has %^ORANGE%^light brown hair %^CYAN%^that is a bit dishelved but adds a nice warm touch to his appearance.  His %^RESET%^soft gray eyes %^CYAN%^are somewhat hidden behind a pair of %^BOLD%^%^WHITE%^silver glasses.  %^RESET%^%^CYAN%^He seems reserved, or perhaps just preoccupied with his studies.  A simple velvet robe of %^BLUE%^midnight blue %^CYAN%^adds to his studious appearance.  Leather boots of a similar hue of blue protect his feet.  His robe is held in place with a belt made of silver and emblazed with seven stars.   From a thick chain around his neck hangs the talisman of the Mother of All Magic.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(4);
   set_diety("mystra");
   new("/d/magic/symbols/mystra_symbol")->move(TO);
	set_guild_level("cleric",25);
	set_class("cleric");
	add_search_path("/cmds/priest");
	set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(50);
	set_hd(30,5);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_stats("strength", 14);
   set_stats("dexterity", 17);
   set_stats("constitution", 15);
   set_stats("intelligence", 14);
   set_stats("charisma", 15);
   set_stats("wisdom", 18);
	set_db("temple_cleric");
	remove_std_db();
}

