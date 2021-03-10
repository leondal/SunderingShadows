//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../echoes.h"
#include "/d/common/common.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("ogre king");
  set_id(({"ogre","Ogre","monster","ogre king","king","cave_ogre"}));
  set_short("Ogre King");
  set_long("This massive ogre is much like the others, ugly, "+
    "smelly, and crude.  Setting him apart, however, is the "+
    "strange crown of bones he wears and the giant scepter-like "+
    "spear at his side.  He stands around ten feet tall and "+
    "has dull yellow skin covered with warty bumps.  His long, "+
    "dark hair is greasy, adding to the rancid smell emanating "+
    "from the furs and hides he wears.");
  set_gender("male");
  set_level(10);
  set_body_type("human");
  set_class("fighter");
  set_alignment(9);
  set_size(3);
  set_hd(10,2);
  set_overall_ac(4);
  set_stats("intelligence",8);
  set_stats("wisdom",6);
  set_stats("strength",20);
  set_stats("dexterity",15);
  set_stats("constitution",12);
  set_hp(random(50)+150);
  set_monster_feats(({"parry"}));
  set_property("aggressive",10);
  set_property("swarm",1);
  set_race("ogre");
  set_wielding_limbs(({"right hand", "left hand"}));
  new(OBJ"ogrespear")->move(TO);
  force_me("wield spear");
  if(random(3)){
     new("/d/deku/armours/ring_p")->move(TO);
     force_me("wear ring");
  }
  add_money("gold",random(100));
//  set_exp(1000);
  set_new_exp(10,"high");
  set_mob_magic_resistance("average");
}
