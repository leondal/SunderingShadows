//NPC priest for newbietown temples 

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Rumpus Flipnhop");
	set_short("Rumpus Flipnhop, Luckbringer of Tymora");
	set_id(({"npc cleric","cleric", "rumpus", "Rumpus", "priest", "luckbringer", "Luckbringer"}));
	set_long(
@CIRCE
%^ORANGE%^Rumpus is a small pudgy halfling with reddish brown hair that has a chaotic kink to it. His deep blue eyes sparkle with warmth and mirth. His plump cheeks feature deep wrinkles from his jovial appearance and the wide smile he always carries. He is dressed in a small %^BOLD%^%^BLUE%^blue robe%^RESET%^ORANGE%^ with a %^BOLD%^%^WHITE%^silver trim%^RESET%^%^ORANGE%^ around the cuffs and hem. The robe is stretched taunt across his plumpy tummy, looking as if the buttons might pop at any time. Perhaps its by sheer luck that he can even fit into such a garment still. A %^BOLD%^%^WHITE%^silver coin%^RESET%^%^ORANGE%^ with a winking womans face engraved into the metal hangs about his neck on a chain. A small grey rabbit occasionally peaks it head from a pocket in his robe.
CIRCE
	);
	set_race("halfling");
	set_gender("male");
	set_alignment(4);
      set_diety("tymora");
      new("/d/magic/symbols/tymora_symbol")->move(TO);
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

