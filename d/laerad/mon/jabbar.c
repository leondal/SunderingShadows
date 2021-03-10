// adding id of laeradmon *Styx* 12/20/03, last change 10/31/98

#include <std.h>
inherit BARKEEP;
create() {
    ::create();
   set_property("no bump", 1);
    set_name("Jabbar");
    set_id(({"jabbar","Jabbar","barkeep", "laeradmon"}));
    set_short("Jabbar the Oasis barkeep");
   set("aggressive", 0);
  set_level(12);
    set_long(
	"Jabbar is a very large man. Massive arms rest across his chest "+
	"as he sits in the shade waiting for your order. A turbin rests "+
	"atop his head keeping the sun from his face. He is wearing "+
	"a fine silk vest, a pair of white breeches, and some sandals."
    );
    set_gender("male");
   set("race", "human");
   set_hp(300);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
        ({
	"water" , "twister" , "sandstorm" , "ale"
        }),
	({ "water", "alcoholic", "alcoholic", "alcoholic" }),
	({ 5000, 10, 15, 5 })
    );
    set_my_mess(
        ({
	"You drink some water.\n",
	"You down a mug of Desert Twister.\n",
	"You chug a mug of Sandstorm.\n",
	"You sip a tasty Ale.\n"
        })
    );
    set_your_mess(
        ({
	"drinks some water.\n",
	"downs a mug of Desert Twister.\n",
	"chugs a mug of Sandstorm.\n",
	"sips a tasty Ale.\n"
        })
    );
    set_menu_short(
        ({
	"A mug of Water",
	"A mug of Desert Twister",
	"A mug of Sandstorm",
	"A mug of Ale"
        })
    );
    set_menu_long(
        ({
	"A mug of crystal clear water.\n",
	"A mug of Desert Twister from the waste's of Laerad.\n",
	"A mug of Sandstorm from the waste's of Laerad.\n",
	"A mug of fine Ale from the waste's of Laerad.\n",
        })
    );
} 
