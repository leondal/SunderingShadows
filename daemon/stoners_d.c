//NOT ACTIVELY USED

// destinations_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke, based on code plundered from Ares
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>
#define SAVE_FILE "/daemon/save/stoners" 
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "stoners_log"


inherit DAEMON;

  string * _stoners;

  int add_stoner(string stoner);
  int am_i_stoned(string stoner);
  string * query_stoners();
  int remove_stoner(string stoner);
  void SAVE();


void create(){
  ::create();
  _stoners = ({});
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

string * query_stoners(){
  return _stoners;
}

int add_stoner(string stoner){
  if (member_array(stoner, _stoners) == -1){
    _stoners += ({});
    return 1;
  }
  return 0;
}

int remove_stoner(string stoner){
  if (member_array(stoner, _stoners) != -1){
    _stoners -= ({stoner});
    return 1;
  }
  return 0;
}

int am_i_stoned(string stoner){
  if (member_array(stoner, _stoners) != -1){
    return 1;
  }
  return 0;
}
