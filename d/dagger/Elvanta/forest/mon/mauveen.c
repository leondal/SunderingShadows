 
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
set_name("Queen Mauveen Evenstar");
set_id( ({"queen", "mauveen", "Queen", "Queen Mauveen Evenstar"}) );
set("race", "elf");
set_gender("female");
set_short("Queen Mauveen Evenstar");
set_long("BOLD%^RED%^Young she is, and yet, not so.  The braids of her dark hair are touched by no frost, her white arms and clear face are flawless and smooth, and the light of the stars are in her bright eyes, grey as a cloudless night; yet queenly she looks and thought and knowledge are in her glance, as one who has knows many things that the years bring.  Above her brow her head is covered with a cap of silver lace netted with small gems, glittering white.
But her soft grey rainment has no ornament other than a girdle of leaves wrought in silver.%^RESET%^");
set_level(25);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
	set_overall_ac(-5);
set_property("swarm",1);
        set_max_mp(0);
        set_mp(query_max_mp());
set_hd(25,1);
set_exp(7500);
set_hp(200);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
new("/d/shadow/obj/weapon/longsword")->move(this_object());
command("wield longsword in left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
        command("wear armor");
	add_money("silver", random(500));
	add_money("gold",random(500));
resist = 30 + random(30) + random(30);
set_property("magical resistance", "resist");
set_guild_level("mage", 20);
set_spell_chance(50);
set_spells(({"monster summoning vi", "web"}));
} 
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 18);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^BOLD%^BLUE%^Queen Evenstar glares at you hatefully");
	return 1;
}
int cast_func(string str){
	write("%^BOLD%^BLUE%^Mauveen looks upon you witheringly");
	return 1;
}
int throw_func(string str){
	write("%^BOLD%^BLUE%^Queen Mauveen Evenstar stands firm!");
	return 1;
}
