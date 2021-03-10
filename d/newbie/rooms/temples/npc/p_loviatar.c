//NPC priest for newbietown temples - describe & name thanks to avatar Malar

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Mantical Elenquay");
	set_short("Mantical Elenquay, Loviatar's Inquisitor");
	set_id(({"npc cleric","cleric", "mantical", "Mantical", "priest"}));
	set_long(
@STYX
%^RESET%^Mantical is dressed in %^BLUE%^dark blue pants%^RESET%^, and a %^MAGENTA%^dark purple shirt%^RESET%^.  As you look him up and down, you notice that his hands are burned and his finger nails seem to have been removed recently.  Even with this, you can see grim determination and enlightenment on his face from enduring the pain.  In one of his hands, a small cat-o-nine rests easily, seemingly well accustomed to its place in his hands.  One of his %^GREEN%^dark green eyes %^RESET%^seems to be a bit lazy, perhaps related to the scar you see alongside it, while the other one focuses steadily on you.  His lips are very pale and thin.  The rest of his face is scarred lightly and his skin tight against his skull.  Light brown hair covers his head.  It seems to stick out, wildly and randomly, as though not much attention is paid to it.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(6);
   set_diety("loviatar");
   new("/d/magic/symbols/loviatar_symbol")->move(TO);
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

