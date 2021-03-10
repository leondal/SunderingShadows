#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
    set_name("Mcdugal");
    set_id(({"Mcdugal","barkeep","mcdugal"}));
    set_short("Mcdugal, the Bartender");
   set("aggressive", 0);
  set_level(12);
    set_long(
@SEETH

SEETH
);
   set_gender("male");
   set_alignment(122);
   set("race", "human");
   set_hp(300);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({
        "deathblow", "special", "ale"
	}),
	({ "alcoholic", "alcoholic", "alcoholic" }),
        ({ 35, 17, 5 })
    );
    set_my_mess(
	({
        "The Deathblow rends your senses!\n",
        "Your not sure if you can handle it, but you'd never say that!\n",
	"You down some ale.\n"
	})
    );
    set_your_mess(
	({
        "begins to cry as they down the rest of there Deathblow.\n",
	"drinks a special of the house.\n",
	"drinks some ale.\n"
    	})
    );
    set_menu_short(
	({
        "A Deathblow",
	"A special of the house",
	"A pale ale"
	})
    );
    set_menu_long(
	({
         "A Deathblow, brewed by Sal himself.\n",
        "A Saturday Night Special from the famous Graez Bar.\n",
        "A fine ale brewed in the royal fields of Graez.\n"
   	})
    );
}
