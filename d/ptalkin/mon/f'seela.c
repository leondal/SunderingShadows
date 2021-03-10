//monsters by the House of Svaha
#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_property("no bump", 1);
set_name("F'seela");
set_id(({"F'seela", "f'seela", "barkeep", "barkeeper", "elf"}));
set_short("%^CYAN%^F'seela");
    set("aggressive", 0);
set_long(
@DESC
%^CYAN%^F'seela is your average sylvan elf, 5'6" tall, and rather rotund
but, unlike his fellow kinsmen, he is cheerful and outgoing.  His dark
brown eyes seem to take in all the action at once in the tavern.  His
forest garb is covered by a leather apron, decorated with the usual
condiments, beer, ale, food, and the occasional splatter of blood.
DESC
);
    set_gender("male");
set_size(2);
    set_alignment(6);
set("race", "elf");
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
set_languages(({"elvish", "common"}));
set_emotes(2,({
"F'seela sighs : Just read the sign, I'm not sure what the special is today.",
"F'seela laughs : C'mon, eat, drink and be merry, for tomorrow you may die."
}), 0);
}
