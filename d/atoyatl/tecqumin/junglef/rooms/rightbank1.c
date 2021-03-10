#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TECBASE + "rightbank_base.c"; 

void create(){
  ::create(); 
  set_enter("northeast");
  set_exit("southeast");
}

string * query_blocked_exits(){
  return ({"northeast", "east", "southeast"});
}

void set_enter(string direction){
  ::set_enter("northeast");
}

void set_exit(string direction){
  ::set_exit ("southeast");
}
