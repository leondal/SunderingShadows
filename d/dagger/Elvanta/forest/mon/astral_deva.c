#include <std.h>

inherit MONSTER;

void init() {
	::init();
add_action("stab_func", "stab");
add_action("throw_func", "throw");
add_action("cast_func", "cast");
}
reset()
{
::reset();
}

void create() {
	int resist;
	::create();

set_author("Svaha");
set_name("Astral Deva");
set_id( ({"astral deva", "deva", "Deva", "Astral Deva"}) );
set("race", "deva");
set_gender("female");
set("short", "An Astral Deva");
set("long", "She is tall, slender and graceful.  Her skin is golden matching her shimmering hair.  Her eyes are amber and her wings are glowing white tinted with gold.  She is here to guard the goodness of Elvanta and to strike down evil.");
set_level(30);
set_body_type("human");
set_class("fighter");
set("aggressive", 10);
set_property("swarm", 1);
set_size(2);
set_stats("strength", 25);
set_stats("intelligence", 25);
set_stats("wisdom", 20);
set_stats("dexterity", 25);
set_stats("constitution", 25);
set_stats("charisma", 20);
set_overall_ac(-6);
set_hd(27,44);
set_exp(8500);
set_hp(200);
set_overall_ac(-5);
set_wielding_limbs(({"right hand", "torso"}));
new("/d/dagger/Elvanta/forest/items/wpns/mmace")->move(this_object());
command("wield mace in right hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(25);
set_spells(({"dispel magic", "magic missile", "scorcher"}));
add_money("gold", 1000);
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 17);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^BOLD%^CYAN%^The deva looks at you with pity in her eyes");
	return 1;
}
int throw_func(string str) {
	write("%^BOLD%^RED%^As you try to injure the deva, her eyes begin to glow");
	return 1;
}
int cast_func(string str) {
	write("%^GREEN%^The deva tells you softly : Your magic cannot harm me");
	return 1;
}
