#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northwest" : TABAXROOM + "jungle41",
                "southeast" : TABAXROOM + "jungle37"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
