/* Coded by Lujke December 2006
This inheritable is intended to make it easier & quicker for coders (mostly me)to create mobs that respond to players' speech.

To use it, just have your monster inherit this file instead of MONSTER, and include specifications for any responses that you want to have it use in the create() function for your file.
*****************
**  SAMPLE create function: void create(){
**  ::create();
**  set_response(({"goodbye"}),({"Farewell")});// This will simply have the
**                                            // mob say "Farewell" whenever
**                                           // someone says "goodbye"
**
**  set_response(({"hello", "hi"}), ({"and hello to you too", 
**                       "How are you doing today?" }), "greet_func",
**                      ({ "Ruldizar's Request", "Friend of the Stone" }));
**
**  //This second set_response will have the mob say "and hello to you too",
**  //followed by "How are you doing today?", after a short pause. It will 
**  //also set off a call_out for the function greet_func(), which would
**  // need to be defined.
**  //However, because this trigger also has a series of dependencies
**  // specified, the mob would only respond to the "hello" trigger if the 
**  // speaker has completed mini quests or quests going by the names 
**  // "Ruldizar's Request" and "Friend of the Stone"
** }

NB You can only set a dependency using the set_response function if you are also setting a function for that trigger at the same time. If you want to set a dependency, but not a function, leave both out of the set_response, then do a separate call to 
  set_dependency("trigger", ({"dependency1", "dependency2", etc }) )

*/

#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
inherit MONSTER;

mapping responses;
mapping dependencies;
mapping functions;

nosave int BEAT;

int check_dependency(string trigger, object speaker);
int remove_response(string * trigs);
void base_reply_func(string msg, object speaker);

void create(){
  ::create();
  responses = ([]);
  dependencies = ([]);
  functions = ([]);
  set_language("wizish");
  set_spoken("wizish");
  BEAT = 0;
  check_my_heart();
  set_property("no random treasure", 1);
}

void check_my_heart()
{
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


varargs int set_response(string * trig, string * resp, string func,
                                                       string * depend){
  int i;
  string trigger;
  if (sizeof(resp)<1){
    return -1;
  }
  for (i = 0;i<sizeof(trig);i++){
    trigger = trig[i];
    responses[trigger] = resp;
    if (stringp(func)){
      functions[trigger] = func;
    } else { return 1; }
    if (sizeof(depend)>0){
      dependencies[trigger] = depend;
    }
  }
  return 1;
}

int remove_response(string * trigs){
  int i, num;
  string trig, * respkeys, *depkeys, *funkeys;
  num = sizeof(trigs);
  if (num<1){
    return 0;
  }
  respkeys = keys(responses);
  depkeys = keys(dependencies);
  funkeys = keys(functions);
  for (i=0;i<num;i++){
    trig = trigs[i];
    if (member_array(trig, respkeys)!=-1){
      map_delete(responses, trig);
    }   
    if (member_array(trig, depkeys)!=-1){
      map_delete(dependencies, trig);
    }   
    if (member_array(trig, funkeys)!=-1){
      map_delete(functions, trig);
    }   
  }
}

int set_function(string trig, string func){
  functions[trig] = func;
}

int set_dependency(string trigger, string dependency){
  dependencies[trigger] = dependency;
}

string * query_trigs(){
  string * triggers;
  triggers = keys(responses);
  return triggers;
}

string * query_response(string trigger){
  return responses[trigger];
}

mapping query_responses(){
  return responses;
}

mapping query_dependencies(){
  return dependencies;
}

mapping query_functions(){
  return functions;
}

string * query_dependency(string trigger){
  return dependencies[trigger];
}

string query_function(string trigger){
  return functions[trigger];
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

object * party_members_with_quest(object ob, string quest){
  object * party_members, * result;
  string party, * deeds;
  int i, count;
  party = PARTY_D->party_member(ob);
  if (stringp(party)){
    party_members = PARTY_D->query_party_members(party);
  } else {
    party_members = ({ob});
  }
  count = sizeof(party_members);
  if (count<1){
    return ({});
  }
  result = ({});
  for (i=0;i<count;i++){
    deeds = party_members[i]->query_mini_quests();
    if (member_array(quest, deeds)!=-1){
      result += ({party_members[i]});
    }
  }
  return result;
}

respond(string trigger, int count){
  string * response, func;
  func = query_function(trigger);
  response = responses[trigger];
  if (count >=sizeof(response)){
    return;
  }
  force_me("say " + response[count]);
  count ++;
  if (count<sizeof(response)){
    call_out("respond", 2, trigger, count);
  }
}

void die(object ob){
  object * killers;
  int i, count;
  if (objectp(ETO)){
    killers = all_living(ETO);
    count = sizeof(killers);
    if (count>0){
      for (i=0;i<count;i++){
        if (userp(killers[i]) && !killers[i]->query_true_invis()){
          EVENT_RECORDS_D->record_kill(killers[i]->query_name(), base_name(TO), time());
        }
      }
    }
  }
  ::die(ob);
}

void base_reply_func(string msg, object speaker){

  string * triggers, trigger, func, * response, resp, temptrig;
  object room;
  int i;
  if (!interactive(speaker)){
//    force_me("say I'm not talking to someone who's not interactive");
    return;
  }
//  force_me("say I am responding to a piece of speech.");
  room = ETO;
  if (!objectp(ETO)){
    force_me("emote looks disturbed by " + TO->QP + " surroundings, which"
            +" may well be broken");
  }
  msg = strip_colors(msg);
  msg = lower_case(msg);
  if (!objectp(speaker)||!present(speaker, room)){
    return;
  }
  triggers = keys(responses);
  if (sizeof(triggers)<1){ return; }
  for (i=0;i<sizeof(triggers);i++){
    trigger = lower_case(triggers[i]);
//    force_me("say I am looking for the trigger: " + trigger);
    if (interact(trigger, msg)){
//      force_me("say I have recognised the trigger: " + trigger);
      if (check_dependency(trigger, speaker)==-1 ){
//        force_me("say Although I recognised the trigger: " + trigger + ", the speaker is missing a dependency required for me to respond.");
        continue;
      }
      if (stringp(temptrig)&&strlen(temptrig)>strlen(trigger)){
//        force_me("say I have now recognised the trigger: " + trigger + ", but I have already identified: " + temptrig + ", which is longer.");
        continue;  // if more than one of the triggers exists in the 
      }            // message, use the one that's the longest
      temptrig = trigger;
    }
  }
  trigger = temptrig;
  if (!stringp(trigger)){return;}
  func = functions[trigger];
  if (stringp(func)){
    call_out(func, 1, speaker);
  }
  respond(trigger,0);
  return;

}

void reply_func(string msg, object speaker){
  base_reply_func(msg, speaker);
}

int check_dependency(string trigger, object speaker){
  int i;
  string * dep, dependency, * quests;
  dep = dependencies[trigger];
  if (sizeof(dep)<1){
    return 1;
  }
  quests = speaker->query_mini_quests();
  for (i=0;i<sizeof(dep);i++){
    dependency = dep[i];
//    force_me("say I am checking for dependency '" + dependency + "'");
    if (member_array(dependency, quests, 1)==-1){
      force_me("say I have nothing to say to you about '" + trigger + "' for now");
      return -1;
    }
  }
  return 1;
}
