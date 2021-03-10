//Added an extra id, to deal with a conflict with summoned monsters. Lujke 14 March 08
#include <std.h>
#include "../elfisland1.h"

inherit "/d/darkwood/camps/mon/wonder.c";

void create() {
   object obj;
   ::create();
   set_name("raider");
   set_id(({"orc","raider","orc raider", "xxguardorcxx"}));
   set_short("Orc raider");
   set_long(
       "This is an orc raider from the nearby camp that calls itself the"+
       " Raging Horde. They are a group of orcs that tend to try to invade"+
       " the nearby elven town and ambush lone travelers on the road."
   );
   set_class("fighter");
   set_guild_level("fighter",10);
   set_race("orc");
   set_body_type("humanoid");
   set_gender("male");
   set_hd(10,7);
   set_alignment(6);
   set_max_hp(125);
   set_speed(17);
   set_moving(1);
   set_hp(125);
   set_overall_ac(7);
   set_size(2);
   set("aggressive",17);
   set_exp(3000);
   set_max_level(14);
   add_money("gold",random(100)+50);
   set_wielding_limbs(({"right hand","left hand"}));
   switch(random(4)){
	case 0:  "/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",10,1,50);
      break;
      case 1:  "/d/common/daemon/randgear_d"->arm_me(TO,"edgedm",10,1,50);
	break;
	case 2:  "/d/common/daemon/randgear_d"->arm_me(TO,"bluntm",10,1,50);
	break;
	case 3:  "/d/common/daemon/randgear_d"->arm_me(TO,"blunts",10,1,50);
	break;
	case 4:  "/d/common/daemon/randgear_d"->arm_me(TO,"bluntl",10,1,50);
	break;
	case 5:  "/d/common/daemon/randgear_d"->arm_me(TO,"polearm",10,1,50);
	break;
   }
//new(WEAP+"longsword")->move(TO);
//   command("wield sword in left hand");
//   new(WEAP+"dagger")->move(TO);
//   command("wield dagger in right hand");
//    if(!random(10)) new(OBJ+"studded+1")->move(TO);
//   command("wear studded");
  obj=new("/d/shadow/room/farm/obj/hide");
	if(random(3)){
		obj->set_property("monsterweapon",1);
	}
	obj->move(TO);
   command("wear hide"); 
   set_property("full attacks",1);
   set_stats("strength",17);
   set_stats("constitution",18);
   set_stats("intelligence",11);
   set_stats("wisdom",9);
   set_stats("charisma",9);
   set_stats("dexterity",12);
}
