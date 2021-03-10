// treasury_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>
#define SAVE_FILE "/daemon/save/treasury" 
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "treasury_log"


inherit DAEMON;

  int quest_last_done;
  int last_hoard;
  int set_time(int time);
  int query_time();
  void SAVE();


void create(){
  ::create();
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE,1);
    seteuid(getuid());
}

void clean_up() { 
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return; 
} 

void SAVE()
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}

int query_time(){
  return quest_last_done;
}

int set_time(int time){
  quest_last_done = time;
  return 1;
}

int last_hoard(){
  return last_hoard;
}

void set_last_hoard(int time){
  last_hoard = time;
}
