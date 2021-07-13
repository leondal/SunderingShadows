#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob, *fighterz;
int step1;
int step2;
int step3;
int step4;

create() {
   ::create();
   set("aggressive",0);
   set_name("revis");
   set_level(10);
   set_alignment(1);
   set_languages( ({ "common","elven" }) );
   command("speak common");
   command("pose laying near a pile of burnt wood");
   set_property("swarm",0);
   set_id( ({"human","man","revis"}) );
   set_short("%^RESET%^A %^BOLD%^%^BLACK%^dark-haired %^RESET%^human with %^BOLD%^%^BLUE%^"+
			 "blue%^RESET%^ eyes and %^RESET%^%^ORANGE%^brown %^RESET%^hair");
   set_long("%^RESET%^This very simple looking man is wearing clothes that seem more fit for a man from"+
		" down south. The man is covered with blood from obviously many %^RESET%^%^RED%^wounds %^RESET%^and seems to be barely clining"+
        " on to life. He seems to be grasping a locket in his hand, trembling violently and mumbling"+
        " about losing his %^BOLD%^%^YELLOW%^wife %^RESET%^, you can %^BOLD%^%^RED%^ignore"+
        " %^RESET%^or you could %^BOLD%^%^YELLOW%^aid %^RESET%^him?");
   set_race("human");
   set_emotes(3,({
		"The wounded man cringes in pain, trembling a moment.",
		"The wounded man rocks back and forth, mumbling quietly.",
		"The wounded man rubs at his hair, his hand trembling.",
  }),0);set_hd(20,10);
   add_money("gold",random(100));
   set_body_type("human");
   set_size( 2 );
   set_property("no attack", 1);
   set_hp(24);
   set_max_hp(243);
   set_exp(400);
}
init()
{
  ::init();
  add_action("aid","aid");
  add_action("ignore","ignore");
}

int ignore(string str){
if ((str=="revis") || (str=="human")){
if (step3 == 1){return 1;}
if (step4 == 1){return 1;}
else;{
  tell_object(ETO,"%^BOLD%^%^WHITE%^The pleading man nods slowly, obviously understanding"+
              " what is about to happen. He looks down an obviously defeated look on crosses"+
              " his features.");
  call_out("ignore_1",5);
  step4 = 1;
  return 1;
}
}
}
int aid(string str){
if ((str=="revis") || (str=="human")){
if (step4 == 1){return 1;}
if (step3 == 1){return 1;}
else;{
  tell_object(ETO,"%^BOLD%^%^WHITE%^You lean over and pour some %^BOLD%^%^YELLOW%^healing vial %^BOLD%^%^WHITE%^into his mouth.%^RESET%^");
  tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" holds the man's head and pours a potion into his mouth.%^RESET%^",ETO);
  call_out("heal_1",1);
  step3 = 1;
  return 1;
}
}
}

void ignore_1(){
force_me("emote runs a %^RESET%^%^RED%^bloody %^RESET%^hand through his hair.");
force_me("say %^BOLD%^%^CYAN%^Please, don't...don't leave...");
call_out("ignore_2",4);
}

void ignore_2(){
force_me("emote leans his head back against the caravan and stares into the sky.");
force_me("say %^BOLD%^%^CYAN%^Jarmila...why...why must it end now?");
call_out("ignore_3",10);
}

void ignore_3(){
force_me("emote lowers head now, staring at the ground, growing very weak.");
force_me("say %^BOLD%^%^CYAN%^Please...someone...someone needs to save her...");
call_out("ignore_4",5);
}

void ignore_4(){
force_me("say %^BOLD%^%^CYAN%^I love her...she is all I ever wanted...all...");
force_me("emote coughs violently, %^BOLD%^%^RED%^blood %^RESET%^dripping from the corner of his mouth.");
call_out("ignore_5",5);
}

void ignore_5(){
force_me("say %^BOLD%^%^CYAN%^What..what are they doing...to her...in the hills...?");
force_me("emote wheezes now..coughing again.");
call_out("ignore_6",5);
}

void ignore_6(){
force_me("emote pales completely now, his weigh slumping and his head falling limp against his shoulder.");
force_me("emote begins to move his lips as if he wants to say something, then his head arches up violently as he shouts...");
force_me("yell %^BOLD%^%^MAGENTA%^Yolandria! I ... LOVE YOU!");
force_me("emote slumps his head down with his last words as he starts shuddering.");
call_out("ignore_7",5);
}

void ignore_7(){
    object *ppl;
    int i;
    string queststring;
    string queststring2;
    force_me("emote shudders violently then stops abruptly, slumping over onto his side.");
    queststring = "%^BOLD%^%^CYAN%^Let Revis Die%^RESET%^";
      fighterz = ({});
      fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      ppl = ({});
      for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring2,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,1000,queststring);
          fighterz[i]->set_mini_quest(queststring2,1000,queststring2);
          tell_object(fighterz[i],"\n%^BOLD%^%^RED%^You let the pitiful man meet his maker.%^RESET%^\n");
        }
      }
    }
      TO->die();
      return 1;
}

void heal_1(){
force_me("emote sits there quietly, closing his eyes slowly, still trembling while trying to gain some composure.");
call_out("heal_2",7);
}

void heal_2(){
force_me("emote stands up warily near the wagon, resting himself on it.");
command("pose leaning on a wagon, resting");
force_me("say %^BOLD%^%^CYAN%^Thank Jarmila...well...thank you.");
force_me("emote rubs his hand through his hair, his hand more calm.");
set_hp(117);
call_out("heal_3",9);
}
void heal_3(){
force_me("emote looks around carefully, regaining his composure completely.");
force_me("say %^BOLD%^%^CYAN%^I was alm...no, not important! My wife! She's missing! Please! Can you help me?!");
step1 = 1;
return;
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
    object *ppl;
    int i;
    string queststring;
    string queststring2;

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
   if((strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 ||
   strsrch(msg,"No") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"no") !=-1) && step1 == 1) {
      force_me("say %^BOLD%^%^CYAN%^Thank..Jarmila...again....");
      force_me("emote trembles as he points to the west.");
      force_me("say %^BOLD%^%^CYAN%^The gnolls took her west with much of our things. I can see they didn't care about some of it, as its laying on the ground.");
      force_me("say %^BOLD%^%^CYAN%^Will you follow the scraps and enter their lair?");
      step1 = 0;
      step2 = 1;
	  return;
  }
     if((strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 ||
   strsrch(msg,"No") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"no") !=-1) && step2 == 1) {
      force_me("say %^BOLD%^%^CYAN%^Thank you brave adventurers. I will be waiting at my home in the village.");
      force_me("say %^BOLD%^%^CYAN%^Travel...safely...the creatures are dangerous.");
      force_me("emote begins to slowly gather his things.");
      force_me("emote leaves towards the west with a few of his things, waving to you as he leaves.");
      queststring = "%^BOLD%^%^CYAN%^Saved Revis%^RESET%^";
      fighterz = ({});
      fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      ppl = ({});
      for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,1000,queststring);
          fighterz[i]->set_mini_quest(queststring2,1000,queststring2);
          tell_object(fighterz[i],"\n%^BOLD%^%^CYAN%^You saved the dying man!%^RESET%^\n");
        }
      }
    }
      TO->move("/d/shadowgate/void");
      TO->remove();
      step1 = 0;
      step2 = 0;
	  return;
}
}
