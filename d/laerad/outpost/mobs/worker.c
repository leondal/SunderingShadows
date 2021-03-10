#include <std.h>
#include "../outpost.h"

inherit MONSTER;

create (){
  object ob;
  ::create ();
  set_name("worker");
  set_property("swarm",1);
  set_id(({"worker", "constuction", "torm","construction worker","work"}));
  set_short("Torm constuction worker");
  set_long("This man is a obvious constuction worker. He has a tool-belt with various "+
  "tools around his weist and has a body ordor that rivals the general eggy smell of the "+
  "island. He is obviously a strong man and looks like he could make good use of that slegde hammer");
set_property("swarm",1);
set_gender("male");
  if(!random(2)){
  set_race("human"); 
  } else {
  set_race("half-elf");
  }
set_body_type("human");
set_hd(18,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",20);
  set_property("full attacks",2);
  set_stats("strength",22);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 10);
set_stats("wisdom", 10);
set_stats("constitution", 20);
set_alignment(1);
  set_max_hp(random(100)+200);
  set_hp(query_max_hp());
  set_exp(1000);
set("aggressive", 0);
set_emotes(1, ({"%^BOLD%^say: You are asking for the hammer!!"}), 1);
set_overall_ac(-5);
add_money("gold", 50 + random(100));

  new(OBJ"torm_leather")->move(TO);
  new(OBJ"torm_bracers")->move(TO);
  new(OBJ"sledgehammer")->move(TO);  
  command("wield hammer");
  command("wearall");
  if(random(1000)<200){
  present("leather",TO)->set_property("monsterweapon",1);
  }
  if(random(1000)<200){
	  present("hammer",TO)->set_property("monsterweapon",1);
  }
  if(random(1000)<200){
	  present("bracers",TO)->set_property("monsterweapon",1);
  }
  set_speed(20);
  set_nogo(({ROOMS"1"}));
  set_monster_feats(({
	  "light weapon",
	  "improved two weapon fighting",
	  "strength of arm",
	  "blade block",
	  "toughness",
	  "powerattack",
	  
   }));
}


