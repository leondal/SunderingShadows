#include <std.h>
inherit MONSTER;

void init(){
	::init();
	add_action("stab_func", "stab");
	add_action("ride_func", "ride");
}
void create(){
	int resist;
	::create();

set_name("dragon horse");
set_id(({"dragon", "dragon horse", "horse", "ki-rin"}));
set_race("ki-rin");
set_gender("male");
set_short("dragon horse");
set_long("%^BOLD%^CYAN%^The skydwelling horse appears to be a ki-rin without any horn.  It's coat is a silvery blue, with flowing mane and tail of silver.  It's hooves are indigo blue and could cause serious damage.  This mount can only be ridden by those pure of heart, mind and soul.");
	set_level(24);
	set_body_type("quaduped");
	set_class("fighter");
	set("aggressive", 1);
	set_alignment(4);
	set_size(3);
	set_overall_ac(0);
set_stats("intelligence", 15);
set_stats("wisdom", 15);
set_stats("strength", 20);
set_stats("charisma", 20);
set_stats("dexterity", 20);
set_stats("consititution", 25);
	set_hd(24,1);
	set_hp(110);
	set_max_hp(query_hp());
resist = 25 + random(25) + random(25);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(50);
set_spells(({"cone of cold"}));
set_property("swarm", 1);
set_exp(2500);
add_money("gold", (100));
add_money("electrum", (10));
}
int stab_func(string str){
	write("%^BOLD%^CYAN%^Deep hooves reach out to kill you, a silver mane flies by and a scream of madness witnesses your foolish action!");
	return 1;
}
int ride_func(string str){
	write("%^BOLD%^CYAN%^I said you had to be pure of heart, soul and mind, and who do YOU think you are kidding");
	return 1;
}
