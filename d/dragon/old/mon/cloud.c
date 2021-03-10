#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("cloud giant");
  set_id(({"cloud giant","giant","Cloud giant"}));
  set("race","giant");
  set_gender("male");
  set("short","Cloud giant");
  set("long","Cloud giants have pale blue white to light blue skin, silver\n"+
             "white or brass colored hair.\n");
  set_level(12);
  set_hd(12,7);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
  set("aggressive", 18);
  set_alignment(5);
  set_stats("strength", 23);
  set_stats("intelligence", 7);
  set_overall_ac(2);
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/misc/stones")->move(this_object());
  set_funcs(({"hurl"}));
  set_func_chance(40);
  set_exp(1400);
  set_hp(159);
}

void hurl(object targ) {
  if(present("stone", this_object())) {
    tell_room(environment(targ), "%^CYAN%^The Cloud giant hurls a large stone towards "+targ->query_cap_name()+"!%^RESET%^",targ);
    tell_object(targ, "%^BOLD%^The Cloud giant hurls a large stone at you!!!%^RESET%^");
    targ->do_damage("torso", roll_dice(2,13));
    return 1;
  }
}
