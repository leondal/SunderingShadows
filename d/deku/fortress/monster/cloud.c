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
  set_func_chance(60);
   set_new_exp(10, "low");
  set_hp(159);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)+10) {
      tell_room(environment(targ), "%^ORANGE%^The Cloud giant hurls a large "
        "stone towards "+targ->query_cap_name()+" but it misses!",targ);
      tell_object(targ, "%^ORANGE%^The Cloud giant hurls a large stone at you "
        "but you manage to dodge out of the way!");
      return 1;
    }
    tell_room(environment(targ), "%^BOLD%^%^CYAN%^The Cloud giant hurls a large "
       "stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^BOLD%^%^CYAN%^The Cloud giant hurls a large stone at you!");
    dam = roll_dice(2,13);
    targ->do_damage("torso", dam);
    return 1;
  }
   set_func_chance(0);
}

init(){
    ::init();
     force_me("block down");
}
