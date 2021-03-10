
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

set_name("%^GREEN%^Mika, Princess of Elvanta");
set_id(({"Mika", "mika", "princess", "Princess"}));
set_race("elf");
set_gender("female");
set_short("%^GREEN%^Mika, Princess of Elvanta");
set_long("%^BOLD%^BLUE%^Mika sits upon a chair by the harpsichord.  Her gown is of teal satin lined with silver.  The long sleeves are turned back to reveal that contrast.  The sleeves themselves are cut long at the back of the arms, reaching quite nearly to her slippers.  A fabulous silver cape descends to the floor behind, held in place by silver beaten leaves.  Her face is surrounded by long wavy tresses of auburn.  A lacework of silver mesh high lighted with smallgems and pearls covers her head.");
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
	"%^GREEN%^Mika smiles",
	"%^GREEN%^Mika looks at you and asks : Are you lost?",
	"%^GREEN%^Mika wonders : what are you doing here?"
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
	"%^GREEN%^Mika looks at you pitingly",
	"%^GREEN%^Mika says : I really dont want to fight, however...."
	}), 1);
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 19);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^GREEN%^Mika laughs");
	return 1;
}
int cast_func(string str){
	write("%^GREEN%^Mika shrugs");
	return 1;
}
