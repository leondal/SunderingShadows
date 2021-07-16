#include <std.h>
#include <daemons.h>
#include "../gantioch.h"

inherit MONSTER;
object ob, *fighterz;
object ob;
int movie;
int step1;

void create() {
   ::create();
   set_name("faris");
   set_id(({"human","faris","merchant"}));
   set_short("Faris, the Merchant");
   set_long(
           "%^BOLD%^%^WHITE%^Faris is a well-dressed man, adorned in fine"+
           " silks and jewelry. He has short dark hair"+
           " which has been spiked. His physique is very toned, and looks in good physical shape.");
   set_class("thief");
   set_guild_level("thief",20);
   set_race("human");
   set_body_type("humanoid");
   set_property("no bows",1);
   set_gender("male");
   set_hd(20,6);
   set_alignment(9);
   command("pose struggling with a woman on a bed");
   set_max_hp(400);
   set_hp(400);
   set_overall_ac(-8);
   set_size(2);
   set("aggressive",1);
   set_exp(15000);
   set_max_level(20);
   ob = new(OBJ+"sfist");
   set_wielding_limbs(({"right hand","left hand"}));
   if(random(5)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   command("wield glove");
   command("wield dagger 2");
   set_property("full attacks",1);
   set_stats("strength",20);
   set_stats("constitution",20);
   set_stats("intelligence",14);
   set_stats("wisdom",12);
   set_stats("charisma",12);
   set_stats("dexterity",21);
   set_func_chance(45);
   set_funcs( ({ "stabit","whirlit","rushit","flashit"}) );
   add_search_path("/cmds/thief");
   add_search_path("/cmds/fighter");
   set_monster_feats(({
      "combat reflexes",
	  "scramble",
	  "dodge",
	  "evasion",
	  "whirl",
	  "ambidexterity",
	  "two_weapon_fighting",
	  "improved_two_weapon_fighting",
	  "rush",
   }));
   step1 = 1;
}

void stabit(object targ) {
   TO->force_me("stab "+targ->query_name());
}

void whirlit(object targ) {
   TO->force_me("whirl "+targ->query_name());
}

void rushit(object targ) {
   TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
   TO->force_me("flash "+targ->query_name());
}

void die(object ob){
    object oba;
tell_room(ETO,"As the man collapses he makes one last snarl, looking to the woman on the bed.");
TP->set_mini_quest("Dispatch the Murderer",1000000,"%^CYAN%^Dispatch the Murderer%^RESET%^");
oba = new(MON"wife");
oba->move(ETO);
   ::die(TO);
}


void ask_1(){
  object *ppl;
  int i;
  string queststring;
  force_me("emote pushes the bag of coins into your chest and smiles at you with a wicked smile.");
  TP->add_money("gold",20000);
  force_me("say %^BOLD%^%^GREEN%^Have a good day...I know I will.");
  force_me("emote gently ushers everyone out of the room, looking back at the shocked female behind him.");
  force_me("say %^BOLD%^%^GREEN%^Now...where were we...?");
  force_me("emote grins evilly as he walks towards the woman.");
  queststring = "%^BOLD%^%^CYAN%^You Left the Wife to Her Fate%^RESET%^";
      fighterz = ({});
      fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      ppl = ({});
      for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,1000000,queststring);
          tell_object(fighterz[i],"\n%^BOLD%^%^RED%^You chose gold over good nature. Wins everytime.%^RESET%^\n");
        }
          fighterz[i]->move(HAMLET"merchanthouse2");
      }
    }
  return 1;
  }

void ask_2(){
force_me("emote rolls his eyes.");
force_me("say %^BOLD%^%^GREEN%^Fine. I did hope that you would be a little more forward thinking.");
force_me("emote shrugs his shoulders slightly, thinking for a moment.");
force_me("say %^BOLD%^%^GREEN%^Well, I didn't want to get blood on my new clothes, but hell...");
        TO->force_me("stab "+TP->query_name());
        force_me("scramble");
      }

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
   call_out("reply_func2",1,msg,TP);
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
   if((strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 ||
   strsrch(msg,"Yep") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"yep") !=-1) && step1 == 1) {
      force_me("say %^BOLD%^%^GREEN%^Finally someone with buisness sense!");
      force_me("emote smiles wickedly as he reaches over to his belt and pulls out a large pouch.");
      force_me("say %^BOLD%^%^GREEN%^You can count it in the hall, I promise it is all there. Now, let me"+
               " get back to...you know...");
      step1 = 0;
      call_out("ask_1",5);
	  return;
  }
}
void reply_func2(string msg, object who){
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if((strsrch(msg,"no") != -1 || strsrch(msg,"No") != -1 ||
   strsrch(msg,"Nope") != -1 || strsrch(msg,"nope") != -1 ||
   strsrch(msg,"Never") != -1 || strsrch(msg,"never") != -1 || strsrch(msg,"not") !=-1) && step1 == 1) {
      step1 = 0;
      call_out("ask_2",5);
	  return;
  }
  }
