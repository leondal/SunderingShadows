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
             "basically similar to a muscular human, but much taller.");
  set_level(10);
  set_hd(10,4);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
  set("aggressive", 18);
  set_alignment(9);
  set_hp(85);
  set_stats("strength", 20);
  set_new_exp(10, "low");
  set_stats("intelligence", 7);
  set_overall_ac(4);
  new("/d/deku/misc/stones")->move(TO);
  new("/d/deku/misc/stones")->move(TO);
  add_money("gold",random(250)+50);
  set_funcs(({"hurl"}));
  set_func_chance(60);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)+10) {
      tell_room(environment(targ), "%^BOLD%^The Frost giant hurls a large "
        "stone towards "+targ->query_cap_name()+" but it misses!",targ);
      tell_object(targ, "%^BOLD%^The Frost giant hurls a large stone at you "
        "but you manage to dodge out of the way!");
      return 1;
    }
    tell_room(environment(targ), "%^BOLD%^The Frost giant hurls a large "
       "stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^BOLD%^The Frost giant hurls a large stone at you!");
    dam = roll_dice(2,10);
    targ->do_damage("torso", dam);
    return 1;
  }
  set_func_chance(0);
}
