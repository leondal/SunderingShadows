#include <std.h>
inherit BARKEEP;
create() {
  ::create();
  set_property("no bump", 1);
  set_name("Nefen");
  set_id( ({ "nefen", "Nefen","barkeep" }) );
  set_short("Nefen, the Barkeep");
  set("aggressive", 0);
  set_level(12);
  set("long","Nefen is the proprietor of the Bountiful Tappe Tavern.");
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
        "'s head nods slowly in approval of this fine alcohol.\n",
        ", after a squint, looks around for another drink.\n",
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
        "A Death by burning from the Bountiful Tappe tavern.\n",
        "An imported wine from an neighboring city.\n",
        "A bottle of beer from the brewers of Verbobone.\n",
	"A Vodka from far lands.\n",
        "A pale ale brewed in the farming fields outside Verbobone.\n"
        })
    );
} 
