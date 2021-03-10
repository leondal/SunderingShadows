//NPC priest for newbietown temples - describe & name thanks to HM Schatten's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Migas Arrai");
	set_short("Migas Arrai, Justiciar of Tyr");
	set_id(({"npc cleric","cleric", "migas", "Migas", "justiciar", "Justiciar", "priest"}));
	set_long(
@STYX
%^RESET%^Migas keenly watches over this well-fortified temple with %^CYAN%^crisp blue-green eyes %^RESET%^that are well set within a wrinkled, somewhat aged face.  He appears to be in his late fifties but maintains the look of a mannered gentleman of some stature.  His %^BOLD%^%^BLACK%^jet-black hair %^RESET%^is cut short and neat, as is the mustache that adorns his upper lip.  %^MAGENTA%^Flowing purple satin robes %^RESET%^hang from his broad shoulders over which lays a stylish %^BOLD%^%^BLUE%^cobalt-blue tabard%^RESET%^.  He holds in his %^BOLD%^white leather clad hand %^RESET%^a light body shield displaying an intensely detailed war hammer atop which sits the equally balanced %^YELLOW%^scales of justice%^RESET%^.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(1);
   set_diety("tyr");
   new("/d/magic/symbols/tyr_symbol")->move(TO);
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

