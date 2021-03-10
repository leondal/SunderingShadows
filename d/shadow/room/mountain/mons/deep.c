//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
#include <std.h>
inherit MONSTER;

void create() {
object obj;
  ::create();
  set_name("deep ogre");
  set_id(({"ogre","deep","deep ogre","cave_ogre"}));
  set_gender("male");
  set_race("ogre");
  set_short("Deep Ogre");
  set_long("This massive ogre is around ten feet tall.  Uglier even than "+
     "his surface cousins, he has broad, bulging shoulders with mottled "+
     "yellow and brown skin.  He wears a simple, flea-ridden skin around "+
     "his waist with mangy brown fur.  In his hand is a wicked-looking "+
     "weapon and by the menacing expression on his face, he is well-prepared "+
     "to use it.");
  set_level(10);
  set_body_type("giant");
  set_class("fighter");
  set("aggressive",18);
  set_alignment(9);
  set_size(3);
  set_hd(10,3);
  set_wielding_limbs(({"right hand","left hand"}));
  "/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",25,1,25);
  add_money("gold",random(100));
  set_hp(100+random(35));
   set_monster_feats(({"parry"}));
  set_max_hp(query_hp());
//  set_exp(900);
  set_new_exp(10,"normal");
  if(random(100) > 79){
	  obj = new("/d/common/obj/armour/leather_plate.c");
	  if(random(100) > 79) {obj->set_property("enchantment",1);}
	  obj->set_size(3);
	  obj->move(TO);
	  command("wear leather");
  }  	  
}
