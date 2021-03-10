#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_property("no bump", 1);
    set_name("Collin");
    set_id( ({ "collin" }) );
    set_short("Collin, the Coffee Shop owner");
    set("aggressive", 0);
    set_long("He spends most of his time helping customers, and cleaning the shop.\n");
    set_gender("male");
    set_alignment(6);
    set("race", "human");
    set_level(10);
    set_hd(9,3);   
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(70));
    set_max_mp(query_mp());
    add_money("gold", random(30));
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({"wine", "beer", "ale","soda","water","coffee"}),
	({ "alcoholic", "alcoholic", "alcoholic","soft drink","water","caffeine" }),
	({ 10, 7, 5, 3, 1, 5 })
    );
    set_my_mess(
	({
	"You drink the aged wine.\n",
	"You about gag from the taste of bear.\n",
	"You chug some ale.\n",
	"You giggle from the soda.\n",
	"You feel better after the watter.",
	"You feel much more sicker after drinking the coffee."
	})
    );
    set_your_mess(
	({
	"smiles after drinking the aged wine.\n",
    "gags from the bear.\n",
    "chugs some ale.\n",
	"giggles after drinking the soda.\n",
	"drinks a clean glass of water.\n",
	"about throws up from the coffee.\n"
        })
    );
    set_menu_short(
        ({
	"A aged wine",
	"A cool beer",
	"A pale ale",
	"A soda",
	"A glass of water",
	"A cup of coffee"})
    );
    set_menu_long(
        ({
    "A aged wine that is several years old.\n",
    "A cool beer from the local store.\n",
    "A pale ale from another world.\n",
	"A soda pop from the local botteling company.\n",
	"A clear spring water, from nearby spring.\n",
	"A cup of coffee with 2 lumps of sugar, the way you like it.\n"
        })
    );
}

