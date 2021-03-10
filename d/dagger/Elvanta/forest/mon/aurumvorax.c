
#include <std.h>

inherit MONSTER;

void init() {
	::init();
	add_action("stab_func", "stab");
	add_action("throw_func", "throw");
	add_action("cast_func", "cast");
}
void create(){
	::create();
set_name("aurumvorax");
set_id(({"aurumvorax", "a aurumvorax"}));
set_short("An aurumvorax");
set_long("%^ORANGE%^This aurumvorax has a golden coat, shining and bright as real gold.  Its eight legs are tipped with copper-coloured claws.  This creature has coppery teeth as well.  Its whiskers and mane guard hairs are a tawny bronze colour, and its eyes are silvery with golden pupils.%^RESET%^");
set_overall_ac(0);
set_hd(27,0);
set_hp(100);
set_class("fighter");
set_property("no bump", 1);
set_property("no paralyze", 1);
set_stats("strength", 20);
set_stats("constitution", 21);
set_stats("intellegence", 12);
set_stats("wisdom", 12);
set_stats("dexterity", 20);
set_stats("charisma", 10);
set_exp(2700);
set_size(2);
set_race("aurumvorax");
set_gender("male");
set_body_type("quadruped");
set_emotes(5, ({
	"%^BOLD%^GREEN%^The aurumvorax growls menancingly at you",
	"%^BOLD%^RED%^The aurumvorax takes a swipe at you"}), 0);
set("agressive", "attack_fun");
set_emotes(30, ({
"%^BOLD%^RED%^A deep growl emanates from the aurumvorax",
"%^BOLD%^GREEN%^The aurumvorax leaps to attack you",
"%^YELLOW%^The aurumvorax tries to bite your leg",
"%^BOLD%^CYAN%^The aurumvorax roars in triumph as blood pours from your wounds"
}), 1);
add_limb("leg 1","leg 1",96,0,4);
add_limb("leg 2","leg 2",96,0,4);
add_limb("leg 3","leg 3",96,0,4);
add_limb("leg 4","leg 4",96,0,4);
add_limb("paw 1","leg 1",96,0,4);
add_limb("paw 2","leg 2",96,0,4);
add_limb("paw 3","leg 3",96,0,4);
add_limb("paw 4","leg 4",96,0,4);
set_wielding_limbs(({"right forepaw", "left forepaw", "right rear paw", "left rear paw", "paw 1", "paw 2", "paw 3", "paw 4"}));
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
command("wield claw in right forepaw");
command("wield claw 2 in left forepaw");
command("wield claw 3 in paw 1");
command("wield claw 4 in paw 2");
command("wield claw 5 in paw 3");
command("wield claw 6 in paw 4");
command("wield claw 7 in right rear paw");
command("wield claw 8 in left rear paw");
add_money("gold", (1000));
}
void do_stuff(){
	if(interactive(TP)){
		set("aggressive", 19);
			call_out("attack", 5,TP);
}
}
void attack(object targ){
	command("pierce "+targ->query_name());
	set_invis();
}
int stab_func(string str) {
	write("That doesn't seem to be working");
	return 1;
}
int throw_func(string str) {
	write("You cannot do that");
	return 1;
}
int cast_func(string str) {
	write("That will not work against this beast, you are on your %^BOLD%^CYAN%^OWN%^RESET%^!!");
	return 1;
}
