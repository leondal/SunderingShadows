#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_property("no bump", 1);
    set_name("giga");
    set_id( ({ "giga", "barkeep" }) );
    set_short("Giga the Visionary");
    set("aggressive", 0);
    set_level(30);
    set_long(
      "Giga is a tall, powerful looking man.  He wears a suit of alloy mesh armor that has been painted with strange red symbols on the chest and arms.  He looks at you through cold, emotionless eyes. He is far from the cheery talkative barkeeps you have come to expect."
    );
    set_gender("male");
    set_alignment(2);
    set("race", "human");
    set_hp(1500);
    add_money("gold", random(200));
    set_property("always interact",1);
    set_body_type("human");
    set_currency("gold");
    set_menu(
      ({
	"firebreather", "felcold", "forcewave", "water"
      }),
      ({ "alcoholic", "alcoholic", "alcoholic", "water" }),
      ({ 25, 15, 45, 1 })
    );
    set_my_mess(
      ({
	"The firebreather burns your throat!\n",
	"%^CYAN%^You shiver and your teeth hurt from the unnaturally cold drink...  %^BOLD%^Your stomach begins to ache!\n",
	"%^BOLD%^%^RED%^You suddenly feel intense pain and cough up blood!\n",
	"The water tastes a tad bitter.\n",
      })
    );
    set_your_mess(
      ({
	"screams from the burning of a drink of a firebreather.\n",
	"turns white as a sheet from drinking the Felcold.\n",
	"screams in pain and coughs %^RED%^blood%^RESET%^ in your face.\n",
	"takes a drink of water.\n"
      })
    );
    set_menu_short(
      ({
	"A firebreather",
	"A Aurataxin Felcold",
	"A %^CYAN%^Glistening Forcewave%^RESET%^",
	"A mug of water"
      })
    );
    set_menu_long(
      ({
	"A firebreather in a black steel stein.\n",
	"A Aurataxin Felcold in an ice coated mug.\n",
	"The drink appears to be alive with hundreds of glowing particles racing around within.\n",
	"A clear and filtered water, from nearby streams.\n"
      })
    );
}
