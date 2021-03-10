//NPC priest for newbietown temples - describe & name thanks to HM Schatten's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Cerisse Venniter");
	set_short("Cerisse Venniter, Grand Oracle of Istishia");
	set_id(({"npc cleric","cleric", "cerisse", "Cerisse", "oracle" }));
	set_long(
@STYX
%^RESET%^Cerisse wears a flowing gown made of pebbly georgette, tiered in rippling waves of alternating coral and mother of pearl skirts.  A matching bodice stitched with %^BOLD%^%^BLUE%^blue %^RESET%^and %^BOLD%^silver %^RESET%^embroidery is cinched tight against her svelte frame.  Tapering sleeves, laced with %^BOLD%^%^CYAN%^azure silk ribbons%^RESET%^, drape down toward the ground in billowing rolls of the silky fabric.  A %^BOLD%^%^GREEN%^jade ring %^RESET%^that seems to swirl like the water of the seas adorns her left hand and is matched by a sparkling %^BOLD%^%^GREEN%^jade pendant %^RESET%^suspended on a silver chain.  Her eyes and shoulder length hair are a creamy chestnut against honey kissed alabaster skin.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("female");
	set_alignment(8);
	set_diety("istishia");
	new("/d/magic/symbols/istishia_symbol")->move(TO);
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