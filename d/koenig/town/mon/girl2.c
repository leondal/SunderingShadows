//updated by Circe 4/4/05 to current code and to be
//more user-friendly
#include <std.h>
inherit NPC;

object player, obj, ob1;
object obj2;
int step, flip, hold;

void create() {
  ::create();
  set_name("haunting spirit");
  set_id(({"girl","little girl","spirit","haunting spirit"}));
  set_race("ghost");
  set_gender("female");
  set_short("%^BOLD%^%^WHITE%^A Mournful Spirit%^RESET%^");
  set_long("%^RESET%^This is a %^BOLD%^ghost%^RESET%^ of a little girl. She has "+
     "been wandering around this land for many years, "+
     "unable to rest. Her %^CYAN%^ghostly eyes%^RESET%^ carry a haunting "+
     "look that hints at her horrific past. Her gaze "+
     "lingers on you, an imploring look on her face.");
  set_body_type("human");
  set_class("fighter");
  set_guild_level("fighter",10);
  set("aggressive",0);
  set_size(1);
  set_hd(10,20);
  set_max_hp(100);
  set_hp(100);
  set_new_exp(10, "normal");
  set_stats("strength",20);
  set_stats("constitution",16);
  set_stats("dexterity",18);
  set_stats("intelligence",10);
  set_stats("wisdom",11);
  set_stats("charisma",10);
  set_property("undead", 1);
  set_mob_magic_resistance("average");
  step = 0;
}

void init() {
   ::init();
   if(interactive(TP) && member_array("Muileann Quest",TP->query_quests()) == -1 && !flip) {
      if((obj = present("black death key",TP)) && !present("boy",TP)) {
         flip = 1;
         call_out("start_talk",1);
         step = 1;
         return;
      }
      if((obj2 = present("boy",TP))){
         if((string)obj2->query_owner() != (string)TPQN) {
            call_out("not_yours",1);
            return;
         }else{
             flip = 1;
             call_out("start_talk2",1);
             return;
         }
      }
   call_out("need_key",1);
   call_out("reset_flip",20);
   return;
   }
}

void start_talk(string str){
   if((int)TP->query_level() < 8){
      force_me("say You are far too weak to help me right now, "+
         "young one. I would not send you to your death.");
      force_me("emote sighs and casts her haunting gaze to the tower.");
      return;
   }
   force_me("say %^BOLD%^%^WHITE%^Excuse me, young "+TP->query_race()+"!  Will you "+
      "help me please?%^RESET%^");
   step = 1;
   return;
}

void not_yours(){
   force_me("say You did not save this boy, "+
      "someone else did!");
   force_me("say Please, I beg you, bring the savior "+
      "to me, so I may reward him!");
   return ;
}

void need_key(){
   force_me("emote looks longingly towards the tower "+
      "before gazing at you with sadness.");
   force_me("say You have not yet found the item you need.  "+
      "Seek out the key...the black skeleton key.");
   return;
}

void start_talk2(string str) {
   object ob;
   if((int)TP->query_level() < 8){
      force_me("say You are too weak to have been able to "+
         "complete this quest. Please send forth the true "+
         "brave one!");
         return;
   }
   force_me("speech proclaim");
   force_me("say Wonderful!  You have saved my brother's life "+
      "and my family's name and line!");
   force_me("say You have shown great courage and prevailed "+
      "where others could not. I shall reward you for this, "+
      "but I'm afraid my gifts to you will not compare to the "+
      "service you have done me and the great peace you have "+
      "given me. Now I can rest in peace. Thank you!");
   step = 5;
   TP->set_quest("Muileann Quest");
   TP->fix_exp(1000000, TP);
   ob = present("boy",TP);
   if(objectp(ob)) ob->remove();
   tell_object(TP,"You feel some gain in experience.");
   tell_object(TP,"%^YELLOW%^You have completed the Muileann Quest!");
   tell_room(ETO,"%^BOLD%^%^CYAN%^The spirit grows translucent "+
      "and fades from sight!");
   remove();
}

void catch_say(string msg){
   object wolf1, wolf2, ob;
   if((strsrch(msg, "yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"help") != -1) && (step == 1)) {
      force_me("say %^RESET%^%^CYAN%^Thank you adventurer, but before you go, "+
         "let me tell you my story so you might know what you are "+
         "up against.");
      tell_room(ETO,"BOLD%^%^WHITE%^The spirit sighs, a breath of wind through the cemetery.");
      force_me("say %^RESET%^%^CYAN%^I was a small child of 10 when the gentleman "+
         "set his henchman to find him a tender and juicy morsel.  "+
         "I was stolen that night from my very bed and prepared "+
         "for him that same night.");
      tell_room(ETO,"BOLD%^%^WHITE%^The spirit scowls.%^RESET%^");
      force_me("say %^RESET%^%^CYAN%^Many have fallen victim to this evil being, "+
         "and it must be stopped! I could not pass on to rest "+
         "in peace knowing that my little brother could one day "+
         "fall into his hands.");
	  force_me("say %^RESET%^%^CYAN%^My greatest fear has come to pass, "+
         "for my brother is now in that tower, and soon they will "+
         "prepare him for the table. He is the only child left to "+
         "my parents and the only one to carry on our name and "+
         "line. At all costs, he must not die!");
      force_me("say %^RESET%^%^CYAN%^If my brother is lucky, he will be saved "+
         "for dessert...");
      tell_room(ETO,"BOLD%^%^WHITE%^The spirit shudders.");
      force_me("say %^RESET%^%^CYAN%^The gentleman loves to eat his desserts "+
         "while they still live, and they come after he has "+
         "gained his fill of what's been cooked and prepared.");
      force_me("say %^RESET%^%^CYAN%^To start your journey you will have to "+
         "enter the crypt and take from the crypt keeper the "+
         "key of life, for you will need it to enter a place "+
         "of magical healing. This place resides in the home "+
         "of the sisters, as does the very door that will "+
         "lead you into the dangers of the tower.");
	   force_me("say %^RESET%^%^CYAN%^Be warned, once you enter that crypt you can not get "+
         "out unless you have that key.");
      force_me("say %^RESET%^%^CYAN%^I wish you luck adventurer... Many before you have failed.");
    step = 2;
    flip = 0;
    call_out("dest_me",3);
    return 1;
  }
  if((strsrch(msg, "no") != -1 || strsrch(msg,"No") != -1) && (step == 1)) {
      tell_room(ETO,"%^BOLD%^%^RED%^The spirit's eyes flash angrily!%^RESET%^");
      force_me("say For your selfishness, I'll send you to the abyss!");
      tell_room(ETO,"%^BOLD%^%^WHITE%^You see the girl raise her arms and hear "+
         "her mumble a few words of summoning.");
      tell_room(ETO,"%^BOLD%^%^BLACK%^To your horror, something answers "+
         "the summons and %^RED%^ATTACKS!");
      TO->kill_ob(TP,1);
      if(!present("wolf", ETO)) {
         ob = new("/d/koenig/town/mon/skelhound");
         ob->move(environment(TO));
         ob->kill_ob(TP,1);
      }
      if(!present("fwolf",ETO)) {
         ob = new("/d/koenig/town/mon/skelhound");
         ob->move(environment(TO));
         ob->kill_ob(TP,1);
      }
    step = 0;
    flip = 0;
    return 1;
  }
  return 1;
}

/*
void reply_back4(string str) {
  tell_room(ETO, "The spirit says: "+str,this_object());
}

void reply_back1(string str) {
  tell_room(ETO, "The spirit crys: "+str,this_object());
}
*/

void reset_flip() {
   flip = 0;
}
     
void dest_me(){
   remove();
}

int test_heart(){return 1;}
