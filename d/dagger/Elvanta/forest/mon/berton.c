#include <std.h>

inherit BARKEEP;

void init(){
	::init();
add_action("stab_func", "stab");
add_action("cast_func", "cast");
}
create() {
    ::create();
    set_property("no bump", 1);
set_property("swarm", 1);
set_name("Berton");
set_id(({"berton", "barkeep"}));
set_short("Berton, the barkeep");
    set("aggressive", 0);
    set_long("He tends bar and he listens.\n");
    set_gender("male");
    set_alignment(6);
    set("race", "human");
set_level(17);
set_class("fighter");
set_hd(17,10);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(400));
    set_max_mp(query_mp());
    add_money("copper", random(20));
add_money("gold", random(750));
    set_body_type("human");
    set_currency("silver");
set_exp(750);
set_wielding_limbs(({"right hand", "left hand", "torso"}));
new("/d/dagger/Elvanta/forest/items/wpns/lucern_hammer")->move(this_object());
command("wield lucern_hammer in left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
    set_menu(
	({"wine", "beer", "ale","soda","water","coffee"}),
	({ "alcoholic", "alcoholic", "alcoholic","soft drink","water","caffeine" }),
	({ 10, 7, 5, 3, 1, 5 })
    );
    set_my_mess(
	({
	"You savour the taste of the fine wine!\n",
	"You feel the beer flow down your throat!\n",
	"You down some ale.\n",
	"The soda tastes good going down.\n",
	"The water quenches your thirst.",
	"The hot coffee opens your eyes a bit."
	})
    );
    set_your_mess(
	({
	"savours the taste of the fine wine as he drinks it.\n",
        "slowly pours a mug of thick beer down his throat.\n",
        "drinks some hearty ale.\n",
	"sips on a soda.\n",
	"guzzles a glass of water.\n",
	"sips the bitter hot coffee.\n"
        })
    );
    set_menu_short(
        ({
	"A fine wine",
	"A dark beer",
	"A pale ale",
	"A soda pop",
	"A mug of water",
	"A cup of coffee"})
    );
    set_menu_long(
        ({
        "A fine wine from the lands acrossed the mountians.\n",
        "A dark beer brewed to the far west of here.\n",
        "A pale ale brewed in the farming fields outside Shadow.\n",
	"A carbonated soda pop from far away lands.\n",
	"A clear and filtered water, from nearby streams.\n",
	"A bitter strong coffee. Sure to help sober you up a bit.\n"
        })
    );
set_emotes(1, ({
	"%^BOLD%^RED%^Berton asks you : So what'll you have my good friend",
	"%^GREEN%^Berton smiles and says : And how may I help you today, traveller?"
}), 0);
set("aggressive", "attack_fun");
set_emotes(20, ({
	"%^BOLD%^RED%^Berton reaches under the counter for a weapon of sorts",
	"%^GREEN%^Berton yells at you, why the heck are you trying to KILL me, the food ain't THAT bad?",
	"%^YELLOW%^Hey, shouts Berton, no fighting in here, especially with me"
}), 1);
}

void do_stuff(){
	if(interactive(TP)){
	set("aggressive",17);
	call_out("attack",5,TP);
}
}
int stab_func(string str){
	write("%^GREEN%^Berton laughs at your feeble efforts to injure");
	return 1;
}
int cast_func(string st){
	write("%^BOLD%^RED%^Your magic cannot harm me here, shouts Berton");
	return 1;
}
