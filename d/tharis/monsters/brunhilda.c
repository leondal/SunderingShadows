#include <std.h>
inherit BARKEEP;

void create() {
  ::create();
  set_property("no bump", 1);
  set_name("Brunhilda");
  set_id( ({"brunhilda", "hildie", "barkeep"}) );
  set_short("Brunhilda, the Barkeep");
  set("aggressive", 0);
  set_level(12);
   set_long("Brunhilda is the proprietor here and although she looks rather appealing she also looks like she could kick your tail on her worst day and your best so it's advisable to just order your drinks and enjoy them.");
   set_gender("female");
  set_alignment(4);
  set_race("barbarian");
  set_hd(13,2);
  add_money("gold", random(200));
  set_body_type("human");
  set_class("fighter");
  set_wielding_limbs(({"right hand"}));
  new("/d/deku/weapons/short")->move(this_object());
  command("wield sword in right hand");
  set_exp(1);
  set_hp(120);
  set_currency("gold");
  set_menu(
        ({
    "fighter special" , "red wine" , "ale" , "tequilla" , "water"
        }),
  ({"alcoholic","alcoholic","alcoholic","alcoholic","water"}),
    ({ 25, 15, 10, 15, 5 })
    );
    set_my_mess(
        ({
    "It burns like fire goin down but your body says 'MORE PLEASE!'\n",
    "Hmmm nice wine but youll bet the harder stuff is better.\n",
    "You down some great ale from another age, MMMMMM smooth.\n",
        "You appreciate the smooth kick of the alcohol.\n",
    "Ahhh, the stuff of life...just plain ol' water.\n"
        })
    );
    set_your_mess(
        ({
        "screams from the burning sensation of the drink.\n",
          "enjoys the refreshing taste of a good wine.\n",
	"shakes his head in approval of this fine alcohol.\n",
	",after a squint, looks around for another drink.\n",
        "drinks some water.\n"
        })
    );
    set_menu_short(
        ({
        "Fighter Special",
          "A red wine",
        "Ale",
        "A shot of Tequilla",
        "A glass of water"
        })
    );
    set_menu_long(
        ({
        "A Special to sooth the hardships of travel.\n",
        "A nice red wine to accompany a dish of red meat.\n",
        "A bottle of ale from the brewers of Verbobone.\n",
        "A Tequilla from far off lands.\n",
        "A glass of good ol' fashion water.\n"
        })
    );
} 
