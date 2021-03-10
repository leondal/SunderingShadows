//Octothorpe (1/5/09)
//Underdark Mining Caverns, Kobold Champion

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create(){
   object ob;
   object ob1;
   ::create();
   set_id(({"kobold","champion","kobold champion"}));
   set_name("kobold kommando");
   set_short("%^RESET%^%^ORANGE%^kobold stained in %^BOLD%^%^BLACK%^black%^RESET%^");
   set_long("%^ORANGE%^This scrawny creature barely reaches above three "+
      "feet in height. Its scaly skin is covered in a %^BOLD%^%^BLACK%^"+
      "black pigment%^RESET%^%^ORANGE%^, and is partially clothed in "+
      "studded leather and dungarees. Unfortunately for any non-kobolds "+
      "though, their stench is hardly as simple as their clothing. "+
      "It is best described as a cocktail of a stagnant pool of water "+
      "and wet dogs, but in this case, this kobold smells more like a "+
      "dead dog in stagnant water. Its dark %^RED%^red %^ORANGE%^eyes "+
      "gleam with sinister intent.%^RESET%^");
   set_race("kobold");
   set_body_type("human");
   set_gender("male");
   set_alignment(3);
   set_size(1);
   set_class("thief");
   add_search_path("/cmds/thief");   
   set_class("fighter");
   add_search_path("/cmds/fighter");
   set_hd(28,random(2)+4);
   set_guild_level("fighter",28);
   set_mlevel("fighter",28);
   set_guild_level("thief",28);
   set_mlevel("thief",28);
   set_max_hp(random(150)+175);
   set_hp(query_max_hp());
   set_stats("strength",18);
   set_stats("dexterity",18);
   set_stats("constitution",12);
   set_stats("intelligence",9);
   set_stats("wisdom",11);
   set_stats("charisma",8);
   set_skill("stealth",20);
   set_skill("athletics",20);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_wimpy(1);
   set_speed(70);
   set_moving(1);
   set_scrambling(1);
   set_new_exp(17,"high");
   set_max_level(20);
   set_overall_ac(-15);
   set_wielding_limbs(({"left hand","right hand"}));
   ob = new(OBJ"kobstudded");
   ob->move(TO);
   command("wear studded");
   ob1 = new("/d/shadow/virtual/mon/kclaws");
   ob1->move(TO);
   ob1->set_property("monsterweapon",1);
   command("wield claws");
   add_money("copper", random(800)+50);
   set("aggressive",6);
   set_fighter_style("thug");
   set_func_chance(30);
   set_funcs(({"rushit","flashit","rushit","flashit","rushit"}));
   add_attack_bonus(1);
   set_monster_feats(({
      "dodge",
	  "evasion",
	  "mobility",
	  "scramble",
	  "spring attack",
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
   if(mrace == "gnome" || mrace == "svirfneblin" || mrace == "halfling" || mrace == "elf" || mrace == "hook horror" || mrace == "dwarf"){
      command ("stab "+TPQN);
      add_attack_bonus(query_attack_bonus()+1);
   }
   if(present("gldstr",TP)){
      command ("kill "+TPQN);
   } 
}

//Thanks to Nienne for the following code
void die(object ob){
   int i, flag;
   object myob, *mytarg;
   mytarg=TO->query_attackers();
   flag = 0;

   if(sizeof(mytarg)){
      for(i=0; i< sizeof(mytarg); i++)
      if(userp(mytarg[i])) flag = 1;
   }
   if(!flag){
      myob=present("studded");
         if(myob){
            myob->move("/d/shadowgate/void");
            myob->remove();
         }
   }
   ::die();
}
