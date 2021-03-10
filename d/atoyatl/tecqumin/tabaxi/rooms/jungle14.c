#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "east" : TABAXROOM + "jungle13",
               "north" : TABAXROOM  + "jungle02"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
