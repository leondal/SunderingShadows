//NPC priest for newbietown temples
#include <std.h>

inherit NPC;

void create() {
        ::create();
        set_name("Lorenzo Esperair");
        set_short("Lorenzo Esperair, Guide of the Hidden Ways");
        set_id(({"npc cleric","cleric", "lorenzo", "Lorenzo", "priest"}));
        set_long("%^ORANGE%^Lorenzo Esperair is shorter and stockier"+
		" than an average male of his race.  His %^BOLD%^%^RED%^"+
		"russet %^RESET%^%^ORANGE%^brown hair is kept long and "+
		"bound in the back with a leather cord.  His tan face is"+
		" covered with a light dusting of whiskers, as if it's been"+
		" a few days since he's had a shave.  A seasoned but kind "+
		"light shines in his light brown eyes.  A long %^BOLD%^"+
		"%^BLACK%^dark %^RESET%^%^ORANGE%^swirling cloak covers "+
		"his shoulders, flowing all the way down to the floor.  "+
		"Dressed in a simple %^CYAN%^cotton%^ORANGE%^ tunic and a"+
		" pair of %^CYAN%^suede%^ORANGE%^ leggings, his garments "+
		"have a rough and well worn look to them.  A suit of leather"+
		" armor conceals most of his clothing, the leather mirroring "+
		"the condition of his clothing.  A pair of %^BOLD%^%^BLACK%^"+
		"deep black%^RESET%^%^ORANGE%^ leather gauntlets cover his "+
		"hands.  On the back of each gauntlet a %^BOLD%^%^WHITE%^silver"+
		"%^RESET%^%^ORANGE%^ upright left hand surrounded by rippling "+
		"lines in %^CYAN%^blue-gray%^RESET%^%^ORANGE%^ and %^MAGENTA%^deep"+
		" violet%^RESET%^%^ORANGE%^ has been stitched.");
      set_race("human");
      set_body_type("human");
      set_gender("male");
     	set_alignment(8);
   	set_diety("shaundakul");
   	new("/d/magic/symbols/shaundakul_symbol")->move(TO);
     	set_guild_level("cleric",25);
      set_class("cleric");
      add_search_path("/cmds/priest");
      set_spells( ({ "limb attack", "hold person", "cause critical wounds",
"hold person" }) );
   	set_spell_chance(50);
      set_hd(30,5);
      set_max_hp(200);
      set_hp(200);
      set_exp(10);
      set_stats("strength", 17);
   	set_stats("dexterity", 17);
   	set_stats("constitution", 15);
   	set_stats("intelligence", 13);
   	set_stats("charisma", 13);
   	set_stats("wisdom", 18);
      set_db("temple_cleric");
      remove_std_db();
}
