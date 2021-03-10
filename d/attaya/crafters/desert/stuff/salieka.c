#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_property("no bump", 1);
    set_name("Salieka");
    set_id( ({ "salieka", "barkeep" }) );
    set_short("Salieka, the barkeep");
    set("aggressive", 0);
    set_long("She tends the bar here and always has a smile for you.\n");
    set_gender("female");
    set_alignment(8);
    set("race", "human");
    set_level(35);
    set_hd(12,2);   
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(400));
    set_max_mp(query_mp());
    add_money("copper", random(20));
    set_exp("20");
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({"passion cooler", "saliena's temple","water","cactus juice"}),
	({ "alcoholic","soft drink","water","water" }),
({ 350,300,200,250 })
    );
    set_my_mess(
	({
	"The cooler makes your skin tingle as it caresses your taste buds!\n",
	"The exotic taste of this drink satisfies you.\n",
	"The water quenches your thirst.",
	"The cactus juice energizes you a little."
	})
    );
    set_your_mess(
	({
	"savours the taste of the exotic passion fruits as she drinks it.\n",
	"sips on Salieka's special concoction.\n",
	"guzzles a glass of water.\n",
	"sips the cactus juice.\n"
        })
    );
    set_menu_short(
        ({
	"A passion cooler",
	"salieka's temple",
	"A mug of water",
	"A cactus juice"})
    );
    set_menu_long(
        ({
"A cooler made from a secret ingredient that releases one's inner passions.\n",
	"A special concoction made from fine ingredients imported from Seneca.\n",
	"A clear and filtered water, from within the Crafter's empire.\n",
"A refresing drink made from the pressed flowers of many types of cactus.\n"
        })
    );
}

