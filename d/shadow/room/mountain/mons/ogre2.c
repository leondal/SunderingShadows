//basic ogre for Echoes Mtns. adapted from Deku ones & chance of random magical
// items added by Styx, 2002
//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("Ogre");
  set_id(({"ogre","hulking ogre","hulk","cave_ogre"}));
  set_gender("male");
  set_race("ogre");
  set_short("Hulking ogre");
  set_long("This brutish ogre stands just under ten feet tall with "+
    "broad shoulders and a slack-jawed looked that makes him appear "+
    "none-too-intelligent.  He is clearly quite strong, but his "+
    "sagging skin and sallow complexion confirms that he spends most "+
    "all his life haunting these caves.  His menacing grin is further "+
    "enhanced by the fact that he is missing every other tooth, and "+
    "his stringy black hair is likewise haphazard - it appears clumps "+
    "have been pulled out here and there, most likely when he was "+
    "disobedient to the slightly smarter guards.");
  set_body_type("human");
  set_alignment(9);
  set_hd(8,2);
  set_stats("strength",19);
  set_stats("aggressive",16);
  set_stats("intelligence", 6);
  set_stats("wisdom", 5);
  set_monster_feats(({"parry"}));
  set_stats("charisma",3);
  set_size(3);
  set_property("swarm",1);
  set_wielding_limbs(({"right hand","left hand"}));
  add_money("gold",random(150));
  set_overall_ac(4);
  set_hp(70+random(25));
//  set_exp(800);
  set_new_exp(8,"normal");
  set_max_level(12);
  switch(random(3)) {
    case 0: "/d/common/daemon/randgear_d"->arm_me(TO,"clubm",20,1);
            break;
    case 1: "/d/common/daemon/randgear_d"->arm_me(TO,"bluntl",20,1);   
            break;
    case 2: "/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",20,1);   
            break;
  }
}
