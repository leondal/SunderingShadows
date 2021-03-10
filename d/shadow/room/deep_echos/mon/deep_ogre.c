#include <std.h>
#include "../deep_echo.h"
inherit "/std/monster";

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
     "yellow and brown skin.  In his hand is a wicked-looking "+
     "weapon and by the menacing expression on his face, he is well-prepared "+
     "to use it.");
  set_body_type("giant");
  set_class("fighter");
  add_search_path("/cmds/fighter"); 
  set_max_level(17);
  set_hd(17,10);
  set_hp(100+random(235));
  set_max_hp(query_hp());
  set_property("full attacks",1);
  set_property("swarm",1);
  set_stats("strength",20);
  set_stats("constitution",18);
  set_stats("intelligence", 6);
  set_stats("wisdom", 6);
  set_stats("charisma",6);
  set_stats("dexterity",6);
  set("aggressive",17);
  set_alignment(9);
  set_size(3);
  add_search_path("/cmds/fighter");
  set_wielding_limbs(({"right hand","left hand"}));
  "/d/common/daemon/randgear_d"->armor_me(TO,"armorlt",90,2);
  add_money("gold",random(100));
  set_spoken("giant");
  //set_exp(6000);
  set_new_exp(15,"normal");
  set_money("silver",random(500));
  switch(random(4)) {
    case 0:{ "/d/common/daemon/randgear_d"->arm_me(TO,"polearm",60,2);
            
            break;}
    case 1: {new(OBJ"drill")->move(TO);
             force_me("wield drill");       

            break;}

    case 2: {"/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",70,2); 
            
            "/d/common/daemon/randgear_d"->armor_me(TO,"shield",60,2);
  
            break;}
    case 3: new(OBJ"gsword")->move(TO);
            force_me("wield sword");
            break;
  }
  force_me("speech snarl");
}
void heart_beat(){
  object *attackers;
  int x;
  ::heart_beat();
  if(!objectp(TO))return; 
  if(query_attackers()==({ })) return;

  attackers = query_attackers();
  x = sizeof (attackers);
  if(random(2)==0)
    force_me("flash ");
  switch (random(3)){
    case 0: force_me("say Me crush you!");
	break;
	case 1: force_me("say Smash!");
	break;
	case 2: force_me("say Me eat you good!");
	break;
	}
	
  
  return;
}
