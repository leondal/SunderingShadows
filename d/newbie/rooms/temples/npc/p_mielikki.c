//NPC priest for newbietown temples - describe & name thanks to HM Kaarell's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Aeralia Greenstar");
	set_short("Aeralia Greenstar, Mielikki's Forest Walker");
	set_id(({"npc cleric","cleric", "aeralia", "Aeralia", "priestess", "walker"}));
	set_long(
@STYX
%^RESET%^Aeralia's long %^BOLD%^%^WHITE%^silver tresses%^RESET%^ are bound up into a loose bun clipped by a %^BOLD%^%^WHITE%^silver clasp%^RESET%^ in the shape of a unicorn. Her crystal clear %^ORANGE%^amber eyes%^RESET%^ are framed by high elven cheek bones and long pointed ears. %^GREEN%^Studded leather armor%^RESET%^ rests comfortably on her slight elven frame, under which she wears a long sleeved %^GREEN%^green tunic%^RESET%^ that is tucked into a set of %^BOLD%^%^BLACK%^dark brown breeches%^RESET%^.  A wooden medalion hangs about her neck on a silk cord and a small unicorn head carved out of %^BOLD%^%^WHITE%^white ivory%^RESET%^ is pinned over her heart.  She holds a long wooden staff capped on both ends with metal bracing.
STYX
	);
	set_race("elf");
	set_body_type("human");
	set_gender("female");
	set_alignment(7);
   set_diety("mielikki");
   new("/d/magic/symbols/mielikki_symbol")->move(TO);
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

