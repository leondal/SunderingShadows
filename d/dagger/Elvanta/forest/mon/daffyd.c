 
#include <std.h>
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
set_name("King Daffyd Strongarm");
set_id( ({"king", "daffyd", "King", "King Daffyd Strongarm"}) );
set("race", "elf");
set_gender("male");
set_short("King Daffyd Strongarm");
set_long("%^BOLD%^CYAN%^The face of King Daffyd is ageless, neither old nor young, though in it is written the memory of many things both glad and sorrowful.  His hair is dark as the shadows of twilight, and upon it sets a circlet of silver; his eyes are grey, as a clear evening and in them is a light like the light of the stars.  Upon his brow sits wisdom, and in his hand, strength.%^RESET%^");
set_level(25);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
	set_property("swarm", 1);
set_overall_ac(-5);
set_stats("intelligence", 20);
set_stats("wisdom", 20);
set_stats("strength", 20);
set_stats("charisma", 20);
set_stats("dexterity", 20);
set_stats("constitution", 20);
set_exp("10000");
set_hd(25,1);
set_exp(7500);
set_hp(200);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
set_emotes(2, ({
	"%^BOLD%^ORANGE%^The king booms  :  Welcome to our domain, weary traveller",
	"%^BOLD%^ORANGE%^King Daffyd addresses you : You are welcome to stay here, or travel to clear the kingdom of the monsters which reside in the gloom",
	"%^BOLD%^ORANGE%^We wish you good tidings, traveller, however, should you attack the good citizens of our city, you will be unwelcome here"
	"%^BOLD%^ORANGE%^King Daffyd warns you : We wish you good tidings, traveller, however, should you attack the good citizens of our city, you will be unwelcome here"
}), 0);
        set_wielding_limbs( ({ "right hand", "left hand" }) );
new("/d/shadow/obj/weapon/two_hand_sword")->move(this_object());
command("wield sword in right hand and left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(50);
set_spells(({"monster summoning vi"}));
add_money("silver", random(2000));
add_money("gold",random(500));
add_money("copper", random(1000));
resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
	set("aggressive", "attack_fun");
	set_emotes(20, ({
	"%^BOLD%^RED%^The King yells : Foolish traveller, you were WARNED!!",
	"%^BOLD%^RED%^The King sighs : What have we done to warrant this action?",
	"%^BOLD%^RED%^King Daffyd roars : You will DIE regretting this, foolish one!"
}), 1);
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 17);
	call_out("attack",5,TP);
}
}
int stab_func(string str){
	write("%^BOLD%^GREEN%^King Daffyd looks upon you with rage in his eyes");
	return 1;
}
int cast_func(string str){
	write("%^BOLD%^GREEN%^The king looks upon you with a withering glance and says 'You cannot do that here, I warned you'");
	return 1;
}
int throw_func(string str){
	write("%^BOLD%^GREEN%^King Daffyd yells  :  YOU ARE ANNOYING ME, FOOLISH ONE!!");
	return 1;
}
