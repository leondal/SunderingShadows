 
#include "/d/shadow/mon/melnmarn.h";
#include <daemons.h>
inherit MONSTER;

void init(){
::init();
	add_action("stab_func", "stab");
	add_action("cast_func", "cast");
	add_action("throw_func", "throw");
}
void create() {
int resist;
    ::create();
set_name("Mikhail, The Royal Guard");
set_id(({"Mikhail", "royal guard", "mikhail", "Mikhail, The Royal Guard"}));
set("race", "elf");
        set_gender("male");
set_short("%^BOLD%^RED%^Mikhail, The Royal Guard");
set_long("%^RED%^Mikhail, The Royal Guard, stands off to one side of the King and Queen, his sole function is to protect the royal personages.  His face is impassive, stern and scarred.  He is no stanger to battle, either physical nor mental.  The strength in his arms is only outdone by the strength of his will.  He carries weapons, openly and concealed, and he does not appear to have much of a sense of humour, while at his station.%^RESET%^");
	set_level(25);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
	set_overall_ac(-5);
set_property("swarm",1);
set_stats("intelligence", 25);
set_stats("wisdom", 16);
set_stats("strength", 25);
set_stats("charisma", 25);
set_stats("dexterity", 25);
set_stats("constitution", 25);
	set_hd(25,1);
set_exp(7500);
	set_hp(200);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
set_wielding_limbs( ({ "right hand", "left hand", "torso"}) );
        new(WEAPONDIR+"halberd")->move(this_object());
        command("wield halberd in right hand and left hand");
	new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
        command("wear armor");
set_emotes(2,({
	"%^BOLD%^GREEN%^Mikhail glowers and speaks : What is your reason for being here Traveller?"}), 0);
resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(50);
set_spells(({"fireball", "lightning bold"}));
set_emotes(20, ({
	"%^BOLD%^GREEN%^Mikhail cries out : For Elvanta and my king!",
	"%^BOLD%^GREEN%^Mikhail roars in anger : For this, YOU DIE!!!!"
}), 1);
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 18);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^Mikhails' eyes turn %^BOLD%^RED%^blood red%^RESET%^ in anger!");
	return 1;
}
int cast_func(string str){
	write("Your magic fails at the sight of Mikhails' wrath!");
	return 1;
}
int throw_func(string str){
	write("Mikhail stands steadfast, true and immovable!");
	return 1;
	add_money("silver",random(250));
	add_money("gold",random(500));
	add_money("electrum",random(20));
} 
