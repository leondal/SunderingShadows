//Octothorpe (9/6/08)
//Underdark Mining Caverns, Svirfneblin Master Inherit

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create(){
   object ob;
   object ob1;
   ::create();
   set_id(({"gnome","deep gnome","svirfneblin"}));
   set_name("svirfneblin");
   set_short("%^RESET%^d%^BOLD%^%^BLACK%^ee%^RESET%^p gnomish miner");
   set_long("%^ORANGE%^This lightly armored gnome participates in "+
      "the mining operation.  He is wielding a solid mining pick, and is "+
      "clothed in a light, leather jack.  This gnome has %^BOLD%^%^BLACK%^"+
      "gray %^RESET%^%^ORANGE%^pulled over a compact, wiry frame.  The "+
      "miner moves about with the skill and confidence of a veteran "+
      "warrior, suggesting that the miners, and the guards that patrol "+
      "the area, are one and the same.%^RESET%^");
   set_race("gnome");
   set_body_type("human");
   set_gender("male");
   set_alignment(4);
   set_size(1);
   set_class("fighter");
   add_search_path("/cmds/fighter");
   set_hd(25,random(4)+1);
   set_guild_level("fighter",25);
   set_mlevel("fighter",25);
   set_max_hp(random(50)+225);
   set_hp(query_max_hp());
   set_stats("strength",18);
   set_stats("dexterity",18);
   set_stats("constitution",12);
   set_stats("intelligence",10);
   set_stats("wisdom",11);
   set_stats("charisma",8);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_new_exp(17,"normal");
   set_max_level(20);
   set_overall_ac(-5);
   set_speed(70);
   set_moving(1);
   set_mob_magic_resistance("average");
   set_wielding_limbs(({"left hand","right hand"}));
   ob1 = new("/d/underdark/obj/sboots");
   ob1->move(TO);
   ob1->set_property("monsterweapon",1);
   command("wear boots");
   ob = new("/d/shadow/virtual/mon/gpick");
   ob->move(TO);
   ob->set_property("monsterweapon",1);
   command("wield pick");
   add_money("silver",random(100)+20);
   set("aggressive",3);
   set_func_chance(35);
   set_funcs(({"rushit","flashit","flashit","flashit"}));
   add_attack_bonus(random(8));
   set_monster_feats(({
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

//Adapted from Grazzt's goblins, query_invis suggestion from Nienne
void init(){
   string mrace=TP->query_race();
   ::init();
   if(TP->query_invis()) return;
   if(mrace == "kobold" || mrace == "drow" || mrace == "goblin" || mrace == "ogre" || mrace == "hook horror" || mrace == "orc" || mrace == "hobgoblin" || mrace == "bugbear" || mrace == "gnoll" || mrace == "ogre" || mrace == "half-ogre" || mrace == "ogre-mage" || mrace == "half-drow" || TP->query_property("kobhelp")){ 
      command ("kill "+TPQN);
   } 
   if(present("bldscl",TP)){
      command ("kill "+TPQN);
   } 
/*   if(mrace == "kobold"){ //put on hold as this cound potentially stack up indefinitely... N, 3/11
      add_attack_bonus(query_attack_bonus()+1);
   }*/
}

//Thanks to Nienne for the following code
void die(object ob){
   int i, flag;
   object myob, myob2, myob3, *mytarg;
   mytarg=TO->query_attackers();
   flag = 0;

   if(sizeof(mytarg)){
      for(i=0; i< sizeof(mytarg); i++)
      if(userp(mytarg[i])) flag = 1;
   }
   if(!flag){
      myob=present("leather jack");
         if(myob){
            myob->move("/d/shadowgate/void");
            myob->remove();
         }
      myob2=present("boots");
      if(myob2){
         myob2->move("/d/shadowgate/void");
         myob2->remove();
      }
      myob3=present("scaled shirt");
      if(myob3){
         myob3->move("/d/shadowgate/void");
         myob3->remove();
      }
   }
   ::die();
}
