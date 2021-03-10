#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("lars");
    set_id( ({ "lars", "barkeep" }) );
    set_short("Lars, the proprietor of the Lars Pub");
   set("aggressive", 0);
  set_level(12);
    set_long("He tends bar and he listens.\n");
   set_gender("male");
   set_alignment(122);
   set("race", "human");
   set_hp(300);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({
	"firebreather", "special", "ale"
	}),
	({ "alcoholic", "alcoholic", "alcoholic" }),
	({ 25, 15, 3 })
    );
    set_my_mess(
	({
	"The firebreather burns your throat!\n",
	"Wow! Lars sure knew how to make drinks when he invented that!\n",
	"You down some ale.\n"
	})
    );
    set_your_mess(
	({
	"screams from the burning of a drink of a firebreather.\n",
	"drinks a special of the house.\n",
	"drinks some ale.\n"
    	})
    );
    set_menu_short(
	({
	"A firebreather",
	"A special of the house",
	"A pale ale"
	})
    );
    set_menu_long(
	({
	"A firebreather from the Lars Pub.\n",
	"A classic special of the house from the Lars Pub.\n",
	"A pale ale brewed in the farming fields outside Praxis.\n"
   	})
    );
}
