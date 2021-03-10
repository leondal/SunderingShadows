#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "south" : TABAXROOM + "jungle32",
                "northwest" : TABAXROOM + "jungle34"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
