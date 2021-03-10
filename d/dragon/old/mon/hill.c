#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("hill giant");
  set_id(({"hill giant","giant","Hill giant"}));
  set("race","giant");
  set_gender("male");
  set("short","Hill giant");
  set("long","This hill giant has a tan to reddish brown skin, brown to \n"+
             "blackish hair, and red-rimmed eyes.  He is dressed in rough\n"+
              "rags or maybe its skin.");
  set_level(8);
  set_hd(8,2);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
  set("aggressive", 18);
  set_alignment(9);
  set_stats("strength", 19);
  set_stats("intelligence", 7);
  set_overall_ac(4);
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/weapons/club")->move(this_object());
  command("wield club in right hand");
  set_hp(125);
  set_funcs(({"hurl"}));
  set_func_chance(50);
}

void hurl(object targ) {
  int dam;
  if(present("stone", this_object())) {
    tell_room(environment(targ), "%^BOLD%^The Hill giant hurls a large stone towards "+targ->query_cap_name()+"!%^RESET%^",targ);
    tell_object(targ, "%^BOLD%^The Hill giant hurls a large stone at you!!!%^RESET%^");
    dam = roll_dice(2,8);
    targ->do_damage("torso", dam);
    return 1;
  }
}
