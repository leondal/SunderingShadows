//Added set_max_level to retard cycling - Octothorpe 6/4/09
#include <std.h>

inherit TOWNSMAN;
void create() {
  ::create();
  set_name("Wytoth");
   set_id( ({ "Wytoth", "healer","wytoth"}));
  set_short("Wytoth, healer of Tonerra");
  set("aggressive", 0);
  set_level(19);
  set_long("He is an old man, who tends to the injured villagers.");
  set_gender("male");
  set_alignment(8);
  set("race", "human");
  add_money("gold", random(500));
  set_body_type("human");
  set_property("no attack", 1);
  set_hd(19,3);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_mp(random(500));
  set_max_mp(query_mp());
  set_exp(100);

set_max_level(25);
  set_nwp("healing",20);
}

int should_interact(object ob){
    return 1;
}
