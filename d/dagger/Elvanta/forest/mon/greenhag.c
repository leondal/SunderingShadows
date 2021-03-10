#include <std.h>

inherit MONSTER;

void init() {
	::init();
add_action("throw_func", "throw");
add_action("cast_func", "cast");
add_action("stab_func", "stab");
}
reset() {
::reset();
}

void create() {
	int resist;
	::create();

set_author("Svaha");
set_name("greenhag");
set_id( ({"greenhag", "green hag", "hag"}) );
set("race", "annis");
set_gender("female");
set_short("A Greenhag");
set_long("%^GREEN%^A typical greenhag is an old withered hag with green skin.  Her hair colour is olive green, and her eye colour amber.  Her clothes rest tattered and torn upon a body that looks to have been dead for years.%^RESET%^");
set_level(25);
set_body_type("human");
set_class("thief");
set("aggressive", 30);
set_property("swarm", 1);
set_size(2);
set_property("no bump", 1);
set_property("no paralyze", 1);
set_stats("strength", 18);
set_stats("intelligence", 25);
set_stats("wisdom", 20);
set_stats("dexterity", 25);
set_stats("constitution", 20);
set_stats("charisma", 20);
set_overall_ac(-2);
set_alignment(9);
set_hd(27,8);
set_exp(10000);
set_wielding_limbs(({"right hand", "left hand", "torso"}));
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
command("wield claw in right hand");
command("wield claw 2 in left hand");
set("aggressive", "do_stuff");
set_thief_skill("move silently", 70);
set_thief_skill("hide in shadows", 70);
add_search_path("cmds/thief");
set_invis();
set_emotes(4, ({
	"%^GREEN%^You see a movement out of the corner of your eye.%^RESET%^",
	"%^BOLD%^RED%^The greenhag cackles at you for falling for the voice trick%^RESET%^",
	"%^YELLOW%^The greenhag attemps to scratch at your face.%^RESET%^"
}), 0);
set("aggressive", "attack_fun");
set_emotes(20, ({
	"%^BOLD%^GREEN%^The greenhag screeches and slashes at your face",
	"%^BOLD%^RED%^The greenhag screams at you in a gutteral language",
	"%^BOLD%^BLUE%^The greenhag attacks you with a vengence",
"%^YELLOW%^The greenhag laughs at your puny efforts%^RESET%^"}), 1);
resist = 35 + random(30) + random(20);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(25);
set_spells(({"magic missile"}));
add_money("gold", 1000);
add_money("platinum",random(100));
}
void do_stuff(){
	if(interactive(TP)){
		set("aggressive", 17);
		call_out("attack",5,TP);
}
}
int throw_func(string str) {
	write("You cannot do that, hee hee, cackles the %^GREEN%^greenhag%^RESET%^!");
	return 1;
}
int cast_func(string str) {
write("%^YELLOW%^That ain't a'gonna work, dorlin, hee hee!%^RESET%^");
	return 1;
}
int stab_func(string str) {
write("%^BOLD%^RED%^The hag screeches : You cannot harm me with your puny stabbings%^RESET%^");
	return 1;
}
int kill_ob(object victim, int which){
if(query_invis()) set_invis();
return ::kill_ob(victim,which);
}
