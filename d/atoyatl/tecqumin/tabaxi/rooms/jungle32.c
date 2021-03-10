#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "north" : TABAXROOM + "jungle33",
                "southeast" : TABAXROOM + "jungle31"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
