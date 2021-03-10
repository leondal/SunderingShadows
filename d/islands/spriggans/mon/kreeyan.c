//quest mob for aarakocra mini-quest on Leilani ~Circe~ 6/2/07
#include <std.h>
#include <daemons.h>
#include "../spriggan.h"

inherit MONSTER;

int step1, step2, step3;
string *asked;


void create(){
   ::create();
   set_name("Kreeyan");
   set_short("Kreeyan, a wandering aarakocra");
   set_id(({"kreeyan","Kreeyan","aarakocra","Aarokocra","wandering arrakocra","birdman"}));
   set_long("%^RESET%^%^CYAN%^Standing about five and a half feet tall, "+
      "this creature seems to be a strange mix of bird and man.  "+
      "His lithe frame is covered in %^RED%^f%^BOLD%^e%^RESET%^"+
      "%^ORANGE%^a%^YELLOW%^th%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^r"+
      "%^RESET%^%^RED%^s %^RESET%^%^CYAN%^that are %^RED%^deep "+
      "red %^CYAN%^along his body and %^RED%^tr%^BOLD%^an"+
      "%^RESET%^%^ORANGE%^sf%^YELLOW%^or%^WHITE%^m %^RESET%^"+
      "%^CYAN%^to brilliant %^YELLOW%^gold %^RESET%^%^CYAN%^"+
      "at the tips of his wings.  Despite his rather small "+
      "size, he has a wingspan of at least twenty feet, and "+
      "he has a somewhat human-like hand midway down each "+
      "wing.  His %^BOLD%^%^RED%^face %^RESET%^%^CYAN%^is "+
      "rather like that of a %^BOLD%^parrot %^RESET%^%^CYAN%^"+
      "with a %^BOLD%^%^BLACK%^hooked beak %^RESET%^%^CYAN%^"+
      "and intelligent, curious eyes.  He wears a %^ORANGE%^"+
      "studded leather breastplate %^CYAN%^and a sheath holding "+
      "six javelins on his back.  His movements are "+
      "quick and fleeting, and he seems somewhat distrustful "+
      "or ill-at-ease, keeping constantly on the move.%^RESET%^");
   set_exp(1); //low exp to make him not worth cycling; shouldn't be able to kill him anyway
   set_race("aarakocra");
   set_body_type("fowl");
   add_limb("right hand","right wing",0,0,0);
   add_limb("left hand","left wing",0,0,0);
   remove_limb("tail");
   set_hd(25,2);
   set_class("ranger");
   set_mlevel("ranger",20);
   set_guild_level("ranger",20);
   set_max_hp(400);
   set_hp(query_max_hp());
   set_alignment(4);
   set_property("full attacks",1);
   set_stats("strength",16); //higher than it would normally be, but strength matters more here
   set_stats("dexterity",20);
   set_stats("intelligence",15);
   set_stats("charisma", 16);
   set_stats("wisdom", 13);
   set_overall_ac(-10);
   add_money("gold",50+random(26));
   set_heart_beat(1);
   force_me("speech speak amid squawks and screeches");
   set_emotes(3,({
      "%^RED%^Kreeyan takes a small hop and tilts his head to the side.%^RESET%^",
      "%^CYAN%^Kreeyan jumps lightly, fluttering his wings.%^RESET%^",
      "%^ORANGE%^With a loud squawk, Kreeyan checks his sheathed javelins.%^RESET%^"
    }),0);
/*  Will need to add moving and nogo eventually - paths aren't there yet :)
    set_nogo(({"/d/dagger/Torm/city/c107","/d/dagger/Torm/city/c111","/d/dagger/Torm/city/c45"}));
*/
}

void init(){
  ::init();
  add_action("xstab", "stab");
  add_action("xstab", "kill");
  add_action("xstab", "rush");
}
//xstab functions borrowed from /d/azha/mon/alradin.c

int xstab(string str){
  object ob;
  if(member_array(str, query_id()) != -1) {
     TO->force_me("emote squawks in protest and takes to the air!");
     TO->force_me("say Such -rawk- treachery!");
     TO->force_me("emote flies away in a great rush of wings.");
     TO->move("/d/shadowgate/void"); 
     TO->remove();
     return 1;
  }
  return 0;
}

void heart_beat(){
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(sizeof(TO->query_attackers()) > 0){
      TO->force_me("emote squawks in protest and takes to the air!");
      TO->force_me("say Such -rawk- treachery!");
      TO->force_me("emote flies away in a great rush of wings.");
      TO->move("/d/shadowgate/void"); 
      TO->remove();
    }
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("KreeyanQuest_asked");
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote tilts his head distractedly as he listens to "+who->QCN+".");
     return;
   }
   if((string)who->query_name() == "circe" && member_array(name, asked) == -1) {
      SAVE_D->set_value("KreeyanQuest_asked", name);
   }
   if(objectp(who)){
      if(member_array("Gathered Ayahuasca for Kreeyan",who->query_mini_quests()) != -1 && (string)who->query_name() != "circe"){
         force_me("say Kreeyan -squawk- thank you again!");
         return;
      }
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("emote hops to the side, tilting his head curiously.");
      force_me("say Squawk!  Me Kreeyan!  You...");
      force_me("emote narrows his eyes for a moment.");
      force_me("say You -eek- help?");
      return;
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"How") != -1)&& step1 && !step2){
      force_me("emote hops back with a flutter of wings.");
      force_me("emote shakes his head and the nods hurriedly.");
      force_me("say Many sick -rawk- in vil-squawk-lage.  Need vines!");
      force_me("say You -skeek- see vines?");
      step2 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"vine") != -1 ||
   strsrch(msg,"Vine") != -1 || strsrch(msg,"Yes") != -1 || 
   strsrch(msg,"no") != -1 || strsrch(msg,"No") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("KreeyanQuest_asked", name);
      }
      force_me("say G-rawk-good!  Kreeyan give basket -reek- for "+
         "vines.  Need -squawk- twenty!");
      force_me("emote drops a small woven basket on the ground before you.");
      new(SOBJ"woven_basket")->move(ETO);
      tell_object(who,"%^BOLD%^%^WHITE%^Kreeyan has asked you "+
         "to collect twenty healing vines in the basket he has "+
         "provided.  You should give it to him when done.%^RESET%^");
      step3 == 1;
      return;
  }
  switch(random(8)){
      case 0:
         force_me("emote twitches his head and ruffles his feathers.");
         break;
      case 1:
         force_me("say You bring -skeek- vines yet?");
         break;
      case 2:
         force_me("say Vines -rawk- all over ground!  Look, look!");
         break;
      case 3:
         force_me("emote skittishly takes to the air.");
         break;
      case 4:
         force_me("emote tilts his head and studies you.");
         break;
      case 5:
         force_me("say Must have -squawk- vines! So sick...");
         break;
      default:
         force_me("emote looks at you hopefully before hopping nervously.");
   }
   return;
}

void receive_given_item(object obj){
   asked = SAVE_D->query_array("KreeyanQuest_asked");
   if(!objectp(obj)) return;
   if(member_array("Gathered Ayahuasca for Kreeyan",TP->query_mini_quests()) != -1 && (string)TP->query_name() != "circe"){
      force_me("emote hops about and squawks as he takes the "+obj->query_short()+".");
      if((string)obj->query_name() == "small woven basket" || obj->is_healing_vine()){
         force_me("say Kreeyan thank -eek- you again!");
      }else{
         force_me("say -rawk- Thank you for gift!");
      }
      force_me("emote carefully puts away the "+obj->query_short()+".");
      obj->remove();
      return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("emote hops away nervously and eyes "+TPQCN+" suspiciously.");
     force_me("say I -skreek- know you?");
     force_me("drop "+obj->query_name()+"");
     return;
   }   
   if((string)obj->query_name() != "small woven basket") {
       force_me("say Thank -skreek- you but this not -rawk- what Kreeyan need!");
       force_me("drop "+obj->query_name()+"");
       return;
   }   
   if((string)obj->query_name() == "small woven basket") {
      force_me("emote opens the basket and tilts his head as he peers inside.");
      if((int)obj->query_internal_encumbrance() < (int)obj->query_max_internal_encumbrance()){
         force_me("say Good start!  Need -rawk- more!");
         force_me("drop "+obj->query_name()+"");
         return;
      }
      force_me("say Enough here!");
      force_me("cheer");
      force_me("say Kreeyan -squawk- never thank you -eek- enough!");
      force_me("emote carefully sets the basket aside, ready to "+
         "be carried away.");
      obj->remove();
      if(member_array(TPQN, asked) != -1) 
         SAVE_D->remove_name_from_array("KreeyanQuest_asked", TPQN);
      if(member_array("Gathered Ayahuasca for Kreeyan",TP->query_mini_quests()) == -1){
         TP->set_mini_quest("Gathered Ayahuasca for Kreeyan",15000,"%^BOLD%^%^GREEN%^Gathered Ayahuasca for Kreeyan%^RESET%^");
         add_money("gold",2500+random(251));
         force_me("give "+query_money("gold")+" gold coins to "+TPQN);
         force_me("say Pay -skreek- for vines!");
         tell_object(TP,"%^BOLD%^%^CYAN%^You've just helped Kreeyan "+
            "the aarakocra gather the vines he needed!%^RESET%^");
         force_me("emote takes flight with the basket in his talons and sails away.");
         TO->move("/d/shadowgate/void"); 
         TO->remove();
      }
      return;
   }
   return;
}