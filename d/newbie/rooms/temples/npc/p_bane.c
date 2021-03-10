//NPC priest for newbietown temples 

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Oderan Metheix");
	set_short("Oderan Metheix, Dreadmaster of Bane");
	set_id(({"npc cleric","cleric", "oderan", "Oderan", "priest", "dreadmaster", "Dreadmaster"}));
	set_long(
@CIRCE
%^BOLD%^%^BLACK%^Oderan is a tall male human in the prime of his life. His long %^RESET%^YELLOW%^golden %^RED%^red%^BOLD%^%^BLACK%^ hair is bound behind his head with a strip of black leather. His small dark %^RESET%^%^ORANGE%^coffee%^BOLD%^%^BLACK%^ colored eyes carry a cruel glint, contrasting with his smooth youthful face. His wide thin lips seem to always be ready with a smirk, giving you the feeling of a man who thinks he is better than you. He is dressed in a breastplate of blackened steel. The armor is carved with spurs, hooks and horns and studded with bits of %^GREEN%^bloodstone%^BOLD%^%^BLACK%^ and glass colored %^BOLD%^%^GREEN%^green%^BLACK%^. A silken tunic and a pair of trousers, both black, help to create an intimidating appearance to his muscular form. A %^RED%^blood red%^BLACK%^ cloak hangs behind him. A terrifying spiked gauntlet covers his left hand, on the back of the gauntlet the image of green rays squeezed forth from a black fist can clearly be seen.
CIRCE
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(3);
      set_diety("bane");
      new("/d/magic/symbols/bane_symbol")->move(TO);
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

