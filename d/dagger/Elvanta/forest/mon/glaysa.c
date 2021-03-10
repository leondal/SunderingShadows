
#include <std.h>
inherit MONSTER;

void init(){
	::init();
	add_action("stab_func", "stab");
}
void create(){
	int resist;
	::create();

set_name("%^BOLD%^RED%^Glaysa, Princess of Hell!");
set_id(({"Glaysa", "glaysa", "Glaysa, Princess of Hell"}));
set_race("devil");
set_gender("female");
set_short("%^RED%^Glaysa, Princess of Hell");
set_long("%^RED%^Glaysa, Princess of Hell stands before you.  Consort to Mammon, daughter of Asmodeus and incredibly beautiful.  Her forked tail, horns and skin are copper coloured.  Laughter hovers across her sensuous lips, but does not reach her feline shaped amber eyes.");
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
	"%^RED%^Glaysa looks upon you and......giggles",
	"%^RED%^Glaysa laughs at your bold stance and licks her lips"
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
	"%^RED%^Glaysa screeches and slashes at your face!",
	"%^RED%^Wing unfurl and a dagger flashes by you!",
	"%^RED%^A how of triumph rends the air!"
	}), 1);
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 19);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^RED%^Glaysa withers you with but a glance!");
	return 1;
}
