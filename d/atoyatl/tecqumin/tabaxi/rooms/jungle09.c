#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                     "south" : TABAXROOM + "jungle10",
                     "northwest" : TABAXROOM + "jungle08",
                    "northeast" : TABAXROOM + "jungle30"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
