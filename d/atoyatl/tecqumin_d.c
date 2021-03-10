// destinations_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke, based on code plundered from Ares
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>

#define SAVE_FILE "/daemon/save/tecqumin" 
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "tecqumin_log"

/* Coded by Lujke
   This daemon is for working with variables needed by various things
  in the Tecqumin area.
*/

inherit DAEMON;

  mapping __empress_killers;
  mapping __jontar_killers;
  mapping __taluc_killers;
  mapping __quali_killers;
  int create_time;

void SAVE();
int empress_kill_time(string who);
int jontar_kill_time(string who);
int taluc_kill_time(string who);
int quali_kill_time(string who);
void kill_empress(string who);
void kill_jontar(string who);
void kill_taluc(string who);
void kill_quali(string who);


void create(){
  ::create();
  __empress_killers = ([]);
  __jontar_killers = ([]);
  __taluc_killers = ([]);
  __quali_killers = ([]);
  create_time = time();
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE,1);
  seteuid(getuid());
}

void clean_up() { 
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return; 
} 

mapping query_empress_killers(){
  if (sizeof(__empress_killers)<1){
    return ([]);
  }
  return __empress_killers;
}
mapping query_jontar_killers(){
  if (sizeof(__jontar_killers)<1){
    return ([]);
  }
  return __jontar_killers;
}
mapping query_taluc_killers(){
  if (sizeof(__taluc_killers)<1){
    return ([]);
  }
  return __taluc_killers;
}
mapping query_quali_killers(){
  if (sizeof(__quali_killers)<1){
    return ([]);
  }
  return __quali_killers;
}

int empress_kill_time(string who){
  string * killers;
  if (sizeof(__empress_killers)<1){
    return 0;
  }
  killers = keys(__empress_killers);
  if (member_array(who, killers)==-1){
    return 0;
  }
  return __empress_killers[who];
}

int jontar_kill_time(string who){ 
  string * killers;
  if (sizeof(__jontar_killers)<1){
    return 0;
  }
  killers = keys(__jontar_killers);
  if (member_array(who, killers)==-1){
    return 0;
  }
  return __jontar_killers[who];
}
int taluc_kill_time(string who){
  string * killers;
  if (sizeof(__taluc_killers)<1){
    return 0;
  }
  killers = keys(__taluc_killers);
  if (member_array(who, killers)==-1){
    return 0;
  }
  return __taluc_killers[who];
}

int quali_kill_time(string who){ 
  string * killers;
  if (sizeof(__quali_killers)<1){
    return 0;
  }
  killers = keys(__quali_killers);
  if (member_array(who, killers)==-1){
    return 0;
  }
  return __quali_killers[who];
}

void kill_empress(string who){ 
  __empress_killers[who] = time();
}

void kill_jontar(string who){ 
  __jontar_killers[who] = time();
}

void kill_taluc(string who){ 
  __taluc_killers[who] = time();
}

void kill_quali(string who){ 
  __quali_killers[who] = time();
}
