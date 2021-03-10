//ogres kept as slaved by the drow spy below echos
// slightly better equiped then normal ogres
#include <std.h>
#include "../deep_echo.h"
inherit "/std/monster";

create() {
  ::create();
  set_name("Ogre");
  set_id(({"ogre","guard","ogre guard","cave_ogre"}));
  set_gender("male");
  set_race("ogre");
  set_short("Armored ogre");
  set_long("This hulking ogre stands just under ten feet tall."+
    "  His broad shoulders "+
    "hint at his strength, but his sagging, pale yellow"+
    " skin speaks of his days in "+
    "the caves.  There is a strange brand on his face.  "+
	"He is missing many teeth"+
    " and often has a menacing grin on his face.  "+
    "His long hair is black and greasy, worn hanging in his face."+
    "  For some reason he seems well equipped.");
  set_body_type("human");
  set_alignment(9);
  set_hd(11,10);
  //set_exp(3000);
  set_new_exp(11,"normal");
  set_property("swarm",1);
  set_stats("strength",20);
  set_stats("aggressive",16);
  set_stats("intelligence", 6);
  set_stats("wisdom", 5);
  set_stats("charisma",3);
  set_stats("dexterity",10);
  set_size(3);
  set_property("swarm",1);
  set_wielding_limbs(({"right hand","left hand"}));
  add_money("gold",random(150));
  set_overall_ac(2);
  set_hp(210+random(80));
  set_max_level(13);
  switch(random(4)) {
    case 0:{ "/d/common/daemon/randgear_d"->arm_me(TO,"polearm",20,1);
            "/d/common/daemon/randgear_d"->armor_me(TO,"armorlt",20,1);

            break;}
    case 1: {"/d/common/daemon/randgear_d"->arm_me(TO,"bluntl",20,1); 
            "/d/common/daemon/randgear_d"->armor_me(TO,"armornp",20,1);
            "/d/common/daemon/randgear_d"->armor_me(TO,"shield",20,1);

            break;}

    case 2: {"/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",20,1); 
            "/d/common/daemon/randgear_d"->armor_me(TO,"armorpl",20,1);
            "/d/common/daemon/randgear_d"->armor_me(TO,"shield",20,1);
  
            break;}
    case 3: new(OBJ"gsword")->move(TO);
            force_me("wield sword");
			"/d/common/daemon/randgear_d"->armor_me(TO,"armorlt",20,1);
            break;
  }
}
