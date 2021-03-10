#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob, *fighterz;
int step1;
int step2;
int step3;

void create() {
   ::create();
   set("aggressive",0);
   set_name("slave");
   set_level(10);
   set_gender("female");
   set_alignment(1);
   set_languages( ({ "common","elven","wizish" }) );
   command("speak wizish");
   set_property("swarm",0);
   set_id( ({"elf","woman","slave"}) );
   set_short("An average-looking elf");
   set_long("%^RESET%^This elf stands before you, trembling slightly. She is very dirty"+
            " and looks to have been mistreated for some time. She has a broom in her hand"+
            " and looks to have been recently cleaning. She eyes you cautiously"+
            " with an obviously hopeful look. Perhaps if you %^BOLD%^%^YELLOW%^ask%^RESET%^"+
            " her, she will tell you what she wants.");
   set_race("elf");
   set_emotes(3,({
		"The elf sweeps the ground casually.",
		"The elf looks about nervously.",
		"The elf coughs quietly.",
  }),0);set_hd(20,10);
   add_money("gold",random(100));
   set_body_type("human");
   set_size( 2 );
   set_property("no attack", 1);
   set_hp(24);
   set_max_hp(24);
   set_exp(10);
}

init()
{
  ::init();
  add_action("ask","ask");
}

/*
Adjusting these first two functions to be more intuitive and responsive ~Circe~ 7/24/19
int ask(string str){
if ((str=="elf") || (str=="slave")){
if (step3 == 1){return 1;}
else;{
  tell_object(ETO,"%^BOLD%^%^WHITE%^You motion to the elf and she comes over to you.%^RESET%^");
  tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" motions to the elf and he moves over to you.%^RESET%^",ETO);
  call_out("ask_1",1);
  step3 = 1;
  return 1;}
}
}

void ask_1(){
   force_me("say %^BOLD%^%^MAGENTA%^The gnoll wanted you to fight him first.");
   force_me("emote glances about.");
   force_me("say %^BOLD%^%^MAGENTA%^You have to kill him to get out of this place or get your
stuff.");
   call_out("ask_2",7);
   return;
}
*/

int ask(string str){
   if(!str){
      tell_object(TP,"What would you like to ask? Perhaps you could <ask the slave>.");
      return 1;
   }
   if(str == "elf" || str == "slave" || str == "the slave" || str == "the elf"){
      if (step3 == 1){
         force_me("say %^BOLD%^%^MAGENTA%^Did you get the key?%^RESET%^");
         return 1;
      }else{
         tell_object(TP,"%^BOLD%^%^WHITE%^You motion to the elf, and she shuffles over to you.%^RESET%^");
         tell_room(ETO,"%^BOLD%^%^WHITE%^"+TPQCN+" motions to to the elf, and she shuffles over to them.%^RESET%^",TP);
         call_out("ask_1",1);
         step3 = 1;
         return 1;
      }
   }else{
      return 0;
   }
}

void ask_1(){
   force_me("say %^BOLD%^%^MAGENTA%^Are you trying to get out of here?");
   force_me("say %^BOLD%^%^MAGENTA%^I think the gnoll is looking for you.");
   force_me("emote glances about.");
   force_me("say %^BOLD%^%^MAGENTA%^You have to kill him to get out of this place or get your stuff.");
   call_out("ask_2",7);
   return;
}

void ask_2(){
   force_me("say %^BOLD%^%^MAGENTA%^Also...he has the key to free us. Will you bring me the key so I can free the slaves here?");
   force_me("emote looks at you pleadingly.");
   step1 = 1;
   return;
}

void ask_3(){
   force_me("emote puts the key into the lock and begins to fiddle with it.");
   call_out("ask_4",5);
   return;
}

void ask_4(){
object *ppl;
    int i;
    string queststring;
force_me("emote smiles as he begins to opens the cages.");
force_me("say %^BOLD%^%^MAGENTA%^I have nothing to give you. You have my thanks, however,"+
" and perhaps in town there will be rewards for our return.");
force_me("emote finishes releasing everyone and turns and smiles brightly.");
force_me("say %^BOLD%^%^MAGENTA%^I will lead them back to safety. Thank you. Thank you so much.");
force_me("emote gathers the other prisoners and escorts them away.");
if(!userp(TP))  return;
    queststring = "%^BOLD%^%^CYAN%^Freed the Slaves%^RESET%^";
      fighterz = ({});
      fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      ppl = ({});
      for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,1000,queststring);
          tell_object(fighterz[i],"\n%^BOLD%^%^GREEN%^You freed the slaves from captivity!%^RESET%^\n");
        }
      }
    }
      TO->move("/d/shadowgate/void");
      TO->remove();
      }

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
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
      strsrch(msg,"Yes") != -1) && step1 == 1) {
      force_me("say %^BOLD%^%^MAGENTA%^Good. Take what you can use, and do your best.");
      force_me("emote sighs as she looks to the south.");
      force_me("say %^BOLD%^%^MAGENTA%^He has killed many. Please, let the gods follow you.");
      step1 = 0;
      step2 = 1;
	  return;
  }
//adding this since it did not make sense for her to reply the same way when people agreed or refused
//~Circe~ 7/24/19 This area could still use work.
   if((strsrch(msg,"No") != -1 || strsrch(msg,"no") !=-1) && step1 == 1) {
      force_me("emote looks like she might cry as she cringes away and goes back to sweeping.");
      force_me("emote whispers something that is barely audible.");
      force_me("say %^BOLD%^%^MAGENTA%^He has killed many ... so many.");
      step1 = 0;
      step2 = 1;
	  return;
  }
}

void receive_given_item(object obj){
   object reward;
   if(!objectp(obj)) return;
   if(!objectp(TP)) return;
   if((string)obj->query_name() == "gnollkey") {
      obj->remove();
      force_me("emote 's eyes go wide as you pull out the key and give it to her.");
      force_me("say I cannot believe you did it!");
      force_me("emote runs over to the cages.");
      call_out("ask_3",5);
   }
}
