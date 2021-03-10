// /d/islands/tonerra/mon/chumba.c

#include <std.h>

inherit BARKEEP;

create() {
  ::create();
  set_nwp("forage",20,500);
  set_name("chumba");
  set_id( ({ "chumba", "Chumba" }) );
  set_short("Chumba, food storage supervisor");
  set("aggressive", 0);
  set_level(10);
  set_long("She is in charge of the food storage for the village.\n");
  set_gender("female");
  set_alignment(4);
  set("race", "human");
  set_hd(10,0);
  set_max_hp(query_hp());
  add_money("copper", random(200));
  set_body_type("human");
  set_currency("gold");
  set_menu(
    ({"leg of aurumvorax", "gargantua stew"}),
    ({"food", "food"}),
    ({10, 7})
  );
  set_my_mess(
    ({"Best meal you've had in a while!\n",
      "Some of the tasty native stew.\n"
    })
  );
  set_your_mess(
    ({"enjoys some aurumvorax.\n",
      "eats some really good stew.\n"
    })
  );
  set_menu_short(
    ({"A plate of aurumvorax",
      "A bowl of stew"
    })
  );
  set_menu_long(
    ({"A tasty looking plate of some really good aurumvorax.\n",
      "A bowl of some really tasty stew.\n"
   	})
  );
}
