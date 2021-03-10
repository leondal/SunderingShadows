
#include <std.h>
inherit MONSTER;

void init(){
	::init();
add_action("stab_func","stab");
add_action("cast_func","cast");
}
void create(){
	int resist;
	::create();

set_name("%^BOLD%^CYAN%^Wirinth");
set_id(({"Wirinth", "wirinth", "druid", "druidess"}));
set_race("elf");
set_gender("female");
set_short("%^BOLD%^CYAN%^Wirinth, Druidess of Elvanta");
set_long("%^GREEN%^Wirinth stands calmly and serenly.  Her gown is a deep green and seems to be unseamed.  Her gown is fastened at each shoulder with a jewelled clip.  A long gold chain catches it below the bust, crosses her back, encircles her waist, and then hugs her hips to an intricate knot low in the front with tassled ends nearly reaching the floor.  Wirinth's gold arms are bare to the shoulders.  A simple ring inscribed by her beloved, and a silver band circling her head, are her only jewellry");
	set_level(20);
	set_body_type("humanoid");
	set_class("fighter");
	set("aggressive", 20);
	set_alignment(9);
set_size(2);
	set_overall_ac(-2);
	set_hd(20,2);
	set_hp(200);
	set_max_hp(query_hp());
set_emotes(2,({
	"%^CYAN%^Wirinth gazes at you and asks : May I help you?",
	"%^CYAN%^Wirinth stands before you and smiles",
	}), 0);
set_wielding_limbs(({"right hand", "left hand", "torso"}));
new("/d/dagger/Elvanta/forest/items/wpns/p_dagger")->move(this_object());
command("wield dagger in left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(50);
set_spells(({"animate dead", "magic missile", "scorcher", "fireball", "lightning bolt", "cone of cold"}));
set_exp(9000);
add_money("gold", (1000));
add_money("silver", (1000));
add_money("electrum", (25));
	set("aggressive", "attack_fun");
	set_emotes(20, ({
	"%^CYAN%^Wirinth nods her head sadly : another fool",
	"%^Wirinth laughs : someone to play with perhaps?"
	}), 1);
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 19);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^GREEN%^Wirinth laughs chillingly");
	return 1;
}
int cast_func(string str){
	write("%^CYAN%^Wirinth  shrugs at you in pity");
	return 1;
}
