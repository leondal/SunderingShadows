#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equipment;

void create(){
   ::create();
   set_name("pirate");
   set_id(({"pirate","second mate","second","mate"}));
   set_short("Second mate");
   set_long("This man has a six inch long, very jagged scar across his left cheek that comes to "
"the corner of his eye.  Several more are visible interspersed with the tattoos on his arms.  He "
"looks like he has seen his share of fights and the cold look in his eyes leaves you no doubt he "
"doesn't take mercy on his opponents, which is probably how he got his rank.");
   set_race("half-elf");
   set_gender("male");
   set_body_type("human");
   set_hd(20,1);
   set_size(2);
   set_wielding_limbs(({"right hand","left hand"}));
   set_max_hp(200);  
   set_hp(200);
   set_exp(4000);
   set_overall_ac(0);
   set_stats("strength",18);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("dexterity",15);
   set_stats("constitution",16);
   set("aggressive",20);
   set_mlevel("fighter",19);
   set_class("fighter");
   set_guild_level("fighter",19);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_funcs(({"rushem","flashem","flashem"}));
   set_func_chance(45);
   add_search_path("/cmds/fighter");
   equipment = new(OBJ"sawdagger");
     equipment->move(TO);
     command("wield dagger");
   "/d/common/daemon/randgear_d.c"->arm_me(TO,"edgedm",75,random(2)+1);
   equipment = new("/d/common/obj/armour/leather");
     equipment->set_property("monsterweapon",1);
     equipment->set_property("enchantment",random(3));
     equipment->move(TO);
     command("wear leather");
   equipment = new(OBJ"woolcloak");
     if(random(2)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wear cloak");
   equipment = new(OBJ"boots");
     if(!random(3)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wear boots");
   add_money("silver",random(200)+100);
   add_money("copper",random(150));
}

void rushem(object targ){
   command("rush "+targ->query_cap_name());
}

void flashem(object targ){
   command("flash "+targ->query_cap_name());
}
