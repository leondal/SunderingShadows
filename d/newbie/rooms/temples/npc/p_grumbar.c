#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Durean Thurmgard");
	set_short("Durean Thurmgard, Chosen of the Earthlord");
	set_id(({"npc cleric","cleric", "durean", "Durean", "priestess"}));
	set_long("Durean seems large for a dwarf at first glance, her height boosted by the thick soles on her sturdy "
"leather boots.  Her stocky dwarven frame seems even sturdier from the heavy shoulder pads and draping folds of the "
"%^ORANGE%^heavy earth-tone robe %^CYAN%^she wears over her armor, belted with a wide black belt at the waist.  A large "
"sardonyx pendant carved with the Earthlord's symbol hangs from a heavy silver chain worn around her neck.  She has long"
", sandy brown hair, a neatly braided beard, and intense dark brown eyes.  All in all, she looks nearly as unshakable as "
"the sturdy stone walls of the temple.");
	set_race("dwarf");
	set_body_type("human");
	set_gender("female");
	set_alignment(2);
   set_diety("grumbar");
   new("/d/magic/symbols/grumbar_symbol")->move(TO);
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

