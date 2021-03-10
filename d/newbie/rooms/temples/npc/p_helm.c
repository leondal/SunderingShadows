//NPC priest for newbietown temples - describe & name thanks to HM Lliira's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Nathaniel Desthar");
	set_short("Nathaniel Desthar, Guardian of Helm");
	set_id(({"npc cleric","cleric", "nathaniel", "Nathaniel", "priest"}));
	set_long(
@STYX
%^RESET%^Nathaniel appears to be young for the responsibilities he shoulders.   His curly strawberry blond hair hangs loose and in his eyes, but his smile is warm and his %^GREEN%^hazel eyes %^RESET%^seem quite alert.  His tall frame is encased in a breastplate of mail that has been stained %^BOLD%^%^CYAN%^sky blue%^RESET%^, worn over a %^BOLD%^white tunic %^RESET%^and breeches made of a fine cotton.  Intricately engraved gauntlets protect his hands.  This young man clearly brings a youthful vigor to his mission to make most feel welcome and safe under Helm's watchful eye.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(2);
   set_diety("helm");
   new("/d/magic/symbols/helm_symbol")->move(TO);
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

