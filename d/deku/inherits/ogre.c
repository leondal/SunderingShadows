//basic ogre to inherit for others used on Deku
#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("Ogre");
  set_id(({"ogre"}));
  set_gender("male");
  set("race","ogre");
  set("short", "Ogre guard");
  set("long", "This ogre is like most others - ugly, smelly, crude, and repulsive "
    "to any civilized race.  He looks very evil and doesn't like intruders.");
  set_body_type("human");
  set_alignment(9);
  set_hd(9,2);
  set_stats("strength",20);
  set_stats("aggressive",16);
  set_stats("intelligence", 6);
  set_stats("wisdom", 5);
  set_stats("charisma",3);
  set_size(3);
  set_property("swarm",1);
  set_wielding_limbs(({"right hand","left hand"}));
  add_money("gold",random(150));
  set_overall_ac(4);
  set_hp(90);
  set_exp(750);
  set_max_level(15);
  "/d/common/daemon/randgear_d.c"->arm_me(TO,"clubm",0,0);
}
