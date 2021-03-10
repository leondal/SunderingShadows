#include <std.h>
#include "../../../newbie.h"

inherit NPC;

void create() {
	::create();
	set_name("Cleric");
	set_short("Temp priest");
	set_id(({"npc cleric","cleric"}));
	set_long(
@STYX
A temp NPC priest for the temples.
STYX
	);
	set_race("human");
	set_gender("male");
	set_alignment(2);
	set_guild_level("cleric",25);
	set_class("cleric");
	add_search_path("/cmds/priest");
	set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(50);
	set_hd(30,5);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	remove_std_db();
}
