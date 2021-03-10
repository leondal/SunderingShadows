#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("stone giant");
  set_id(({"stone giant","giant","Stone giant"}));
  set("race","giant");
  set_gender("male");
  set("short","Stone giant");
  set("long","With their gray to gray-brown skins, dark gray to blue-gray\n"+
             "hair, and metallic-looking eyes, stone giants are striking\n"+
             "in appearance.");
  set_level(9);
  set_hd(9,3);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
  set("aggressive", 18);
  set_alignment(5);
  set_stats("strength", 20);
  set_stats("intelligence", 7);
  set_overall_ac(0);
  set_exp(1100);
  set_hp(103);
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/misc/stones")->move(this_object());
  set_funcs(({"hurl"}));
  set_func_chance(40);
}

void hurl(object targ) {
  if(present("stone", this_object())) {
    tell_room(environment(targ), "%^RED%^The Stone giant hurls a large stone towards "+targ->query_cap_name()+"!%^RESET%^",targ);
    tell_object(targ, "%^BOLD%^The Stone giant hurls a large stone at you!!!%^RESET%^");
    targ->do_damage("torso", roll_dice(3,8));
    return 1;
  }
}
