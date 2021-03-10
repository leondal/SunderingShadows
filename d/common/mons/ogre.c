/*basic ogre file - inherit and change whatever is needed.  Be sure to add treasure, weapons, and equipment, as well as adjust levels and exp if needed. */

#include <std.h>
inherit MONSTER;

create() {
  ::create();
  set_name("ogre");
  set_id(({"ogre","monster"}));
  set_gender("male");
  set_race("ogre");
  set_short("ogre");
  set_long("This hulking ogre stands just under ten feet tall.  His broad shoulders "+
    "hint at his strength, but his sagging, pale yellow skin speaks of his days in "+
    "the caves.  He is missing many teeth and often has a menacing grin on his face.  "+
    "His long hair is black and greasy, worn hanging in his face.  He is dressed in "+
    "battered, mangy looking furs, and he wields a stout weapon.");
  set_body_type("human");
  set_alignment(9);
  set_hd(8,2);
  set_stats("strength",19);
  set_stats("aggressive",16);
  set_stats("intelligence", 6);
  set_stats("wisdom", 5);
  set_stats("charisma",3);
  set_size(3);
  set_property("swarm",1);
  set_wielding_limbs(({"right hand","left hand"}));
  set_overall_ac(4);
  set_hp(80+random(20));
  set_exp(750);
  set_max_level(15);
}
