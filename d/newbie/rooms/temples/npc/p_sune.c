//NPC priest for newbietown temples
#include <std.h>

inherit NPC;

void create() {
        ::create();
        set_name("Alexander Kilix");
        set_short("Alexander Kilix, Silkwhisper of Sune");
        set_id(({"npc cleric","cleric", "Alexander", "alexander", "priest"}));
        set_long("%^BOLD%^%^WHITE%^Alexander Kilix is a tall male"+
		" human with a muscular physique.  His short %^BOLD%^"+
		"%^RED%^scarlet red%^BOLD%^%^WHITE%^ hair has a carefully"+
		" windblown look to it.  The even %^RESET%^%^ORANGE%^bronze"+
		"%^BOLD%^%^WHITE%^ complexion of his skin brings out his "+
		"%^BOLD%^%^GREEN%^emerald green%^BOLD%^%^WHITE%^ eyes.  A "+
		"light dusting of %^RESET%^%^ORANGE%^freckles%^BOLD%^%^WHITE%^"+
		" across his face gives him a youthful appearance.  A manicured"+
		" and well groomed %^BOLD%^%^RED%^goatee%^BOLD%^%^WHITE%^ covers"+
		" his chin.  Dressed in a loose, billowing white silk shirt and a"+
		" %^RESET%^%^RED%^deep crimson%^BOLD%^%^WHITE%^ kilt, his appearance"+
		" is immaculate, and cut to show off his best attributes.  A long"+
		" %^RESET%^%^RED%^dark crimson%^BOLD%^%^WHITE%^ velvet cloak is "+
		"casually tossed over his left shoulder.  An air of confidence and"+
		" kindness radiates outwards from this handsome man.");
      set_race("human");
      set_body_type("human");
      set_gender("male");
     	set_alignment(8);
   	set_diety("sune");
   	new("/d/magic/symbols/sune_symbol")->move(TO);
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
      set_stats("strength", 15);
   	set_stats("dexterity", 17);
   	set_stats("constitution", 16);
   	set_stats("intelligence", 11);
   	set_stats("charisma", 17);
   	set_stats("wisdom", 18);
      set_db("temple_cleric");
      remove_std_db();
}
