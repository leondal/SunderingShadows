 
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
        set_name("guard");
        set_id( ({ "guard"  }) );
        set("race", "human");
        set_gender("male");
        set("short", " gate guard");
set("long", "The guard stands by the iron gate of the grounds.  Hard-faced with distinctly Elven features and eyes that seem tired and old.  As you glance at him you are chilled by the way his eyes stare back at you.");
	set_level(15);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
set_exp(1000);
	set_stats("intelligence", 15);
	set_stats("wisdom", 15);
	set_stats("strength", 18);
	set_stats("charisma", 20);
	set_stats("dexterity", 20);
	set_stats("constitution", 25);
set_hp(120);
set_max_mp(query_hp());
        set_mp(query_max_mp());
set_hd(20,1);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
set_wielding_limbs( ({"right hand", "left hand", "torso", "head"}) );
new("/d/dagger/Elvanta/forest/items/armor/helm")->move(this_object());
command("wear helm on head");
        new(WEAPONDIR+"halberd")->move(this_object());
        command("wield halberd in right hand and left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
        command("wear armor");
	add_money("silver", random(1000));
	add_money("gold", random(500));
	add_money("copper", random(500));
} 
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 18);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^CYAN%^The guard glares at your puny efforts");
	return 1;
}
int cast_func(string str){
	write("%^CYAN%^The guard informs you that your attempts are futile");
	return 1;
}
int throw_func(string str){
	write("%^CYAN%^The guard sneers at you");
	return 1;
}
