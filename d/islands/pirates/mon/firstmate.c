#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equipment;

void create(){
   ::create();
   set_name("pirate");
   set_id(({"pirate","first mate","first","mate"}));
   set_short("First mate");
   set_long("This man has a patch over his right eye, though the gaze of his left is cold and hard.  "
"He is dressed in rough clothing, though it seems chosen to allow him easy movement. He has the look "
"of someone whose orders are obeyed without question, and he looks like he can use the weapons he "
"holds quite efficiently.");
   set_race("human");
   set_gender("male");
   set_body_type("human");
   set_hd(20,1);
   set_size(2);
   set_wielding_limbs(({"right hand","left hand"}));
   set_max_hp(250);  
   set_hp(250);
   set_exp(5000);
   set_overall_ac(0);
   set_stats("strength",19);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("dexterity",13);
   set_stats("constitution",16);
   set("aggressive",20);
   set_mlevel("fighter",24);
   set_class("fighter");
   set_guild_level("fighter",24);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_funcs(({"rushem","flashem","flashem"}));
   set_func_chance(45);
   add_search_path("/cmds/fighter");
   equipment = new(OBJ"whalebone");
     equipment->move(TO);
     command("wield dagger");
//Removing the following since it's getting wielded before the rapier, and Capt. Rust also has the random gear daemon.  Octothorpe 5/7/09
   //"/d/common/daemon/randgear_d.c"->arm_me(TO,"edgedm",75,random(2)+1);
   equipment = new("/d/common/obj/armour/studded");
     if(random(2)) equipment->set_property("monsterweapon",1);
     equipment->set_property("enchantment",random(2)+1);
     equipment->move(TO);
     command("wear studded");
   equipment = new(OBJ"rapier");
     if(!random(3)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wield rapier");
   new(OBJ"leathercoif")->move(TO);
     command("wear coif");
   add_money("silver", random(400)+100);
   add_money("copper", random(50)+20);
   set_mob_magic_resistance("average");
}

void rushem(object targ){
   command("rush "+targ->query_cap_name());
}

void flashem(object targ){
   command("flash "+targ->query_cap_name());
}
