#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "north" : TABAXROOM + "jungle44",
                "southeast" : TABAXROOM + "jungle46"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
