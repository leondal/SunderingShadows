#include "summoned_monster.h"
inherit MONSTER;

create() {
  ::create();
  set_name("troll");
  set("race", "troll");
  set_id(({"troll","Troll"}));
  set_gender("male");
  set("short", "A ugly troll");
  set("long","Trolls are horrid carnivores.  The troll's hide is a \n"+
             "nauseating moss green.  His writhing hair like growth\n"+
             "upon his head is a greenish black, with dull black eyes.\n");
  set_level(7);
  set_ac(4);
  set("aggressive",18);
  set_size(3);
  set_body_type("giant");
  set_class("fighter");
  set_alignment(8);
  set_hd(7,6);
  set_stats("strength",18);
   set_stats("constitution", 20);
  set_sp(query_max_sp(100));
  set_exp(650);
  set_mp(query_max_mp(100));
  set_wielding_limbs(({"right hand","left hand"}));
  set_hp(71);
  add_money("gold", random(500));
  set_funcs(({"bite"}));
  set_func_chance(40);
}

void bite(object targ) {
  int dam;
  if(!targ) return 0;
  tell_room(environment(targ), "The troll bites "+targ->query_cap_name()+" with its mighty teeth!", targ);
  tell_object(targ, "You are bitten by the trolls mighty teeth!");
  dam = 5 + random(5);
   targ->do_damage("torso",dam);
  return 1;
}
