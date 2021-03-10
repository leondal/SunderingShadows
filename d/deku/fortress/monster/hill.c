#include <std.h>
#include "/d/common/common.h"

inherit "/std/monster";

void create() {
  ::create();
  set_name("hill giant");
  set_id(({"hill giant","giant","Hill giant"}));
  set_race("giant");
  set_gender("male");
  set("short","Hill giant");
  set("long","This hill giant has a tan to reddish brown skin, brown to \n"+
             "blackish hair, and red-rimmed eyes.  He is dressed in rough\n"+
              "rags or maybe it's skin.");
  set_level(10);
  set_hd(10,2);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
   set_new_exp(10, "low");
  set("aggressive", 18);
  set_alignment(9);
  set_stats("strength", 19);
  set_stats("intelligence", 7);
  set_overall_ac(4);
  add_money("gold",random(250)+50);
  new("/d/deku/misc/stones")->move(TO);
  new("/d/deku/misc/stones")->move(TO);
  new("/d/deku/misc/stones")->move(TO);
  set_wielding_limbs(({"right hand","left hand"}));
  RANDGEAR->arm_me(TO, "bluntl", 20, random(3));
// note will return 0-2 for enchantments, so 2 chances of +1 and one of +2
// IF it gets any enchanment from the 20% chance
  set_hp(125);
  set_funcs(({"hurl"}));
  set_func_chance(40);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)+10) {
      tell_room(environment(targ), "%^BOLD%^The Hill giant hurls a large "
        "stone towards "+targ->query_cap_name()+" but it misses!",targ);
      tell_object(targ, "%^BOLD%^The Hill giant hurls a large stone at you "
        "but you manage to dodge out of the way!");
      return 1;
    }
    tell_room(environment(targ), "%^ORANGE%^The Hill giant hurls a large "
       "stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^ORANGE%^The Hill giant hurls a large stone at you!");
    dam = roll_dice(2,8);
    targ->do_damage("torso", dam);
    return 1;
  }
  set_func_chance(0);
}
