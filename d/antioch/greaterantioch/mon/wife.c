#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob, *fighterz;
int step1;
int step2;
int step3;

create() {
   ::create();
   set("aggressive",0);
   set_name("yolandria");
   set_level(10);
   set_gender("female");
   set_alignment(1);
   set_languages( ({ "common"}) );
   command("speak common");
   command("pose laying on a bed, upset");
   set_property("swarm",0);
   set_id( ({"human","wife"}) );
   set_short("Yolandria, %^RESET%^A %^BOLD%^%^MAGENTA%^beautiful %^RESET%^%^ORANGE%^auburn-haired %^RESET%^human woman with %^BOLD%^%^GREEN%^green %^RESET%^eyes");
   set_long("%^RESET%^This exotic looking woman is obviously from lands far to the south."+
            " She wears a simple %^RESET%^%^RED%^Tharisian %^RESET%^outfit, with an exposed"+
            " mid-section. Her hair has been tied into many simple braids, topped at the ends with"+
            " %^BOLD%^%^YELLOW%^col%^BOLD%^%^WHITE%^o%^BOLD%^%^RED%^rf%^BOLD%^%^YELLOW%^ul %^RESET%^beads."+
            " She is laying on the bed, trembling. Obviously shaken up, perhaps you"+
            " could %^BOLD%^%^YELLOW%^calm %^RESET%^her?");
   set_race("human");
   set_hd(5,10);
   add_money("gold",random(10));
   set_body_type("human");
   set_size( 2 );
   set_property("no attack", 1);
   set_hp(24);
   set_max_hp(24);
   set_exp(5);
   step1=1;
}
init()
{
  ::init();
  add_action("calm","calm");
}

int calm(string str){
if ((str=="yolandria") || (str=="human") || (str=="wife") || (str=="woman")){
if (step3 == 1){return 1;}
else;{
  tell_object(ETO,"%^BOLD%^%^WHITE%^The woman seems to calm noticeably. She looks down at the body, narrowing her"+
              " eyes slightly.");
  call_out("calm_1",5);
  step3=1;
  return 1;
}}}

void calm_1(){
force_me("emote %^RESET%^pulls up some of the clothing that had been pulled away, covering herself up.");
force_me("say %^BOLD%^%^CYAN%^Thank you...");
call_out("calm_2",4);
}

void calm_2(){
force_me("emote %^RESET%^looks down, obviously saddened.");
force_me("say %^BOLD%^%^CYAN%^Thank you for saving me. Di..did...my husband survive?");
}

void ignore_3(){
force_me("emote climbs off of the bed and straightens herself up.");
force_me("say %^BOLD%^%^CYAN%^You are so very brave, you know that don't you?");
call_out("calm_4",5);
}

void calm_4(){
    object *ppl;
    int i;
    string queststring;
force_me("say %^BOLD%^%^CYAN%^Be well, and thank you...again.");
force_me("emote walks out of the room with a almost gleeful stride, given the situation.");
      queststring = "%^BOLD%^%^CYAN%^Rescued the Missing Wife%^RESET%^";
    ppl = ({});
    fighterz = ({});
    fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
    for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,75000,queststring);
          tell_object(fighterz[i],"\n%^BOLD%^%^CYAN%^You rescued the wife!%^RESET%^\n");
      TO->move("/d/shadowgate/void");
      TO->remove();
}}}}

void calm_5(){
object *ppl;
    int i;
    string queststring;
force_me("emote climbs out of the bed.");
force_me("say %^BOLD%^%^CYAN%^Please come visit me...in the future...I will find a suitable reward.");
force_me("emote walks out of the room, obviously sad.");
    queststring = "%^BOLD%^%^CYAN%^Rescued the Missing Wife%^RESET%^";
    ppl = ({});
    fighterz = ({});
    fighterz += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
    for(i=0;i<sizeof(fighterz);i++) {
      if(interactive(fighterz[i])) {
        ppl += ({ fighterz[i] });
        if(member_array(queststring,fighterz[i]->query_mini_quests()) == -1) {
          fighterz[i]->set_mini_quest(queststring,75000,queststring);
          tell_object(fighterz[i],"\n%^BOLD%^%^CYAN%^You rescued the wife!%^RESET%^\n");
      TO->move("/d/shadowgate/void");
      TO->remove();
}}}}

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
   strsrch(msg,"No") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"yeah") !=-1) && step1 == 1) {
      force_me("say %^BOLD%^%^CYAN%^Oh..thanks the gods.");
      force_me("emote smiles slightly, obviously relieved by the news.");
      force_me("say %^BOLD%^%^CYAN%^I will go to him then. He is likely at our home in the hamlet to the west. Perhaps"+
               " you will come see us again in the future? I am sure we can find a suitable award for your efforts.");
      call_out("ignore_3",10);
      step1 = 0;
      step2 = 1;
	  return;
  }
     if((strsrch(msg,"no") != -1 || strsrch(msg,"Nope") != -1 ||
   strsrch(msg,"nah") != -1 || strsrch(msg,"No") != -1 ||
   strsrch(msg,"never") != -1 || strsrch(msg,"Never") != -1 || strsrch(msg,"no") !=-1) && step1 == 1) {
      force_me("say %^BOLD%^%^CYAN%^Are...you...sure?");
      force_me("emote nods slowly, breathing in.");
      force_me("say %^BOLD%^%^CYAN%^I suppose I will go now.");
      force_me("emote begins to slowly gather herself up.");
      call_out("calm_5",10);
      step1 = 0;
      step2 = 0;
	  return;
}
}
