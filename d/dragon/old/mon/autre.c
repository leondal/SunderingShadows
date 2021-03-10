#include <std.h>
inherit BARKEEP;
create() {
  ::create();
  set_property("no bump", 1);
  set_name("autre");
  set_id( ({ "autre", "Autre","barkeep" }) );
  set_short("Autre, the Barkeep");
  set("aggressive", 0);
  set_level(12);
  set("long","Autre is an attractive, physically fit 48 year old human.  She\n"+
             "is respected by virtually everyone in the town of Sanctuary.");
  set_gender("female");
  set_alignment(4);
  set("race", "human");
  set_hd(13,2);
  add_money("gold", random(200));
  set_body_type("human");
  set_class("fighter");
  set_wielding_limbs(({"right hand"}));
  set_exp(1000);
  set_hp(120);
  set_currency("gold");
  set_guild_level("fighter",6);
  set_menu(
        ({
	"burningdeath" , "wine" , "beer" , "vodka" , "ale"
        }),
        ({ "alcoholic", "alcoholic", "alcoholic","alcoholic","alcoholic" }),
        ({ 25, 15, 10, 15,5 })
    );
    set_my_mess(
        ({
          "When the Death by burning hits your tongue, you drop to the floor in convulsive fits of pain.\n",
          "Wow! That is a very fine imported wine.\n",
        "You down some great beer from another age.\n",
	"You appreciate the result of the trade of this city.\n",
        "You chug down some ale.\n"
        })
    );
    set_your_mess(
        ({
        "screams from the burning sensation of the drink.\n",
          "enjoys the refreshing taste of an imported wine.\n",
	"shakes his head in approval of this fine alcohol.\n",
	",after a squint, looks around for another drink.\n",
        "drinks some ale.\n"
        })
    );
    set_menu_short(
        ({
        "A death by burning",
          "An imported wine",
	"A bottle of beer",
	"A shot of Vodka",
        "A pale ale"
        })
    );
    set_menu_long(
        ({
        "A Death by burning form the Bountiful Tappe tavern.\n",
        "An imported wine from an neighboring city.\n",
        "A bottle of beer from the brewers of Verbobone.\n",
	"A Vodka from far lands.\n",
        "A pale ale brewed in the farming fields outside Verbobone.\n"
        })
    );
} 
