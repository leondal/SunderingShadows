#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                     "west" : TABAXROOM + "jungle50",
                "northeast" : TABAXROOM + "jungle21",
                     "east" : TABAXROOM + "jungle54",
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
