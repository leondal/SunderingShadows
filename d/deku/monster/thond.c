#include <std.h>
inherit BARKEEP;
create() {
  ::create();
  set_property("no bump", 1);
  set_name("Thond");
  set_id( ({ "thond", "Thond","barkeep" }) );
  set_short("Thond, the Barkeep");
  set("aggressive", 0);
  set_level(12);
  set("long","Thond is the proprietor of the Sleeping Snake Tavern.");
  set_gender("male");
  set_alignment(4);
  set("race", "barbarian");
  set_hd(13,2);
  add_money("gold", random(200));
  set_body_type("human");
  set_class("fighter");
  set_wielding_limbs(({"right hand"}));
  new("/d/deku/weapons/battle_axe")->move(this_object());
  command("wield axe in right hand");
   set_exp(10);
  set_hp(120);
  set_currency("gold");
  set_menu(
        ({
	"wine" , "home" , "beer" , "ale" , "water"
        }),
        ({
        "alcoholic", "alcoholic", "alcoholic", "alcoholic", "water"
        }),
        ({ 20, 15, 10, 5, 1})
    );
    set_my_mess(
        ({
       "It's the best house wine you ever had.\n",
        "Wow! The home-brewed beer was fantastic.\n",
        "You down some great beer from another age.\n",
	"You appreciate some good imported ale.\n",
        "You chug down some water.\n"
        })
    );
    set_your_mess(
        ({
        "enjoys some good house wine.\n",
        "shakes after having a home-brewed beer.\n",
	"shakes his head in approval of this fine alcohol.\n",
          "enjoys a neighboring town's ale.\n",
        "drinks some water.\n"
        })
    );
    set_menu_short(
        ({
        "House wine",
        "Home-brewed beer",
        "Bottle of beer",
        "Imported Ale",
        "Water"
        })
    );
    set_menu_long(
        ({
        "A house wine from the Sleeping Snake tavern.\n",
        "Home-brewed beer from the Sleeping Snake tavern.\n",
        "A bottle of beer from the brewers in Solace.\n",
         "An imported ale from the neighboring town of Tharis.\n",
        "Some water from the lake outside Solace.\n"
        })
    );
} 
