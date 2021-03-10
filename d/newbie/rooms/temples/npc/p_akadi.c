//NPC priest for newbietown temples - describe & name thanks to HM Schatten's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Cormier Gryins");
	set_short("Cormier Gryins, High Priest of Akadi");
	set_id(({"npc cleric","cleric", "cormier", "Cormier", "gryins", "Cormier Gryins", "priest"}));
	set_long(
@STYX
%^RESET%^Adorned in a pair of %^BOLD%^%^BLUE%^light blue pantaloons%^RESET%^, a %^BOLD%^long sleeved, white shirt%^RESET%^, and a %^BOLD%^%^CYAN%^silken gray-blue vest%^RESET%^, Cormier presents a striking figure as he tends the altar of %^BOLD%^Akadi, Queen of the Eternal Winds%^RESET%^.  His sharply defined features and seemingly regal pose are softened by the warm smile and%^BOLD%^%^CYAN%^ sparkling azure eyes %^RESET%^that seem welcoming, yet preoccupied with other thoughts.  His deeply tanned skin born of long exposure to the elements still retains some of the trappings of youth, but the waist length, wavy salt and pepper hair gives away his advanced age.  Rings of sapphire, turquoise and opal adorn his fingers while his left wrist is surrounded by a beautiful beryllonite bracelet with a %^BOLD%^tiny white cloud %^RESET%^in the center of the %^BOLD%^%^BLUE%^dazzling blue stone%^RESET%^.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(8);
   set_diety("akadi");
   new("/d/magic/symbols/akadi_symbol")->move(TO);
   set_overall_ac(6);
   set("aggressive",0);
	set_guild_level("cleric",25);
	set_class("cleric");
	add_search_path("/cmds/priest");
	set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(80);
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

