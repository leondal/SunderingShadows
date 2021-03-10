//NPC priest for newbietown temples

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Dantura Shalastar");
	set_short("Dantura Shalastar, Demarch of Mask");
	set_id(({"npc cleric","cleric", "dantura", "Dantura", "priest"}));
	set_long(
@STYX
%^RESET%^Dressed in a %^BOLD%^%^BLACK%^long, flowing dark gray robe %^RESET%^that blends readily into the shadows, Dantura appears rather non-descript at a glance.  However, his dark hair and %^BLUE%^depthless blue eyes %^RESET%^are somewhat of a contrast to his rather pale skin, which is doubtless from spending his life in the shadows.  His %^ORANGE%^dark brown hair and goatee %^RESET%^are well-groomed and he carries himself with an almost unsettling air of confidence.  The cuffs of a fine %^BLUE%^blue silk shirt %^RED%^embroidered with red %^RESET%^peek from under the sleeves of the robe, revealing a taste for finery.  His %^BOLD%^%^BLACK%^muted black leather boots %^RESET%^also have designs of a mask tinged with muted red cut into the leather.  
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(6);
   	set_diety("mask");
	new("/d/magic/symbols/mask_symbol")->move(TO);
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