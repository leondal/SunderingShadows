#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_property("no bump", 1);
set_name("Diric");
set_id( ({ "diric", "barkeep"}) );
set_short("Diric, the barkeep");
    set("aggressive", 0);
    set_long("He tends bar and he listens.\n");
    set_gender("male");
    set_alignment(6);
    set("race", "human");
    set_level(12);
    set_hd(12,2);   
set_property("no kill", 1);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(400));
    set_max_mp(query_mp());
    add_money("copper", random(20));
    set_body_type("human");
    set_currency("silver");
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
}

