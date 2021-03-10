//NPC priest for newbietown temples 

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Kalaphelia Mar'Tark");
	set_short("Kalaphelia Mar'Tark, Lorekeeper of Oghma");
	set_id(({"npc cleric","cleric", "kalaphelia", "Kalaphelia", "priestess", "lorekeeper", "Lorekeeper"}));
	set_long("%^MAGENTA%^Kalaphelia is a dusky skinned woman, obviously from the Tsvarian Empire. Her %^BOLD%^%^BLACK%^"
"coal black%^RESET%^%^MAGENTA%^ hair is tucked away behind bound with a %^YELLOW%^golden snood%^RESET%^%^MAGENTA%^. Her "
"slender form is dressed in a pair of full %^BOLD%^%^WHITE%^white pants%^RESET%^%^MAGENTA%^ that have been drawn close "
"against her ankles. A shirt of similar fabric covers her torso, the sleeves very much like the pants. A %^BOLD%^%^BLACK%^"
"black silk%^RESET%^%^MAGENTA%^ vest covers the shirt. A variety of strange runes and symbols cover the vest, each sigil "
"brought to life with the use of %^YELLOW%^gold braid%^RESET%^%^MAGENTA%^. Some of the runes you might recognize, though "
"there are many you have no clue what they might mean. A pair of %^YELLOW%^gold earrings%^RESET%^%^MAGENTA%^ adorn each "
"ear. The earrings are actually miniature musical chimes that chime softly as she moves about. Her dark eyes shine with "
"an intelligent light, of someone you feel knows a great deal of knowledge, and the wisdom of how to use such.");
	set_race("human");
	set_gender("female");
	set_alignment(4);
      set_diety("oghma");
      new("/d/magic/symbols/oghma_symbol")->move(TO);
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

