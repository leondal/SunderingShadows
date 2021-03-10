//NPC priest for newbietown temples - describe & name thanks to HM Vivian's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Zelandrina");
	set_short("Zelandrina, High Priestess of Selune");
	set_id(({"npc cleric","cleric", "zelandrina", "Zeladnrina", "priestess"}));
	set_long(
@STYX
%^RESET%^Zelandrina wears a %^BOLD%^%^CYAN%^long, flowing, light blue gown%^RESET%^ that sparkles with a %^BOLD%^silvery sheen%^RESET%^.  The fabric is layered from the drop waist to form a full skirt that just brushes the floor.  The bodice has a princess neckline and is made of an exquisite %^BOLD%^%^BLUE%^dark blue silk%^RESET%^.  Silver piping graces the edges of the gown, accented by delicate embroidery stitched in threads of silver.  A small silver brooch sparkles against the %^BOLD%^%^BLUE%^dark blue silk%^RESET%^.  She wears an ornate silver ring set with a %^BOLD%^brilliant moonstone %^RESET%^ that matches the circlet encrusted with the %^BOLD%^milky white stones %^RESET%^resting on her head.  %^BOLD%^%^BLACK%^Long black hair %^RESET%^reaches her waist and the front is pulled back in an elegant braid, held with a small silver clasp, etched with phases of the moon.  Her %^BOLD%^%^CYAN%^silvery gray eyes %^RESET%^greet all visitors to the %^BOLD%^Moonmaiden's temple %^RESET%^with warmth and openness.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("female");
	set_alignment(4);
   set_diety("selune");
   new("/d/magic/symbols/selune_symbol")->move(TO);
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

