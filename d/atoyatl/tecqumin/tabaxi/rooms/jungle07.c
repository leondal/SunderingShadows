#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                     "northwest" : TABAXROOM + "jungle23",
                     "east" : TABAXROOM + "stock_wall3",
                    "south" : TABAXROOM + "jungle05",
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
