//by Circe 11/24/04 - parts taken from the imps in Tharis forest
//boss for "evil" version of Lothwaite quest
#include <std.h>
#include <daemons.h>
#include <move.h>
#include "../lothwaite.h"

inherit WEAPONLESS;

string *asked;
int step1;
int step2;
int step3;
int FLAG;

void make_me();
void new_form();
void make_imp();

void create() {
   ::create();
   set_name("imp");
   set_id(({"imp","rat","spider","Imp","devious imp"}));
   set_hd(30,8);
   set_hp(600+random(150));
   add_money("gold",random(200)+200);
   set_attacks_num(2);
   set_stats("dexterity",21);
   set_stats("strength",17);
   make_me();
   set("aggressive",4);
   set_gender("male");
   set_exp(10000+random(1500));
   set_alignment(3);
   set_max_level(35);
}

void make_me() {
   set_long(
      "%^BOLD%^%^BLACK%^This hideous little creature is covered "+
      "with black skin and hovers on small, leathery wings.  "+
      "Its beady %^RED%^eyes %^BLACK%^glitter %^RED%^red%^BLACK%^ "+
      "with a fire all their own.  Curling below it is a slender "+
      "prehensile tail ending in a wicked %^WHITE%^barb%^BLACK%^ "+
      "that reflects light.  Protruding from its head are two "+
      "sharp, twisted %^WHITE%^horns%^BLACK%^.  He seems to shift "+
      "in and out of the shadows.%^RESET%^"
   );
   set_short("A devious little imp");
   set_race("imp");
   set_body_type("human");
   add_limb("tail","torso",0,0,0);
   add_limb("left wing","torso",0,0,0);
   add_limb("right wing","torso",0,0,0);
   set_damage(1,6);
   set("aggressive",4);
   set_hit_funcs((["tail":(:TO,"poison_me":)]));
   set_base_damage_type("piercing");
   set_attack_limbs(({"tail"}));
   set_overall_ac(-13);
}

int poison_me(object targ) {
   tell_object(targ,"%^RED%^The imp hovers close, "+
      "stinging you with his barbed tail!");
   tell_room(ETO,"%^BOLD%^%^RED%^The imp hovers close to "+
      ""+targ->QCN+" and stings "+targ->QO+" viciously!",targ);
   if(!random(4)){
      if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",0)) {
         tell_object(targ,"%^BOLD%^%^RED%^The poison stings your "+
            "veins, and you feel your lungs collapse!");
         if(!objectp(targ)) return 40;
         targ->add_poisoning(30);
         targ->setPoisoner(TO);
      }
   }else{
      tell_object(targ,"%^RED%^You feel your body fighting "+
         "off the poison flowing through it!");
      tell_object(targ,"%^BOLD%^%^CYAN%^You feel you will live!");
      return random(8);
   }
}

void heart_beat() {
   ::heart_beat();
   if(!objectp(TO)) return;
   if(random(4))  return;
   if(query_race() == "imp" && query_attackers() == ({}))
      new_form();
   if(query_race() != "imp" && query_attackers() != ({}))
      make_imp();
   if(query_hp() < 50) {
      run_away();
      set_invis();
   }
}

void new_form() {
   int my_hp;
   object ob;
   if(!objectp(TO)) return;
   seteuid(getuid());
   switch(random(2)) {
    case 0:
      set_name("giantrat");
      set_id( ({ "giantrat","giant","rat","giant rat", "devious imp"}) );
      set_short("A giant rat");
      set_level(10);
      set_long("This giant rat looks a little unusual.  His "+
         "fur has a leathery sort of look to it, although it is "+
         "still fur.  He has tiny, beady eyes that glitter "+
         "%^BOLD%^%^RED%^red%^RESET%^%^CYAN%^, and his claws glisten "+
         "like wet %^BOLD%^%^WHITE%^ivory%^RESET%^%^CYAN%^.  There seems to be "+
         "a small %^RED%^barb %^CYAN%^on the end of his tail - "+
         "how unusual.");
      set_gender("male");
      set_race("rat");
      set_body_type("quadruped");
      set("aggressive",4);
      set_size(1);
      set_attacks_num(2);
      set_base_damage_type("slashing");
      set_attack_limbs(({"right forepaw", "left forepaw"}));
      break;
    case 1:
      set_name("spider");
      set_id(({"spider","giant spider", "devious imp"}));
      set_short("A giant spider");
      set_level(15);
      set_long("This large black spider is covered with a "+
         "leathery carapace.  A wicked %^RED%^red hourglass "+
         "%^CYAN%^is visible upon her belly, which is often "+
         "shown when she rears up on her back.  Her multi-"+
         "faceted eyes are filled with a %^RED%^red spark "+
         "%^CYAN%^that hints at her malicious intent.");
      set_gender("female");
      set_race("spider");
      set_body_type("arachnid");
      set_alignment(5);
      set("aggressive",4);
      set_size(2);
      set_class("fighter");
      set_attack_limbs(({"left pincer", "right pincer"}));
      break;
   }
   tell_room(ETO,"%^BOLD%^%^YELLOW%^You witness a wondrous "+
      "transformation as this creature changes form!");
   return;
}

void make_imp() {
   set_name("imp");
   set_id(({"imp","rat","spider","Imp","devious imp","raven"}));
   set_hd(30,8);
   set_hp(600+random(150));
   set_attacks_num(2);
   set_stats("dexterity",21);
   set_stats("strength",17);
   set_gender("male");
   set_exp(10000+random(1500));
   set_alignment(3);
   set_max_level(35);
   set_long(
      "%^BOLD%^%^BLACK%^This hideous little creature is covered "+
      "with black skin and hovers on small, leathery wings.  "+
      "Its beady %^RED%^eyes %^BLACK%^glitter %^RED%^red%^BLACK%^ "+
      "with a fire all their own.  Curling below it is a slender "+
      "prehensile tail ending in a wicked %^WHITE%^barb%^BLACK%^ "+
      "that reflects light.  Protruding from its head are two "+
      "sharp, twisted %^WHITE%^horns%^BLACK%^.  He seems to shift "+
      "in and out of the shadows.%^RESET%^"
   );
   set_short("A devious little imp");
   set_race("imp");
   set_body_type("human");
   add_limb("tail","torso",0,0,0);
   add_limb("left wing","torso",0,0,0);
   add_limb("right wing","torso",0,0,0);
   set_damage(1,6);
   set("aggressive",4);
   set_hit_funcs((["tail":(:TO,"poison_me":)]));
   set_base_damage_type("piercing");
   set_attack_limbs(({"tail"}));
   set_overall_ac(-13);
   force_me("speech speaks with an insidious hiss");
   tell_room(ETO,"%^BOLD%^%^YELLOW%^You witness a wondrous "+
      "transformation as this creature reveals its true form!");
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("lothwaite_asked2");
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote completely ignores everyone but "+who->query_cap_name()+".");
     return;
   }
   if(FLAG == 1){
      if(strsrch(msg,"gold") != -1) {
         force_me("say %^RED%^Simple tastes, eh?  Nothing wrong with that.");
         who->add_money("gold",15000);
         force_me("emoteat "+name+" gives $N a large sack of gold.");
         FLAG = 0;
         call_out("go_away",0);
         return;
      }
      if(strsrch(msg,"cloak") != -1) {
         force_me("say %^RED%^Here's my end of the bargain.  That's real "+
            "demonskin, you know!");
         obj = new(OBJ"impcloak");
         if (obj->move(who) != MOVE_OK){
            force_me("say %^RED%^Bah, you can pick it up yourself when "+
               "you get your hands free there.");
            obj->move(ETP);
         }
         force_me("emote grins and tosses a cloak.");
         FLAG = 0;
         call_out("go_away",0);
         return;
      }
      if(strsrch(msg,"staff") != -1) {
         force_me("say %^RED%^Here's my end of the bargain.  I won't "+
            "tell you how I make these.");
         force_me("grin");
         obj = new(OBJ"impstaff");
         force_me("emote lifts a staff from the shadows.");
         if (obj->move(who) != MOVE_OK){
            force_me("say %^RED%^Bah, you can pick it up yourself when "+
               "you get your hands free there.");
            obj->move(ETP);
         }
         FLAG = 0;
         call_out("go_away",0);
         return;
      }
      force_me("say %^RED%^Ehh, huh?  Look, I told you.  Say "+
         "%^YELLOW%^gold%^RESET%^%^RED%^, %^BOLD%^"+
         "cloak%^RESET%^%^RED%^, or %^BOLD%^%^BLACK%^staff%^RESET%^"+
         "%^RED%^.");
      return;
   }
   if(strsrch(msg,"out") != -1 || strsrch(msg,"way out") != -1 ) {
      force_me("say %^RED%^Hey, now, we got a deal...I get the belt, "+
         "you get out.  Or you can go talk to the firbolgs if you want.");
      force_me("smirk");
      return;
   }
   if(who->query_quests()) {
     if(member_array("Lothwaite Quest",who->query_quests()) != -1) {
       switch( (string)who->query("lothwaitequest") ) {
         case "G" :
           force_me("say %^RED%^You disappoint me...go away.");
           force_me("emote grins, revealing barbed teeth.");
           break;
         case "E" :
           force_me("say %^RED%^Now, you're my kind of "+race+"!  Come "+
              "back someday and maybe I'll show you some more fun.");
           force_me("cackle");
           break;
          default: tell_object(TP,"Ack! You must have done "+
             "the early version of the quest.  Mail Circe so "+
             "she can fix you.");
          break;
       }
     return;
     }
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say %^RED%^Hey, you!  Remember our deal...");
     if(!random(3))
      force_me("say %^RED%^If you find that belt, bring it to me...the belt "+
         "is mine!!");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("emote hovers just above the nest");
      force_me("say %^RED%^You there!  You looking for some fun?");
      force_me("say %^RED%^I sent out this thief, see, awhile back, but "+
         "he hasn't returned, so our deal is off.");
      force_me("say %^RED%^Think you're interested in some work?  For a "+
         "fitting reward, of course.");
      force_me("grin "+name+"");
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"work") != -1 || strsrch(msg,"fun") !=-1)&& step1 && !step2)        {
      force_me("say %^RED%^Excellent!  Here's how it is, see...");
      force_me("emote rubs his clawed hands together in anticipation.");
      force_me("say %^RED%^These firbolgs are dead, you know, but they "+
         "still have a lot of wonderful things!  There's a belt I want..."+
         "a golden belt, set with jewels.  It belonged to the king.");
      force_me("say %^RED%^Do you know the belt I'm talking about?");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"belt") != -1 || strsrch(msg,"golden") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"firbolg") != -1 || 
   strsrch(msg,"no") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"No") !=-1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("lothwaite_asked2", name);
      }
      force_me("say %^RED%^Ahh, good!  I sent out a thief awhile back, but the "+
         "inept bugger's probably died by now.  Look for his body.");
      force_me("say %^RED%^Bring me the belt, and I'll give you riches!");
      step3 == 1;
		return;
  }
  switch(random(10)){
      case 0:
         force_me("say %^RED%^Do I know you?");
         break;
      case 1:
         force_me("say %^RED%^Hey, you looking for some treasure?");
         break;
      case 2:
         force_me("say %^RED%^I need a new thief!  You interested?");
         break;
      case 3:
         force_me("emote grins, flashing barbed teeth.");
         break;
      case 4:
         force_me("emote shifts form suddenly before returning to his true form.");
         break;
      case 5:
         force_me("emote studies you curiously.");
         break;
      default:
         force_me("emote looks at you and mutters to himself, shaking his head.");
   }
   return;
}

void receive_given_item(object obj){
   object item;
   int size;
   asked = SAVE_D->query_array("lothwaite_asked2");
   if(!objectp(obj)) return;
   if(member_array("Lothwaite Quest",TP->query_quests()) != -1  && 
    (string)TP->query("lothwaitequest") == "G") {
      force_me("say %^RED%^Ehh...thanks, but I don't trust people who help "+
         "those insipid firbolgs.");
      force_me("smirk "+TPQN);
      return;
   }   
   if(member_array(TPQN, asked) == -1 && member_array("Lothwaite Quest",TP->query_quests()) == -1) {
     force_me("say %^RED%^What makes you think I'd want this?  I don't even "+
        "know you.");
     return;
   }   
   if((string)obj->query_name() != "belt of giant strength") {
       force_me("say %^RED%^Wow, you're not bright.  Does this look like what I "+
          "asked for?");
       return;
   }   
   if((string)obj->query_name() == "belt of giant strength") {
      if(member_array("Lothwaite Quest",TP->query_quests()) != -1 && 
       (string)TP->query("lothwaitequest") == "E") {
         force_me("say %^RED%^Most excellent!  You're not so bad, you know that?");
         force_me("say %^RED%^Now, I always keep my bargains.  The belt is mine..."+
            "so tell me what you want - %^YELLOW%^gold%^RESET%^%^RED%^, %^BOLD%^"+
            "cloak%^RESET%^%^RED%^, or %^BOLD%^%^BLACK%^staff%^RESET%^"+
            "%^RED%^.");
         force_me("emote motions in turn to a pile of gold, a red leather cloak, "+
            "and a shadowy staff.");
        force_me("say %^RED%^Just say the word, and it's yours!");
        force_me("say %^RED%^Oh...but I should tell you, you "+
           "won't be able to figure out the staff unless you're "+
           "one of those priestly types who does nothing but "+
           "pray.");
        FLAG = 1;
         force_me("grin "+TPQN+" conspiratorially");
         call_out("open_up",1);
         call_out("reset_give_out",30);
         obj->remove();
         return;
      }
      force_me("emote greedily grabs the belt and grins as he waves his hand and it "+
         "disappears.");
      obj->remove();
      if(member_array(TPQN, asked) != -1) 
        SAVE_D->remove_name_from_array("lothwaite_asked2", TPQN);
//to clean up the array after it's not needed any more
      if(member_array("Lothwaite Quest",TP->query_quests()) == -1){
         force_me("say %^RED%^Most excellent!  You're not so bad, you know that?");
         force_me("say %^RED%^Now, I always keep my bargains.  The belt is mine..."+
            "so tell me what you want - %^YELLOW%^gold%^RESET%^%^RED%^, %^BOLD%^"+
            "cloak%^RESET%^%^RED%^, or %^BOLD%^%^BLACK%^staff%^RESET%^"+
            "%^RED%^.");
         force_me("emote motions in turn to a pile of gold, a red leather cloak, "+
            "and a shadowy staff.");
        force_me("say %^RED%^Just say the word, and it's yours!");
        force_me("say %^RED%^Oh...but I should tell you, you "+
           "won't be able to figure out the staff unless your "+
           "one of those priestly types who does nothing but "+
           "pray.");
        FLAG = 1;
        tell_object(TP,"%^YELLOW%^You have finished the Quest of "+
           "Lothwaite and gained the respect of an Imp!");
        TP->set_quest("Lothwaite Quest");
        TP->set("lothwaitequest","E");
        TP->fix_exp(2000000,TP);
        "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" gave the belt to the "+
           "imp.");
        call_out("open_up",1);
        call_out("reset_give_out",30);
        return;
      }
      force_me("say %^RED%^Go spread more mischief and mayhem!");
      call_out("open_up",1);
      return;
   }
   return;
}

void reset_give_out() { FLAG = 0; }

void go_away() {
   force_me("emote cackles and disappears in a pillar of flame, leaving "+
      "the smell of brimstone.");
   TO->move("/d/shadowgate/void"); 
   TO->remove();
}

void open_up() {
   tell_room(ETO,"%^RED%^Suddenly, the back wall cracks and begins to "+
      "split open!");
   tell_room(ETO,"%^BOLD%^%^RED%^Peering through, you see a narrow exit "+
      "to the ring of stones!");
   "/d/barriermnts/lothwaite/rooms/hidden2"->add_exit(PATHEXIT"stones2","out");
   return;
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
