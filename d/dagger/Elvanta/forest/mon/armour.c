 
inherit "/std/monster";
void init() {
	::init();
add_action("stab_func", "stab");
add_action("throw_func", "throw");
add_action("cast_func", "cast");
}
void create() {
int resist;
    ::create();
set_name("armour");
set_id(({"suit of armour"}));
set("race", "armour");
set_short("A suit of armour");
set_long("%^CYAN%^This is a suit of armour, shining brightly and standing approximately six feet tall.  At one time the armour must have been worn by some warrior as the occasional dent shows upon its gleaming surface.  One arm of the armour has a longsword held tightly in its grip, while the other holds a bec-de-corbin resting upon the floor.%^RESET%^");
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
set_alignment(5);
        set_size(2);
set_hd(30,1);
set_stats("intelligence", 15);
set_stats("wisdom", 12);
set_stats("strength", 20);
set_stats("charisma", 12);
set_stats("dexterity", 20);
set_stats("constitution", 20);
set_overall_ac(-1);
set_hp(160);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
set_wielding_limbs( ({"right hand", "left hand", "torso"}) );
new("/d/deku/weapons/longsword")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/bec_de_corbin")->move(this_object());
new("/d/shadow/obj/armor/fullplate")->move(this_object());
command("wield bec de corbin in left hand");
command("wield longsword in right hand");
command("wear fullplate on torso");
resist = 20 + random(30) + random(20);
set_property("magical resistance", resist);
set_guild_level("cleric", 17);
set_spell_chance(25);
set_spells(({"cause critical wounds"}));
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
     set_exp(900);
} 
void do_stuff(){
	set("aggressive", 20);
}
int stab_func(string str) {
	write("You cannot stab the armour, it is too strong");
	return 1;
}
int throw_func(string str) {
	write("You cannot hurt the armour that way");
	return 1;
}
	int cast_func(string str) {
	write("The spell just bounces off of the armour");
	return 1;
}
