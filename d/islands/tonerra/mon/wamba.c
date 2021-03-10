#include <std.h>

inherit BARKEEP;

create() {
  ::create();
  set_property("no bump", 1);
  set_name("wamba");
  set_id( ({ "wamba", "Wamba" }) );
  set_short("Wamba, water storage supervisor");
  set("aggressive", 0);
  set_long("He is in charge of the village water supply.\n");
  set_gender("male");
  set_alignment(6);
  set("race", "human");
  set_level(12);
  set_hd(12,2);   
  set_max_hp(query_hp());
  add_money("copper", random(20));
  set_exp(20);
  set_body_type("human");
  set_currency("gold");
  set_menu(({"water"}),({"water"}),({2})
  );
  set_my_mess(({"The water quenches your thirst."}));
  set_your_mess(({"guzzles a glass of water.\n"}));
  set_menu_short(({"A mug of water"}));
  set_menu_long(({"A clear and filtered water, from nearby streams.\n"}));
}
