// destinations_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke, based on code plundered from Ares
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <clock.h>
#include <daemons.h>

#define SAVE_FILE "/daemon/save/mob_kill_records" 
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "mob_kill_records_log"

/* Coded by Lujke
This daemon is for recording and querying timings of players killing specified mobs, or completing named events. Information is saved across reboots. See function descriptions below for use instructions.

*/

inherit DAEMON;

  mapping __mob_killers;
  mapping __events;
  int create_time;
varargs int completed_event(string actor, string event, int time_passed); 
//True if player named has completed event named within time specified. 
//Defaults to 7 days if no time specified.

varargs object has_anyone_here_completed(object where, string event, int time_passed);
//Checks all players in the room 'where', to see if any of them has completed the event
//within the specified time frame. Returns the first player that it finds who has

varargs object has_anyone_here_killed(object where, string victim, int time_passed);
//Checks all players in the room 'where', to see if any of them has killed the victim 
//within the specified time frame. Returns the first player that it finds who hasog


varargs int has_killed(string killer, string victim, int time_passed); 
//True if player named has killed mob with this file name within time 
//specified. Defaults to 7 days if no time specified.

varargs int party_completed_event(string actor_name, string event, int time_passed); 
//True if player named or anyone in their party has completed event 
//named within time specified. Defaults to 7 days if no time specified.

varargs int party_has_killed(string slayer, string victim, int time_passed);  
//True if player named or anyone in their partyhas killed mob with this file 
//name within time specified. Defaults to 7 days if no time specified.

mapping query_all_mob_killers(); 
// returns entire mapping of recorded mob kills & timings

int query_event_time(string who, string whichevent); 
//returns time recorded for player named completing event named

mapping query_event_times(string event); 
//returns entire mapping of recorded event com pletions & timings

int query_mob_kill_time(string who, string whichmob); 
//returns time recorded for player named killing mob with this file name

mapping query_mob_killers(string whichmob); 
//returns mapping of all players recorded as killing mob with this file
// name & timings of kills

varargs void record_event(string actor, string event, int time_of_event); 
//adds a record of player named completing event named. Defaults to 
//current time if no time passed

varargs void record_kill(string killer, string mob, int time_of_death);
//adds a record of player named killing mob with this file name. Defaults
//to current time if no time passed

void remove_event(string event, string actor); //removes record of player named completing event named
void remove_event_record(string event); //removes all records of anyone completing event named
void remove_kill_record(string mob, string killer); //removes record of player named killing mob with this file name
void remove_mob_record(string mob); //removes all records of anyone killing mob with this file name
void SAVE();

void clean_up() { 
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return; 
} 



varargs int completed_event(string actor, string event, int time_passed){ //defaults to 7 days
  mapping __actors;
  string * actor_names, * events;
  int when;
  if (sizeof(__events)<1){
    return -1;
  }
  events = keys(__events);
  if (member_array(event, events)== -1){
    return -1;
  }
  __actors = __events[event];
  if (sizeof(__actors)<1){
    return -1;
  }
  actor_names = keys(__actors);
  if (member_array(actor, actor_names)==-1){
    return -1;
  }
  when = __actors[actor];
  if (!time_passed){
    time_passed = DAY * 7;
  }
  if (when + time_passed > time()){
    return 1;
  }  
  return -1;
}


void create(){
  ::create();
  __mob_killers = ([]);
  __events = ([]);
  create_time = time();
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE,1);
  seteuid(getuid());
}

varargs object has_anyone_here_completed(object where, string event, int time_passed){
  object * critters;
  string nm;
  int i, count;
  if (!objectp(where)){ return 0;}
  critters = all_living(where);
  count = sizeof(critters);
  if (count<1){ return 0;}
  for (i=0;i<count;i++){
    if (!interactive(critters[i]) || critters[i]->query_true_invis()){
      continue;
    }
    nm = critters[i]->query_name();
    if (time_passed >0){
      if (completed_event(nm, event, time_passed) >0){
        return critters[i];
      } 
    } else {
      if (completed_event(nm, event) >0){
        return critters[i];
      } 
    }
  }
}

varargs object has_anyone_here_killed(object where, string victim, int time_passed){
  object * critters, room;
  int i, count;
  string nm;
  if (!objectp(where)){
    return 0;
  }
  critters = all_living(where);
  count = sizeof(critters);
  if (count<1){ 
    return 0;
  }
  for (i=0;i<count;i++){
    if (!interactive(critters[i]) || critters[i]->query_true_invis()){
      continue;
    }
    nm = critters[i]->query_name();
    if (time_passed > 0){
      if (has_killed(nm, victim, time_passed)>0){
        return critters[i];
      } 
    } else {
      if (has_killed(nm, victim)>0){
        return critters[i];
      } 
    }
  }
}

varargs int has_killed(string killer, string victim, int time_passed){ //defaults to 7 days
  mapping killers;
  string * slayers, * mobs;
  int when;
  if (sizeof(__mob_killers)<1){
    return -1;
  }
  mobs = keys(__mob_killers);
  if (member_array(victim, mobs)== -1){
    return -1;
  }
  killers = __mob_killers[victim];
  if (sizeof(killers)<1){
    return -1;
  }
  slayers = keys(killers);
  if (member_array(killer, slayers)==-1){
    return -1;
  }
  when = killers[killer];
  if (!time_passed){
    time_passed = DAY * 7;
  }
  if (when + time_passed > time()){
    return 1;
  }  
  return -1;
}

varargs int party_completed_event(string actor_name, string event, int time_passed){ //defaults to 7 days
  object * party, actor;
  string party_name;
  int i, count, flag;
  actor = find_player(actor_name);
  if (!objectp(actor)){
    return -1;
  }
  if (!time_passed){
    time_passed = 7 * DAY;
  }
  party_name = PARTY_D->party_member(actor);
  if (!stringp(party_name)){
    return completed_event(actor_name, event, time_passed);
  }
  party = PARTY_D->query_party_members(party_name); 
  flag = -1;
  count = sizeof(party);
  if (count<1){
    return completed_event(actor_name, event, time_passed);
  }
  for (i=0;i<count;i++){
    if (!objectp(party[i]) || !party[i]->is_player()){
      continue;
    }
    if (completed_event(party[i]->query_name(),event, time_passed)){
      flag = 1;
      break;
    }
  }
  return flag;
}

varargs int party_has_killed(string slayer, string victim, int time_passed){ //defaults to 7 days
  object * party, killer;
  string party_name;
  int i, count, flag;
  killer = find_player(slayer);
  if (!objectp(killer)){
    return -1;
  }
  if (!time_passed){
    time_passed = 7 * DAY;
  }
  party_name = PARTY_D->party_member(killer);
  if (!stringp(party_name)){
    return has_killed(slayer, victim, time_passed);
  }
  party = PARTY_D->query_party_members(party_name); 
  flag = -1;
  count = sizeof(party);
  if (count<1){
    return has_killed(slayer, victim, time_passed);
  }
  for (i=0;i<count;i++){
    if (!objectp(party[i]) || !party[i]->is_player()){
      continue;
    }
    if (has_killed(party[i]->query_name(),victim, time_passed)){
      flag = 1;
      break;
    }
  }
  return flag;
}
mapping query_all_events(){
  if (sizeof(__events)<1){
    return ([]);
  }
  return __events;
}

mapping query_all_mob_killers(){
  if (sizeof(__mob_killers)<1){
    return ([]);
  }
  return __mob_killers;
}

int query_event_time(string who, string whichevent){
  string * events, * actors;
  mapping __actors;
  events = keys(__events);
  if (member_array(whichevent, events)==-1){
    return -1;
  }
  __actors = __events[whichevent];
  actors = keys(__actors);
  if (member_array(who, actors)==-1){
    return -1;
  }
  return __actors[who];
}

mapping query_event_times(string event){
  mapping resultmap;
  string * events;
  if (sizeof(__events)<1){
    return ([]);
  }
  events = keys(__events);
  if (member_array(event, events)==-1){
    return ([]);
  }
  resultmap = __events[event];
  return resultmap;
}

int query_mob_kill_time(string who, string whichmob){
  string * mobs, * slayers;
  mapping __killers;
  mobs = keys(__mob_killers);
  if (member_array(whichmob, mobs)==-1){
    return -1;
  }
  __killers = __mob_killers[whichmob];
  slayers = keys(__killers);
  if (member_array(who, slayers)==-1){
    return -1;
  }
  return __killers[who];
}

mapping query_mob_killers(string whichmob){
  mapping resultmap;
  string * victims;
  if (sizeof(__mob_killers)<1){
    return ([]);
  }
  victims = keys(__mob_killers);
  if (member_array(whichmob, victims)==-1){
    return ([]);
  }
  resultmap = __mob_killers[whichmob];
  return resultmap;
}

varargs void record_event(string actor, string event, int time_of_event){
  mapping map;
  if (!time_of_event){
    time_of_event = time();
  }
  map = ([actor : time_of_event]);
  __events[event] = map;
  SAVE();
}

varargs void record_kill(string killer, string mob, int time_of_death){
  mapping map;
  if (!time_of_death){
    time_of_death = time();
  }
  map = ([killer : time_of_death]);
  __mob_killers[mob] = map;
  SAVE();
}

void remove_event(string event, string actor){
  string * events, * actor_names;
  mapping __action_times;
  if (sizeof(__events)<1){
    return;
  }
  events = keys(__events);
  if (member_array(event, events)== -1){
    return;
  }
  __action_times = __events[event];
  if (sizeof(__action_times)<1){
    return;
  }
  actor_names = keys(__action_times);
  if (member_array(actor, actor_names)==-1){
    return;
  }
  m_delete(__action_times, actor);
  __events[event] = __action_times;
  SAVE();
}

void remove_event_record(string event){
  string * events;
  if (sizeof(__events)<1){
    return;
  }
  events = keys(__events);
  if (member_array(event, events)== -1){
    return;
  }
  m_delete(__events, event);
  SAVE();
}

void remove_kill_record(string mob, string killer){
  string * mobs, * slayers;
  mapping __killers;
  if (sizeof(__mob_killers)<1){
    return;
  }
  mobs = keys(__mob_killers);
  if (member_array(mob, mobs)== -1){
    return;
  }
  __killers = __mob_killers[mob];
  if (sizeof(__killers)<1){
    return;
  }
  slayers = keys(__killers);
  if (member_array(killer, slayers)==-1){
    return;
  }
  m_delete(__killers, killer);
  __mob_killers[mob] = __killers;
  SAVE();
}

void remove_mob_record(string mob){
  string * mobs;
  if (sizeof(__mob_killers)<1){
    return;
  }
  mobs = keys(__mob_killers);
  if (member_array(mob, mobs)== -1){
    return;
  }
  m_delete(__mob_killers, mob);
  SAVE();
}

void SAVE(){
	seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
	seteuid(getuid());
}






