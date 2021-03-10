#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "north" : TABAXROOM + "jungle10",
            "southwest" : TABAXROOM + "jungle13",
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
