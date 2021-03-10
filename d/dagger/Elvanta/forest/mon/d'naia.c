
#include <std.h>
inherit MONSTER;

void init(){
	::init();
add_action("stab_func","stab");
}
void create(){
	int resist;
	::create();

set_name("%^GREEN%^d'naia");
set_id(({"D'naia", "d'naia"}));
set_race("devil");
set_gender("female");
set_short("%^GREEN%^D'naia, the wickedly beautiful");
set_long("%^GREEN%^D'naia stands here, waiting for victims, perhaps you could become one.  Her beauty, dark, sullen, evil, is only matched by her temperment, wild, wicked, and deadly.");
	set_level(20);
	set_body_type("humanoid");
	set_class("fighter");
	set("aggressive", 20);
	set_alignment(9);
	set_size(3);
	set_overall_ac(-2);
	set_hd(20,2);
	set_hp(200);
	set_max_hp(query_hp());
set_emotes(2,({
	"%^GREEN%^D'naia gently whispers : come to me, and I will fulfill all your dreams, wishes and nightmares",
	"%^GREEN%^D'naia strokes her body seductively and awaits....",
	"%^GREEN%^D'naia purrs  :  shall we play?"
	}), 0);
set_wielding_limbs(({"right hand", "left hand", "torso"}));
new("/d/dagger/Elvanta/forest/items/wpns/p_dagger")->move(this_object());
command("wield dagger in left hand");
new("/d/dagger/Elvanta/forest/items/armor/devilwings")->move(this_object());
command("wear wings");
resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);
set_guild_level("mage", 20);
set_spell_chance(50);
set_spells(({"animate dead", "magic missile", "scorcher", "fireball", "lightning bolt", "cone of cold"}));
set_exp(15000);
add_money("gold", (1000));
add_money("silver", (1000));
add_money("electrum", (25));
	set("aggressive", "attack_fun");
	set_emotes(20, ({
	"%^GREEN%^D'naia yells in triumph : another fool!",
	"%^GREEN%^D'naia smiles with deadly glee",
	"%^GREEN%^A howl of triumph rips through the air"
	}), 1);
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 19);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^GREEN%^D'naia laughs menacingly");
	return 1;
}
