//basic ogre for Echoes Mtns. adapted from Deku ones & chance of random magical
// items added by Styx, 2002
//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("Ogre");
  set_id(({"ogre","guard","ogre guard","cave_ogre"}));
  set_gender("male");
  set_race("ogre");
  set_short("Ogre guard");
  set_long("This hulking ogre stands just under ten feet tall.  His broad shoulders "+
    "hint at his strength, but his sagging, pale yellow skin speaks of his days in "+
    "the caves.  He is missing many teeth and often has a menacing grin on his face.  "+
    "His long hair is black and greasy, worn hanging in his face.  He is dressed in "+
    "battered, mangy looking furs, and he wields a stout weapon.");
  set_body_type("human");
  set_alignment(9);
  set_hd(10,2);
  set_stats("strength",19);
  set_stats("aggressive",16);
  set_stats("intelligence", 6);
  set_stats("wisdom", 5);
  set_stats("charisma",3);
  set_size(3);
  set_property("swarm",1);
  set_monster_feats(({"parry"}));
  set_wielding_limbs(({"right hand","left hand"}));
  add_money("gold",random(150));
  set_overall_ac(2);
  set_hp(90+random(30));
//  set_exp(800);
  set_new_exp(10,"normal");
  set_max_level(12);
  switch(random(4)) {
    case 0: "/d/common/daemon/randgear_d"->arm_me(TO,"clubm",20,1);
            break;
    case 1: "/d/common/daemon/randgear_d"->arm_me(TO,"bluntl",20,1);   
            break;
    case 2: "/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",20,1);   
            break;
    case 3: new("/d/shadow/obj/special/flail_frost")->move(TO);
            force_me("wield flail");
            break;
  }
}
