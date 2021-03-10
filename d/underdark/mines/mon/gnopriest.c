//Octothorpe (9/20/08)
//Underdark Mining Caverns, Svirfneblin Priest

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create(){
   ::create();
   set_id(({"gnome","deep gnome","svirfneblin","priest","cleric","svirfneblin priest"}));
   set_name("svirfneblin");
   set_short("%^RESET%^beady-eyed d%^BOLD%^%^BLACK%^ee%^RESET%^p gnome");
   set_long("%^ORANGE%^This gnome is of short stature, even for a "+
      "member of his race. His head is completely bald, and sits atop "+
      "a very skinny frame draped in a simple %^RESET%^grey "+
      "%^ORANGE%^robe.  The only other decorations on his person is a "+
      "simple %^BOLD%^%^WHITE%^mithral %^RESET%^%^ORANGE%^circlet, and "+
      "a %^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^by %^ORANGE%^medallion "+
      "that hangs heavily around his neck.");
   set_race("gnome");
   set_body_type("human");
   set_gender("male");
   set_alignment(4);
   set_size(1);
   set_class("cleric");
   add_search_path("/cmds/cleric");
   set_diety("grumbar");
   set_hd(25,random(4)+1);
   set_guild_level("cleric",35);
   set_mlevel("cleric",35);
   set_max_hp(random(50)+225);
   set_hp(query_max_hp());
   set_stats("strength",18);
   set_stats("dexterity",13);
   set_stats("constitution",12);
   set_stats("intelligence",10);
   set_stats("wisdom",18);
   set_stats("charisma",8);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_new_exp(17,"high");
   set_max_level(20);
   set_overall_ac(-8);
   set_mob_magic_resistance("average");
   set_spells(({
      "maw of stone",
      "earth reaver",
      "earth reaver",
      "earth reaver",
      "maw of stone"
   }));
   set_spell_chance(95);
   add_money("silver", random(100)+30);
   set("aggressive",3);
   set_func_chance(60);
   set_funcs(({"stoneme","strme","healme"}));
}

void stoneme(){
   if(TO->query_property("stone body")){
      return 0;
   }
   new("/cmds/spells/s/_stone_body.c")->use_spell(TO,0,35,100,"cleric");
}

void strme(){
   if(TO->query_property("stone strength")){
      return 0;
   }
   new("/cmds/spells/s/_strength_of_stone.c")->use_spell(TO,0,35,100,"cleric");
}

void healme(){
   if(query_hp() < 125){
      new("/cmds/spells/h/_heal.c")->use_spell(TO,TO,35,100,"cleric");
   }
}

//Adapted from Grazzt's goblins, query_invis suggestion from Nienne
void init(){
   string mrace=TP->query_race();
   object ob;
   ::init();
      if(TP->query_invis()) return;
      if(mrace == "kobold" || mrace == "drow" || mrace == "goblin" || mrace == "ogre" || mrace == "hook horror" || mrace == "orc" || mrace == "hobgoblin" || mrace == "bugbear" || mrace == "gnoll" || mrace == "ogre" || mrace == "half-ogre" || mrace == "ogre-mage" || mrace == "half-drow" || TP->query_property("kobhelp")){
   command ("kill "+TPQN);
   command ("watch");
   }
   if(present("bldscl",TP)){
      command ("kill "+TPQN);
   } 
   if(mrace != "earth elemental"){
      if(present("eele")) return;
      ob = new(MON+"earthelement");
      ob->move(ETO);
      TO->add_follower(ob);
      TO->add_protector(ob);
   }
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
