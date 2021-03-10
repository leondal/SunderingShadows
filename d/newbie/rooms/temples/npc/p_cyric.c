//NPC priest for newbietown temples - describe & name thanks to HM Schatten's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Saul");
	set_short("Saul Halsanap, Dark Hand of Cyric the Mad");
	set_id(({"npc cleric","cleric", "saul", "Saul", "priest"}));
	set_long(
   " %^RESET%^The hood of a %^MAGENTA%^royal purple, chintz robe %^RESET%^lays thrown back to reveal the stark white blaze of hair crowning the ebony skinned High Priest of Cyric."+
   " Glittering %^BOLD%^%^BLACK%^black eyes %^RESET%^are narrowed and hawk-like as they glare disdainfully at you above a sharply pointed nose.  A maniacal grin slowly creeps across his"+
   " face as he idly fingers the tight fitting silver bracelets around his wrists.  The symbol of Cyric, a white skull set atop a black sun, can be seen glinting"+
   " from the bracelets.  He stands well over seven feet tall and even the voluminous, shimmery fabric of the robe's folds do not hide his"+
   " muscular frame.  A hammer, made from a blackened metal and adorned with the holy symbol of Cyric hangs casually from his"+
   " %^BOLD%^%^BLACK%^black leather belt%^RESET%^, while %^BOLD%^%^RED%^tiny flecks of red%^RESET%^ can be seen upon the leather wrapped grip.");
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(9);
   set_diety("cyric");
   new("/d/magic/symbols/cyric_symbol")->move(TO);
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

