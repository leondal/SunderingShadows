//Coded by Bane//
#include <std.h>
inherit BARKEEP;
create() {
    ::create();
    set_name("Pandemonium");
    set_id(({"pandemonium","barkeep","Pandemonium","waitress"}));
    set_short("Pandemonium the barmaid");
    set_long(
	"Pandemonium sits at the bar waiting for your order.  "+
	"Dressed in a blood red waitress outfit she mixes drinks "+
	"and cleans the glasses while not busy.  Her green eyes follow "+
	"your every movement and you notice a sly grin move across "+
	"her face."
    );
   set_gender("female");
    set("aggressive",0);
    set_race("human");
    set_hd(15,0);
   set_hp(300);
    set_property("no bump",1);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
        ({
	"demon's fire","heaven's wrath","angel ale","cocktail"
        }),
	({"alcoholic","alcoholic","alcoholic","alcoholic"}),
	({25,15,10,5})
    );
    set_my_mess(
        ({
	"You take a shot of Demon's fire and you drop to the floor in a convulsive fit of pain.\n",
	"You down a glass of Heaven's wrath, coughing up a lung.\n",
	"You chug a tankard of Angel ale.\n",
	"You sip a tasty cocktail.\n"
        })
    );
    set_your_mess(
        ({
	"screams from a shot of Demon's fire and falls to the ground.\n",
	"downs a glass of Heaven's wrath.\n",
	"chugs a tankard of Angel ale.\n",
	"sips a tasty cocktail.\n"
        })
    );
    set_menu_short(
        ({
	"A shot of Demon's fire",
	"A glass of Heaven's wrath",
	"A tankard of Angel ale",
	"A cocktail"
        })
    );
    set_menu_long(
        ({
	"A shot of Demon's fire from the Fallen Angels guild.\n",
	"A glass of Heaven's wrath from the Fallen Angels guild.\n",
	"A tankard of Angel ale from the Fallen Angels guild.\n",
	"A tasty cocktail drink fixed in the Fallen Angels guild.\n"
        })
    );
} 
