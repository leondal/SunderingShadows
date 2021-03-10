//NPC priest for newbietown temples - describe & name thanks to HM Vivian's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Seth Calinbar");
	set_short("Seth Calinbar, Exalted of Eldath");
	set_id(({"npc cleric","cleric", "seth", "Seth", "Calinbar", "priest"}));
	set_long(
@STYX
The %^ORANGE%^deep brown %^CYAN%^of the high priest's fitted breeches blends with the surrounding %^ORANGE%^tree trunks%^CYAN%^.  The pants seem to be made of a coarse burlap softened by hours wading in the rushing water of the stream as Seth tends the grove of the Goddess of Singing Waters.  The high priest moves gracefully, each gesture echoing the quiet movement of water symbolic of his goddess's message of peace.  A %^GREEN%^green linen shirt %^CYAN%^is worn loosely tied at the neck with voluminous sleeves billowing over his arms before being gathered and tied at the wrists.  A deeper green leather cord binds the older man's %^RESET%^silvery hair %^CYAN%^at the base of his neck while allowing wispy tendrils to frame his face.  A kind, quiet smile is ever-present on this stoic man's face, hinting at the deeper peace brought by worship of the Green Goddess.  He carries a small flute carved of wood that has been worn smooth by ages of playing the music of the grove.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(4);
   set_diety("eldath");
   new("/d/magic/symbols/eldath_symbol")->move(TO);
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

