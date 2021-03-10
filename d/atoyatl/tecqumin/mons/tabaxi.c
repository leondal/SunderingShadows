//Coded by Lujke
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
inherit QNPC;
#define EYECOLOUR ({"%^BOLD%^%^GREEN%^green%^RESET%^",\
                    "%^BOLD%^%^YELLOW%^yellow%^RESET%^"})

int armored, command_time;
nosave int BEAT, heartcount, eyecolour;
string last_command,* commanders;
mapping greeted;
object requester;
string train_desc();
void greet(object who);


void create()
{
      ::create();
      commanders = ({});
  	set_name("tabaxi");
  	set_id(({"tabaxi", "humanoid", "tabaxi peasant", "peasant"}));
  	set_short("tabaxi");
      switch (random(2)){
  	case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
      eyecolour = random(sizeof(EYECOLOUR));
      set_long( (:TO, "long_desc":) );
  	set_race("tabaxi");
  	set_body_type("humanoid");
  	set_size(2);
  	set("aggressive",6);
	set_class("fighter");
	set_mlevel("fighter",45);
	set_guild_level("fighter",45);
   	set_hp(random(500)+200);
	set_max_level(45);
	set_property("swarm",1);
  	set_overall_ac(-55);
  	set_alignment(4);
      set_speed(1);
      set_property("full attacks",1);
      greeted = ([]);
      set_property("no random treasure", 1);
      set_property("not random monster", 1);
      set_new_exp(45, "normal");

      BEAT = 0;
      heartcount = 0;
      check_my_heart();
}

void init(){
  ::init();
  add_action("command_me", "command");
  add_action("agree", "nod");
  greet(TP);
}

void check_my_heart()
{
    if (heartcount>300){
      return;
    }
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}


void set_greeted(object who){
  int when;
  when = time();
  greeted[who] = when; 
}

int set_commander(object commander){
  if (objectp(commander)){
    commanders = commanders + ({commander->query_name()});
    set_speed(0);
    return 1;
  }
  return 0;
}

int query_greet_time(object who){
  return greeted[who];
}

void greet(object who){
  int when, i, j, flag;
  object * critters, crit, * tabaxi, * players;
  string * quests, greeting;
  if (!objectp(who)||!interactive(who)||who->query_true_invis()){
    return;
  }
  quests = who->query_mini_quests();
  when = greeted[who];
  flag = 0;
  if (when >0){
    if (when < time() - 500 && objectp(ETO)){
      flag = 1;
    }
  } else {
    flag  = 1;
  }
  if (flag == 1){
    if (member_array("Agreed to help the Tabaxi", quests)!=-1||
                member_array("Tabaxi Defender", quests)!=-1||
                member_array("Aided the Tabaxi against the Orog attacks", quests)!=-1){
      force_me("say %^ORANGE%^Ello again meester!");
      return;
    }
    call_out("force_me", 1, "say %^ORANGE%^Hey meester! Arre jew one of thee heroes come to save thee veellage?");
    call_out("force_me", 2, "say %^ORANGE%^eef jew are, just go and %^BOLD%^%^RED%^knock%^RESET%^"
                           +"%^ORANGE%^ on thee stockade gate!");
    call_out("force_me", 4, "say %^ORANGE%^Talk too elder Nobacherie in thee stockade"); 
    critters = all_living(ETO);
    players = ({});
    tabaxi = ({});
    for (i=0;i<sizeof(critters);i++){
      crit = critters[i];
      if (objectp(crit)){
        if ((string)crit->query_race() == "tabaxi"){
          tabaxi += ({crit});
        } else{
          if ((int)crit->is_player()>0){
            players += ({crit});
          }
        }
      }
    }
    if (sizeof(players)>0 && sizeof(tabaxi)>0){
      for (i=0;i<sizeof(tabaxi);i++){
        for (j=0;j<sizeof(players);j++){
          tabaxi[i]->set_greeted(players[j]);
        }
      }
    }
  }
}

void heart_beat(){
  string where, battlement;
  int len;
  if (objectp(ETO)){
    where = file_name(ETO);
    battlement = TABAXROOM + "battlement";
    if (where[0..strlen(battlement)-1]==battlement){
      if ((string)ETO->query_ladders()!=""){
        call_out("fend_off", 3+ random(3));
      }
    }
  }
  ::heart_beat();
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
}

void catch_say(string msg){
   if (!interactive(TP)){
     return;
   }
   call_out("reply_func",1,msg,TP);
}

string * query_commanders(){
  return commanders;
}

string main_desc(){
  string desc;
  desc = "%^ORANGE%^This tabaxi peasant's brownish red coat has"
              +" rosetted spots. " + capitalize(QS) + " is tall and"
              +" slender, with eyes"
              +" of "+ EYECOLOUR[eyecolour] +"%^ORANGE%^. "
              + capitalize(QS) + " has quick, stealthy movements, and " 
              + QP +" coat"
              +" pattern provides " + QO + " with natural camouflage.";
  return desc;
}

string long_desc(){
  string desc;
  desc = main_desc();
  if (member_array(TP->query_name(), commanders)!=-1){
  desc +=    "\nThe " + QCN + " will do as you ask. Just %^BOLD%^%^YELLOW%^'command <who> to <do"
                 +" something>'%^RESET%^. " + capitalize(QS) + " will %^BOLD%^%^YELLOW%^<follow>"
                 +" %^RESET%^you, %^BOLD%^%^YELLOW%^<wait> %^RESET%^somewhere or perform a number of"
                 +" other tasks. Experiment and see.\n"
                 + "%^BOLD%^%^RED%^Warning - RP this situation appropriately. The " + QCN + " has"
                 +" agreed to help you on behalf of " + QP +" village. "+ capitalize(QS) + " will only"
                 +" help you to that end. Sanctions will be taken against people who attempt to abuse"
                 +" this trust (e.g. for pk, other quests, etc). If you have any doubts about"
                 +" something you wish to try - please ask an Imm first.";
  desc += train_desc();
  }
  return desc;
}

string train_desc(){
  string desc = "";
  if (ETO == find_object_or_load(TABAXROOM + "training")&& file_name(TO)==MOB + "tabaxi"){
    desc = "\nPerhaps " + QO + " could %^BOLD%^%^YELLOW%^<train> here, to improve " + QP 
           + " fighting skills";
  }
  return desc;
}

void reply_func(string msg, object speaker){
  string what, how, why;
  object env;
  env = ETO;
  if (!objectp(env)||!objectp(speaker)||!present(speaker, env)){
    return;
  }
  if (interact("request", msg) && interact("aid", msg) && (interact("village", msg) 
                                                        || interact ("veellage", msg))){
    if (speaker == requester || member_array(speaker->query_name(), commanders)!=-1){
      return;
    }
    force_me("say Jew wanna ask my elp for dee veellage? Jus' nod eef dat's what jew are askin'"
            +" about");
    requester = speaker;
  }
}

int agree(string str){
  if (TP!=requester){
    return 0;
  }
  call_out("agree2", 1, TP);
  requester = 0;
  return 0;
}

void agree2(object ob){
  if (!objectp(ob)||!objectp(ETO)||!present(ob, ETO)){
    return;
  }
  force_me("emote nods grimly");
  force_me("say Very well, I chall return to de veellage wit jew. Leed on!");
  tell_object(TP, "The " + QCN + " will do as you ask. Just %^BOLD%^%^YELLOW%^'command <who> to <do"
                 +" something>'%^RESET%^. " + capitalize(QS) + " will %^BOLD%^%^YELLOW%^<follow>"
                 +" %^RESET%^you, %^BOLD%^%^YELLOW%^<wait> %^RESET%^somewhere or perform a number of"
                 +" other tasks. Experiment and see.");
  tell_object(TP, "%^BOLD%^%^RED%^Reminder - Please RP this situation appropriately. The " + QCN 
                 +" has agreed to help you on behalf of " + QP +" village. "+ capitalize(QS) 
                 +" will only help you to that end. Sanctions will be taken against people who"
                 +" attempt to abuse this trust (e.g. for pk, other quests, etc). If you have any"
                 +" doubts about something you wish to try - please ask an Imm first.");
  tell_object(TP, "%^RESET%^Note: if you have more than one of the tabaxi under your command in"
                +" the room with you, you can use 'command tabaxi 1', 'command tabaxi 2', etc, to"
                +" distinguish between them. However, 'command tabaxi' without a number will not"
                +" necessarily command the same tabaxi as 'command tabaxi 1'");
  set_speed(0);
  commanders += ({ob->query_name()});
}

varargs int command_me(string str){
  string name, junk, commandee, temp;
  int num, id_num;
  object what;
  num = sscanf(str, "%s to %s", commandee, junk);
  if (num ==2)
  { 
    what = present(commandee, ETO);
    if (what != TO)
    {
      return notify_fail("Who do you want to command to do what?");
    }
  }
  name  = TP->query_name();
  if(member_array(name, commanders)==-1){
    return notify_fail("The tabaxi does not recognise you as a commander");
  }
  call_out("command_me2", 2, str, TP);
  return 1;
}

void command_me2(string str, object obj){
  string where, who, what;
  object env, ob, luj;
  int num;
//  luj = find_player("lujke");
//  if (objectp(luj)){
//    tell_object(luj, "activating command_me, with the string :");
//    tell_object(luj, str);
//  }
  if(sscanf(str, "%s to %s", who, what) <2){
   return notify_fail("Try 'command <who> to <do something>'");
  }
//  if (objectp(luj)){
//    tell_object(luj, "who = " + who + "what = " + what);
//  }
  if (sscanf(who, "%s %d", who, num)>1){
    ob = present(who + " " + num, ETP);
    if (objectp(ob) && ob != TO){
      str = "command " + who + " to " + "what";
      return ob->command_me(str, obj);
//      if (objectp(luj)){
//        tell_object(luj, "re-activating command_me for the " + who + ", with the string '" + str + "'");
//      }
    }
  }
  if (!id(who)){
    return notify_fail("Try 'command <who> to <do something>'");
  }
  if (!objectp(obj)){
    obj = TP;
//    if (objectp(luj)){
//      tell_object(luj, "setting ob to TP, which is" + TP->query_short());
//    }
  }
  if (member_array(obj->query_name(), commanders)==-1 && !avatarp(obj) && !obj->query_true_invis()){
    tell_object(obj, "The " + QCN + " isn't willing to follow your suggestions");
//    if (objectp(luj)){
//      tell_object(luj, "the tabaxi is not willing to follow this person's commands");
//    }
    return 1;
  } 
  env = ETO;
  if (objectp(env)){
    where = env->query_exit(what);
    if (where != "/d/shadowgate/void" && !interact(TABAXROOM, where) 
        && !interact(TEC + "jungle", where)){
      tell_object(TP, QCN + " is unwilling to leave the familiar jungles of " + QP + " homeland", TP);
      return 1;
    }
  }
  if (!interact("orog", what) && (interact("kill ", what) ||interact("shoot ", what) ||interact("rush ", what))){
    tell_object(TP, QCN + " will only fight against the enemies of " + QP + " people, in defence of " 
                + QP + " homelands");
    return 1;
  }
  if (present(TP, ETO)){
    tell_object(TP, "You tell the " + QCN + " to " + what + ".");
    tell_room(env, TPQCN + " gives some instructions to the " + QCN, TP);  
    if (what == "follow"){
      tell_object(TP, "The " + QCN + " will follow you now. Command " + QO + " to%^BOLD%^%^YELLOW%^"
                     +" <wait>%^RESET%^ when you want " + QS + " to stop following");
      TP->add_follower(TO);
      return 1;
    }
    if (what == "wait"){
      if (member_array(TO, TP->query_followers())==-1){
        tell_object(TP, QCN + " is not following you anyway. No need to tell " + QO + " to wait.");
        return 1;
      }
      tell_object(TP, "The " + QCN + " will no longer follow you.");
      TP->remove_follower(TO);
      return 1;
    }
  }
  if (force_me(what)==0){
    tell_object (TP, "Unfortunately, the " + QCN + " doesn't know how to do that");
  }
  return 1;
}

void fend_off(){
  object * wielded;
  int i;
  string what, * ids;
  wielded = query_wielded();
  what = "nothing";
  if (sizeof(wielded)>0){
    for (i=0;i<sizeof(wielded);i++){
      if (wielded[i]->id("pole")||wielded[i]->id("polearm")||wielded[i]->id("staff")){
        ids = wielded[i]->query_id();
        what = ids[0];
        break;
      }
    }
  } else {
    if (present("polearm", TO)){
      force_me("wield polearm");
      what = "polearm";
    }
    if (present("staff", TO)){
      force_me("wield staff");
      what = "staff";
    }
    if (present("pole", TO)){
      force_me("wield pole");
      what = "pole";
    }
  }
  if (sizeof(wielded)<1){
    force_me("push ladder");
  } else{
    if (what != "nothing"){
      force_me("push ladder with " + what);
    }
  }
}

int clean_up(){return 1;}
