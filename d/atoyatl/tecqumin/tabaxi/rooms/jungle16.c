#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
               "south" : TABAXROOM + "jungle01",
               "north" : TABAXROOM  + "jungle04"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
