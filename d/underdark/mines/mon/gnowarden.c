//Octothorpe (9/8/08)
//Underdark Mining Caverns, Burrow Warden
//Based on Rosinden
///d/shadow/room/ekibi/mon/rosinden.c

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit MONSTER;

int step1;
int step2;
string *asked;

void create(){
   object ob1;
   object ob2;
   ::create();
   set_id(({"gnome","deep gnome","svirfneblin","burrow warden","veteran","pietram","steadstone","Pietram",}));
   set_name("pietram");
   set_short("%^RESET%^Pietram Steadstone, Veteran Burrow Warden");
   set_long("%^ORANGE%^This gnome moves about with an air of "+
      "confidence, and appears to be in command of this band of "+
      "svirfneblin.  His face is wrought by many years out in the "+
      "wilderness of the Underdark.  Tired %^CYAN%^bl%^BLUE%^u%^CYAN%^e "+
      "%^ORANGE%^are set within deep eye sockets on his %^BOLD%^"+
      "%^BLACK%^dusk%^RESET%^y %^ORANGE%^face.%^RESET%^");
   set_race("gnome");
   set_body_type("human");
   set_gender("male");
   set_alignment(4);
   set_size(1);
   set_class("mage");
   set_guild_level("mage",29);
   set_mlevel("mage",29);
   add_search_path("/cmd/mage");
   set_diety("grumbar");
   set_hd(29,random(4)+1);
   set_spells(({
      "gust of wind",
      "greater shout",
      "magic missile",
      "magic missile",
      "lower resistance",
      "powerword stun",
      "prismatic spray",
      "prismatic spray",
      "chain lightning"
   }));
   set_spell_chance(75);
   set_overall_ac(-10);
   set_stats("intelligence",18);
   set_stats("wisdom",17);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_max_hp(random(100)+225);
   set_hp(query_max_hp());
   set_new_exp(17,"boss");
   set_max_level(20);
   set_overall_ac(-10);
   set_mob_magic_resistance("average");
   set_property("spell penetration",45);
   set_wielding_limbs(({"left hand","right hand"}));
   ob1 = new(OBJ"earthamulet");
   ob1->move(TO);
   command("wear amulet");
   ob2 = new(OBJ"gnorobe");
   ob2->move(TO);
   command("wear robe");
   set("aggressive",3);
   command("speak wizish");
   command("speech %^BOLD%^%^YELLOW%^state in a gravelly tone%^RESET%^");
   set_func_chance(30);
   set_funcs(({"stoneme","helpme"}));
   add_money("silver", random(10000)+30);
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void receive_given_item(object obj){
   object ob;
   if(!objectp(obj)) return;
   if(!objectp(TP)) return;
   if((string)obj->query_name() == "mask of the deep wyrm") {
      obj->remove();
      force_me("emote nods abruptly.");
      force_me("say Many thanks surface dweller, you have done a great "+
         "deed for Callarduran Smoothhands.");
      if(!userp(TP)) return;
      if(member_array("Assisted the Svirfneblin",TP->query_mini_quests()) == -1){
         tell_object(TP,"%^BOLD%^You've just finished Assisted the "+
            "Svirfneblin!");
         TP->set_mini_quest("Assisted the Svirfneblin",500000,"Assisted the Svirfneblin");
      }
      if(ob = present("gldstr",TP)){
         ob->move("/d/shadowgate/void");
         ob->remove();
      }
      force_me("say Take this small token of our gratitude.");
      TP->add_money("electrum",2000+random(1000));
      force_me("give "+query_money("electrum")+" electrum coins to "+TPQN);
      if(present("wardens",TO)) force_me("give robe to "+TPQN);
      else if(present("boots",TO)) force_me("give boots to "+TPQN);
      return;
   }
   force_me("say Hmm, this is not exactly what I had in mind.");
   force_me("emote throws the item into the pile of rocks in the middle "+
      "of the floor, where it disappears.");
   obj->remove();
   return;
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(objectp(current) && who != current) {
      force_me("emote seems annoyed with the interruption and returns "+
         "his attention to "+who->QCN+".");
      return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ail") != -1) && !step1){
      if(member_array("Assisted the Svirfneblin",TP->query_mini_quests()) != -1){
         force_me("say Have you dispatched our kobold foes yet?"),
         force_me("emote shifts his weight and touches the amulet "+
            "around his neck.");
         return;
      }
      force_me("emote thoughtfully rubs his chin.");
      force_me("say Perhaps you could assist us in bringing peace to "+
         "these caverns, surfacer.");
      force_me("say Would you like to help us and gain the favor of "+
         "Callarduran Smoothhands?");
      force_me("emote nods to himself as if agreeing to the venture "+
         "by proxy.");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"kay") != -1 || strsrch(msg,"elp") != -1 || strsrch(msg,"Ok") != -1 || strsrch(msg,"ok") != -1) && step1 && !step2){
      force_me("emote clears his throat.");
      force_me("say These tunnels are unique due to the ancient and "+
         "very potent faerzress node located in the cavern to the "+
         "northeast.");
      force_me("say The faerzress has warped what you know as the Weave "+
         "inside that cavern.  It has also imbued the very earth in the "+
         "area with mysterious properties that we do not fully "+
         "understand.");
      force_me("say We are here to mine for the faerzress-imbued ores "+
         "and minerals.  Unfortunately, the faerzress node has also "+
         "attracted the attention of a sinister power, and has brought "+
         "our mortal enemies, kobolds, within close proximity.");
      force_me("say Our mining expedition is not equipped to confront "+
         "the kobolds directly, but perhaps you can deal a crippling "+
         "blow that can give us enough time to summon reinforcements.");
      force_me("say What do you say, will you help us?");
      force_me("emote raises an eyebrow in a questioning manner.");
      step2 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"kay") != -1 || strsrch(msg,"help") != -1 || strsrch(msg,"Ok") != -1 || strsrch(msg,"ok") != -1 || strsrch(msg,"ure") != -1) && step2 == 1){
      force_me("say Excellent.");
      force_me("say The entrance to the kobold camp can be found to the "+
         "northeast of the large faerzress node in the main cavern.");
      force_me("say Seek out and kill their leader, also bring back "+
         "evidence of the kobolds' master.");
      force_me("say When you return with the evidence, you shall be "+
         "rewarded.  Go now, and may The Lord of Deepearth protect "+
         "you.");
      force_me("emote nods to himself and turns away to survey the "+
         "mining operation.");
      new(OBJ"gnotoken")->move(TP);
      step1 = 0;
      step2 = 0;
      return;
   }
}

void stoneme(){
   if(TO->query_stoneSkinned()){
      return 0;
   }
   new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,29);
}

void helpme(object targ){
   object obx;
   force_me("emote begins rubbing the %^RED%^r%^BOLD%^%^RED%^u"+
      "%^RESET%^%^RED%^by %^RESET%^amulet around his neck whilst "+
      "muttering an incantation.");
   tell_room(ETO,"The circle of runes in the middle of the floor begin "+
      "to %^CYAN%^gl%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^w %^RESET%^softly"+
      "...then suddenly a large form materializes out of the pile of "+
      "rocks in the center of the circle!");
   obx = new(MON+"earthelement");
   obx->move(ETO);
   TO->add_follower(obx);
   TO->add_protector(obx);
}    

void init(){
   string mrace=TP->query_race();
   ::init();
   if(TP->query_invis()) return;
   if(mrace == "kobold" || mrace == "drow" || mrace == "goblin" || mrace == "ogre" || mrace == "hook horror" || mrace == "orc" || mrace == "hobgoblin" || mrace == "bugbear" || mrace == "gnoll" || mrace == "ogre" || mrace == "half-ogre" || mrace == "ogre-mage" || mrace == "half-drow"){
      command ("kill "+TPQN);
   new("/cmds/spells/w/_warriors_constitution.c")->use_spell(TO,TO,29);
   new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,29);
   }
   if(present("bldscl",TP)){
      command ("kill "+TPQN);
   }      
   if(mrace == "kobold"){
      add_attack_bonus(query_attack_bonus()+1);
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
      myob=present("wardens");
         if(myob){
            myob->move("/d/shadowgate/void");
            myob->remove();
         }
      myob2=present("boots");
      if(myob2){
         myob2->move("/d/shadowgate/void");
         myob2->remove();
      }
      myob3=present("ruby amulet");
      if(myob3){
         myob3->move("/d/shadowgate/void");
         myob3->remove();
      }
   }
   ::die();
}
