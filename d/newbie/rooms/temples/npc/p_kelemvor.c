#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Jarrold Brummand");
	set_short("Jarrold Brummand, Doomguide of Kelemvor");
	set_id(({"npc cleric","cleric", "priest", "jarrold", "Jarrold"}));
	set_long(
@STYX
%^RESET%^Jarrold appears to be about six foot tall and has a rather gaunt build.  He has deep-set, %^BLUE%^dark blue eyes %^RESET%^and dark brown hair graying around the temples.  His neatly trimmed beard also has streaks of gray, which adds to his grandfatherly appearance.  A simply cut, %^BOLD%^%^BLACK%^smoky gray cowled cloak %^RESET%^blends with the rest of his subdued clothing and seems to suit his somber demeanor well.  The only adornment on his vestments is the embroidered symbol of Kelemvor, a skeletal arm holding the %^YELLOW%^golden scales of justice%^RESET%^.  
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(2);
   set_diety("kelemvor");
   new("/d/magic/symbols/kelemvor_symbol")->move(TO);
	set_guild_level("cleric",25);
	set_class("cleric");
	add_search_path("/cmds/priest");
	set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(50);
	set_hd(30,5);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_db("temple_cleric");
	remove_std_db();
}

