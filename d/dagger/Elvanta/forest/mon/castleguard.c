 
inherit "/std/monster";
void init(){
	::init();
	add_action("stab_func", "stab");
	add_action("cast_func", "cast");
	add_action("throw_func", "throw");
}
void create() {
    ::create();
        set_name("guard");
        set_id( ({ "guard"  }) );
        set("race", "human");
        set_gender("male");
set("short", "castle guard");
set_long ("%^CYAN%^This is one of the many guards you will run across as you look through the castle.  His job is to inspect each visitor, and decided whether the visitor should be allowed to come in or not.  He stands about five foot six inches tall and has a welcoming smile, however, as you look into his eyes, you see he is no stranger to peril.%^RESET%^");
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
set_hd(20,1);
set_hp(115);
set_overall_ac(3);
set_stats("intelligence", 18);
set_stats("wisdom", 15);
set_stats("strength", 18);
set_stats("charisma", 12);
set_stats("constitution", 20);
set_stats("dexterity", 18);
set_property("swarm",1);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
set_emotes(3, ({
	"%^CYAN%^The guard says :  All are welcome here, but should you wish to fight, you WILL be greviously hurt or killed, just a friendly warning, gentlebeing."
}), 0);
	set_wielding_limbs( ({ "right hand", "left hand", "torso" }) );
new("/d/dagger/Elvanta/forest/items/wpns/bardiche")->move(this_object());
command("wield bardiche in right hand");
	new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
	command("wear armor");
        add_money("silver",random(10));
add_money("gold", random(500));
        add_money("copper",random(20));
set_exp(900);
}
int stab_func(string str){
	write("%^BOLD%^RED%^The guard sneers : Did you really think that would work?");
	return 1;
}
int cast_func(string str){
	write("%^BOLD%^RED%^The guard yells  :  Your powers are nothing here!");
	return 1;
}
int throw_func(string str){
	write("%^BOLD%^RED%^The guard smiles and says : I warned you about fighting, did I not?");
	return 1;
}
