#include <std.h>
#include "../gantioch.h"
#include <move.h>

inherit MONSTER;
object ob, *fighterz;
int step1;
int step2;

void create(){
   	::create();
   	set_name("zathon");
   	set_short("Zathon, Justice of the Peace");
   	set_id(({"zathon","justice","human"}));
   	set_long("%^CYAN%^This noble looking man is middle aged, with"+
             " a slight %^BOLD%^%^WHITE%^gray %^RESET%^%^CYAN%^in his hair."+
             " His clothes are made of well-sewn layers, and he has a few"+
             " pieces of simple jewerly on his hand. He looks to have a"+
             " signet ring of some type on his right hand.");
   	set_race("human");
   	set_gender("male");
   	set_hd(25,8);
   	set_max_hp(520+random(50));
   	set_hp(query_max_hp());
   	set_overall_ac(-10);
   	set_alignment(8);
   	set_class("wizard");
	set_class("cleric");
   	set_mlevel("wizard",25);
	set_mlevel("cleric",25);
   	set_level(25);
   	set_stats("intelligence",22);
   	set_stats("wisdom",22);
   	set_stats("charisma",11);
   	set_stats("strength",15);
   	set_stats("constitution",15);
   	set_stats("dexterity",18);
	add_search_path("/cmds/wizard");
	add_search_path("/cmds/priest");
	set("aggressive",0);
	force_me("wearall");
   	set_exp(1000);
     	add_money("gold",random(10));
	add_money("silver",random(7));
	add_money("copper",random(2));
   	force_me("speech say in a refined manner");

}

void init(){
   ::init();
   add_action("ask_em","ask");
}


void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
    object *ppl;
    int i;
    string queststring;

   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote sits in a proper manner he speaks to "+who->QCN+".");
     return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ail") != -1) && !step1){
            force_me("emote peeks out from inside a cart.");
      force_me("say Greetings, Welcome to the Lord's Home.");
      force_me("say You look like a person able to handle yourself in battle...");
	  force_me("emote nods and gestures you closer.");
	  force_me("say My name is Zathon, Justice of the Peace for these lands."+
		" We have a few matters which are troubling this area, and need assistance."+
		" Will you aid us in the endeavors? Our patrols are already heavily tasked."+
		" We will of course repay you for your efforts.");
      step1 = 1;
	  return;
   }
   if((strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 ||
   strsrch(msg,"No") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"no") !=-1) && step1 == 1) {
      force_me("say Good.");
      force_me("emote writes a few things down on a piece of paper at his desk.");
      force_me("say Now, the person we wish you to stop is...shall we say...dangerous.");
      force_me("say A gnoll leader to the north has been raiding caravans and logistical routes that have been trying to "+
               "bring supplies to the blossoming town to the west. Recent reports indicate that villagers have gone missing."+
               " Please try to find them, hopefully alive.");
      force_me("say I would recommend you bring a couple friends, he and his crew have killed quite a few sent to dispatch them.");
      force_me("emote looks up and nods to "+who->QCN+".");
      force_me("say Please %^YELLOW%^bring%^RESET%^ back his axe as"+
		" proof he has been dispatched. It is his most prized posession.");
      force_me("emote nods again, going back to his work.");
	  force_me("say Let Jarmila Bless your travels.");

      queststring = "%^BOLD%^%^CYAN%^Agreed to Save the Slaves!%^RESET%^";
      fighterz = ({});
      fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      ppl = ({});
      for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,0,queststring);
        }
      }
    }

      step1 = 0;
      step2 = 0;
	  return;
  }
  }

void receive_given_item(object obj){
   object reward;
   if(!objectp(obj)) return;
   if(!objectp(TP)) return;
   if((string)obj->query_name() == "chieftainaxe") {
      force_me("say You have done it? Indeed!  This is his battleaxe!");
      force_me("emote stands up, nodding as he examines the item.");
      command("drop axe");
      force_me("say I am impressed.");
      force_me("emote smiles to you.");
      force_me("say As I promised, I will give you a reward, and also"+
		" inform the Lord of the house of your good deeds.");
      if(!userp(TP))  return;
      if(member_array("%^BOLD%^%^RED%^Dispatch the Murderer!",TP->query_mini_quests()) == -1) {
         tell_object(TP,"%^CYAN%^You Dispatched the Merciless Gnoll Leader!%^RESET%^");
      }
      tell_object(TP,"Zathon reaches down into a small chest and pulls something out to give to you.");
      reward = new(OBJ"lordsring");
      if((int)(reward->move(TP))!=MOVE_OK){
         force_me("say Oh, you seem to be encumbered, I shall place this on the table.");
         force_me("emote places a ring on the table.");
         reward->move(ETP);
         return 1;
      }else{
         force_me("say As a reward for assisting the Lord of the Keep.");
         tell_room(ETO,"Zathon gives a ring to "+TPQCN+"",TP);
         tell_object(TP,"Zathon hands you a ring.");
         return 1;
      }
      return;
   }
   force_me("say This is not his axe.");
   force_me("emote tosses the item into a wastebasket next to him.");
   obj->remove();
   return;
}
