// trainer in studying to load in Antioch.  Circe 5/23/04
#include <std.h>

inherit NPC;

void create()
{
	::create();
	set_nwp("studying", 12);
	set_name("Oswin");
	set_id(({ "oswin", "Oswin", "trainer" }));
	set_short("Oswin, a young entertainer");
	set_long("%^RESET%^%^CYAN%^Oswin is a young man, just out of " +
		 "his teens.  He is dressed in a simple %^BOLD%^%^BLUE%^" +
		 "blue linen tunic %^RESET%^%^CYAN%^atop %^ORANGE%^brown " +
		 "leather breeches%^CYAN%^.  His unruly hair is a pleasant " +
		 "%^WHITE%^wheat shade %^CYAN%^and falls in waves all " +
		 "about his face.  Across the bridge of his nose is a " +
		 "smattering of %^ORANGE%^fre%^RED%^c%^ORANGE%^kles %^CYAN%^" +
		 "that makes him seem even younger than he is.  Despite " +
		 "his youthful appearance, his %^BOLD%^%^GREEN%^green " +
		 "eyes %^RESET%^%^CYAN%^are filled with a deep " +
		 "intelligence.  He is never without at least one " +
		 "%^ORANGE%^book %^CYAN%^or %^WHITE%^scroll%^CYAN%^, " +
		 "and he spends most of his time working hard in his " +
		 "apprenticeship under the town's minstrel.");
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(20, 15);
	set_max_level(20);
	set_size(2);
	set_alignment(5);
	set_overall_ac(0);
	set_max_hp(random(50) + 160);
	set_hp(query_max_hp());
	set_exp(100);
	set_level(20);
	set_class("bard");
	set_mlevel("bard", 20);
	set_guild_level("bard", 20);
	set_stats("intelligence", 18);
	set_stats("wisdom", 15);
	set_stats("strength", 18);
	set_stats("charisma", 18);
	set_stats("dexterity", 16);
	set_stats("constitution", 15);
	set_mob_magic_resistance("very low");
	set_property("full attacks", 1);
//   set_property("alignment adjustment",-5);
	add_money("electrum", random(100));
	set_moving(1);
	set_speed(10);
	set_nogo(({ "/d/antioch/antioch2/rooms/trail6" }));
	set_spell_chance(90);
	set_spells(({ "hold person", "powerword stun", "hold person", "lightning bolt", "magic missile", "meteor swarm" }));
	"daemon/place_d"->place_in("/d/antioch/antioch2/rooms/", TO);
}
