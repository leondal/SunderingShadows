//NOT ACTIVELY USED

// destinations_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke, based on code plundered from Ares
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>

#define SAVE_FILE "/daemon/save/gold_records" 
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "gold_records_log"

/* Coded by Lujke
Daemon for keeping track of gold donations for Loki

*/

inherit DAEMON;

int savings;

void create(){
  ::create();
  savings = 0;
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE,1);
  seteuid(getuid());

}

void make_donation(int amount){
  savings += amount;
  SAVE();
}

int query_savings(){
  return savings;
}


int withdraw_money(int amount){
  if (savings < amount){
    return -1;
  }
  savings -= amount;
  SAVE();
  return amount;
}

void SAVE(){
	seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
	seteuid(getuid());
}
