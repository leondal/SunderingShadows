#include <std.h>
inherit MONSTER;
string commandee;
int countdown;
void catch_say(string msg);
void command_func(string command, object speaker, object who);
void set_commandee(string str);
string query_commandee();
void obey_command(string name, string command);

void create(){
  ::create();
  set_name("");
      set_property("not random monster", 1);
  set_id(({"followmob"}));
  set_short(("followmob"));
  set_long((""));
  set_gender("neuter");
  set_race("followmob");
  set_heart_beat(1);
  set_no_clean(1);
  set_property("no animate",1);
  set_true_invis();
  set_property("no detect", 1);
  countdown = 500;
  set_property("eavesdropping", 1);
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int do_damage(string str, int i){
    return 0;
}

void set_commandee(string str){
  commandee = str;
}

string query_commandee(){
  return commandee;
}

void heart_beat(){
  object *players, own, env;
  int i, count;
  if (!stringp(commandee)) {return;}
//  ::heart_beat();
  if (!objectp(ETO)){ return;}
//  tell_room(ETO, "Table's heart beats");
  if (!present(commandee, ETO)){
    players = children("/std/user.c");
    count = sizeof(players);
    if (count <1) {return;}
    for (i=0;i<count;i++){
      if ((string)players[i]->query_name() == commandee){
        own = players[i];
        break;
      }
    }
    if (objectp(own)){
      env = environment(own);
      if (objectp(env)){
        tell_room(ETO, "The many-legged table spins around and then"
          +" rushes off, seemingly in search of something");
        tell_room(env, "A many-legged stone table trips into the room and"
          +" walks happily over to stand by " + own->QCN, own);
        tell_object(own, "A many-legged stone table trips into the room and"
          +" walks happily over to stand next to you.");
        move(env);
        own->add_follower(TO);
      }
    } else {
      countdown --;  //The mob will wait if the player's not 
      if (countdown <1){remove();} //around, but not forever
    } 
  }
}

void init(){
  ::init();
  add_action("instruct_func", "instruct");
}

int instruct_func(string str){
  string name, command;
  int count;
  str = strip_colors(str);
  count = sscanf(str, " %s to %s", name, command);
  if (count <2){
    return notify_fail("Try 'instruct <name> to <do something>'");
  }
  obey_command(name, command); 
  TP->force_me("whisper " + name + " " + command); 
}

void catch_say(string msg){
  string name, command;
  int count;
  msg = strip_colors(msg);
  count = sscanf(msg, " %s %s", name, command);
  obey_command(name, command);
}

void obey_command(string name, string command){
  object * critters, who;
  int i, count;
  if (!objectp(ETO)){return;}
  if (!stringp(name)){return;}
  if (!stringp(command)){return;}
  if (count <1) {return;}
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count <1) {return;}
  for (i = 0;i<count;i++){
    if (!interactive(critters[i])|| critters[i]==TP){
      continue; 
    }
    if (TP->isKnown(critters[i]->query_name())){ 
      if ((string)TP->knownAs(critters[i]->query_name())==name){
        who = critters[i];
        break;
      }
    }
  } 
  if (!objectp(who)){ 
    return;
  }
  tell_object(TP, who->QCN + " appears inclined to do as you"
    +" say. You could also <instruct> them, if you don't want"
    +" to say every command out loud");
  call_out("command_func",1,command,TP,who);
}

void command_func(string command, object speaker, object who){
  string name;
  if (!objectp(who)){ return;}
  if (!objectp(speaker)) {return;}
  if (!speaker->isKnown(speaker->query_name())){
    name = speaker->query_short();
  } else {
    name = speaker->knownAs(who->query_name());
  }
  who->remove_paralyzed();
  tell_object(who, "As " + name + "speaks, You feel compelled try to follow "
   + name + "'s will.");  
  who->force_me(command);
  who->set_paralyzed(500, "You feel listless and unmotivated");
}
