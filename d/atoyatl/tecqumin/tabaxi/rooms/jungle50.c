#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                     "east" : TABAXROOM + "jungle51",
                "northwest" : TABAXROOM + "jungle49"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
