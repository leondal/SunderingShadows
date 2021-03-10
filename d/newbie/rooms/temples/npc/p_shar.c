//NPC priest for newbietown temples - describe & name thanks to HM Lliira's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Aemilia Malfour");
	set_short("Aemilia Malfour, Nightcloak of Shar");
	set_id(({"npc cleric","cleric", "aemilia", "Aemilia", "priestess"}));
	set_long(
@STYX
%^ORANGE%^Aemilia Malfour has a look of profound sadness on her gaunt face, perhaps from enduring losses beyond comprehension.  What little light there is in here only allows you a glimpse of this chilling woman, who seems to blend into the darkness.  Her dark, simple clerical attire over a frail frame makes her seem almost more a shadow than human.  Her mahogany skin is marked by a few wrinkles here and there while %^RESET%^long dull silver hair %^ORANGE%^hangs limply about her shoulders.  Small %^MAGENTA%^streaks of violet %^ORANGE%^are woven into her hair, providing what little break of color there is.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("female");
	set_alignment(6);
   set_diety("shar");
   new("/d/magic/symbols/shar_symbol")->move(TO);
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

