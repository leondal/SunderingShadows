//NPC priest for newbietown temples 

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Adiekze Ketsanzal");
	set_short("Adiekze Ketsanzal, Xvimlar High Priestess");
	set_id(({"npc cleric","cleric", "Adiekze", "adiekze", "priestess"}));
	set_long(
@STYX
%^BOLD%^%^BLACK%^Adiekze's ebony skin with otherwise elven features leaves no doubt this priestess is drow.  She is wearing black leather armor under a robe woven of black silk edged in%^RESET%^%^GREEN%^ dark green%^BOLD%^%^BLACK%^.  Dark, piercing eyes peer from under the hood of the robe and %^RESET%^dull white hair %^BOLD%^%^BLACK%^falls loosely along her lean but muscular shoulders.  Everything in her demeanor reminds you that drow are ruthless killers and she seems well suited to carrying out Xvim's merciless work.
STYX
	);
	set_race("drow");
	set_body_type("human");
	set_gender("female");
	set_alignment(6);
   set_diety("xvim");
   new("/d/magic/symbols/xvim_symbol")->move(TO);
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

