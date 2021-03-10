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
  set_new_exp(10, "low");

  set_hp(103);
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/misc/stones")->move(this_object());
  set_funcs(({"hurl"}));
  set_func_chance(70);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)+10) {
      tell_room(environment(targ), "%^BOLD%^The Stone giant hurls a large "
        "stone towards "+targ->query_cap_name()+" but it misses!",targ);
      tell_object(targ, "%^BOLD%^The Stone giant hurls a large stone at you "
        "but you manage to dodge out of the way!");
      return 1;
    }
    tell_room(environment(targ), "%^BOLD%^The Stone giant hurls a large "
       "stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^BOLD%^The Stone giant hurls a large stone at you!");
    dam = roll_dice(3,8);
    targ->do_damage("torso", dam);
    return 1;
  }
  set_func_chance(0);
}
