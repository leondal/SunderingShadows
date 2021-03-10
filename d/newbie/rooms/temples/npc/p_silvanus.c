//NPC priest for newbietown temples - describe & name thanks to HM Schatten's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Allesen Serniah");
	set_short("Allesen Serniah, Grand Caretaker of Nature's Balance");
	set_id(({"npc cleric","cleric", "allesen", "Allesen", "priestess", "caretaker"}));
	set_long(
@STYX
%^RESET%^Allesen is a young woman, perhaps in her late 20's, whose %^BOLD%^%^CYAN%^soft silver-gray eyes %^RESET%^flicker with willful determination. Her %^YELLOW%^braided sunshine blonde hair %^RESET%^has been piled atop her head and pinned with a %^GREEN%^green leather tie%^RESET%^, while a %^ORANGE%^brown leather cloak%^RESET%^, suspended by silver clasps on her shoulders, flutters in the wind. She appears well protected, yet still free to move, in the beautiful %^GREEN%^forest-green studded leather %^RESET%^she wears. The individual metal studs have been shaped into detailed silver oak leaves that sparkle in the tree filtered light of the grove.  A life-like oak leaf copper pin is attached above her right breast, and seems to move as though blown on a faint unfelt wind.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("female");
	set_alignment(5);
   set_diety("silvanus");
   new("/d/magic/symbols/silvanus_symbol")->move(TO);
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

