#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("frost giant");
  set_id(({"frost giant","giant","Frost giant"}));
  set("race","giant");
  set_gender("male");
  set("short","Frost giant");
  set("long","Frost giants have dead white or ivory skin, blue-white or \n"+
           "yellow hair, and pale blue eyes.  This giant's build is \n"+
             "basically similar to a muscular human, but taller.");
  set_level(10);
  set_hd(10,4);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
  set("aggressive", 18);
  set_alignment(9);
  set_hp(85);
  set_stats("strength", 20);
  set_stats("intelligence", 7);
  set_overall_ac(4);
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/misc/stones")->move(this_object());
  set_funcs(({"hurl"}));
  set_func_chance(20);
}

void hurl(object targ) {
  if(present("stone", this_object())) {
    tell_room(environment(targ), "%^MAGENTA%^The Frost giant hurls a large stone towards "+targ->query_cap_name()+"!%^RESET%^",targ);
    tell_object(targ, "%^BOLD%^The Frost giant hurls a large stone at you!!!%^RESET%^");
    targ->do_damage("torso", roll_dice(2,10));
    return 1;
  }
  return 1;
}
