//NPC priest for newbietown temples - describe & name thanks to HM Lliira's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Curan Laxunthy");
	set_short("Curan Laxunthy, Stormrider of Talos");
	set_id(({"npc cleric","cleric", "curan", "Curan", "priest"}));
	set_long(
@STYX
Curan is a man of immense size, not only in height but quite round as well.   His wild %^RESET%^salt and %^BOLD%^%^BLACK%^pepper h%^RESET%^a%^BOLD%^%^BLACK%^i%^RESET%^r %^CYAN%^nearly stands on end, as if he has been struck by lighting once too often.  A thick, greasy moustache covers his upper lip and over his right eye is a %^BOLD%^%^BLACK%^black eyepatch %^RESET%^trimmed in silver%^CYAN%^.  Perhaps it is just ornamental, since most priests of the Lord of Storms dress like their master.  A %^BOLD%^%^BLACK%^quite large robe made of black silk %^RESET%^%^CYAN%^wraps his huge frame.  The robe has been %^RESET%^edged in silver material %^CYAN%^and cut to give the appearance of lighting bolts.  About one of his thick fingers is a ring made of electrum, bearing the symbol of Talos.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(9);
   set_diety("talos");
   new("/d/magic/symbols/talos_symbol")->move(TO);
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

