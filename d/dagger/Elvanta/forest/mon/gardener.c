inherit "/std/monster";
void init(){
	::init();
add_action("throw_func", "throw");
add_action("cast_func", "cast");
add_action("stab_func", "stab");
}
void create() {
int resist;
::create();
set_name("gardener");
set_id( ({"gardener", "the gardener", "a gardener"}) );
set("short", "An old gardener, bent upon the grounds searching for perfection");
set("long", "This old fellow has toiled for many years, to reach the standard of perfection these grounds require.  Many years of bending, raking, cutting, pruning, and planting have left him a bit cranky, a bit crooked, and a bit tired.");
set("race", "human");
set_gender("male");
set_body_type("human");
set_hd(19,11);
set_level(19);
set_size(2);
set_stats("strength",18);
set_stats("intelligence",18);
set_stats("dexterity",14);
set_stats("charisma",7);
set_stats("constitution",15);
set_stats("wisdom",8);
set_max_mp(0);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
set_emotes(4, ({
	"%^BOLD%^CYAN%^The gardener growls : Whadda want?",
	"%^BOLD%^CYAN%^The old man yells : Leave me ALONE!",
	"%^BOLD%^CYAN%^The bent old man snarls at you : Go 'way, I'm busy"
}), 0);
set_money("silver",random(100));
set_exp(500);
set("aggressive",5);
set_property("rake",1);
set_wielding_limbs( ({"right hand", "left hand", "torso"}) );
new("/d/shadow/obj/weapon/rake.c")->move(this_object());
new("/d/shadow/obj/weapon/dagger")->move(this_object());
command("wield dagger in left hand");
command("wield rake in right hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
resist = 30 + random(20) + random(20);
set_property("magical resistance", resist);
set_guild_level("mage", 15);
set_spell_chance(25);
set_spells(({"monster summoning vi"}));
}
int throw_func(string str) {
write("%^YELLOW%^The gardener looks at you with hate filled eyes");
	return 1;
}
int cast_func(string str) {
	write("%^YELLOW%^The gardener sneers at you : You were told that would na' work");
	return 1;
}
int stab_func(string str) {
	write("%^YELLOW%^The gardener hollers : That is dangerous to your soul, traveller, not to mention, your life");
	return 1;
}
