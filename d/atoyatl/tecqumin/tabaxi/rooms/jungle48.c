#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                     "east" : TABAXROOM + "jungle49",
                    "north" : TABAXROOM + "jungle47"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
