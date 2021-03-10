#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "south" : TABAXROOM + "jungle43",
                     "east" : TABAXROOM + "jungle41"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
