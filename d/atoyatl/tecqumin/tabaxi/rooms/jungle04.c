#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ "northwest" : TABAXROOM + "jungle05",
                "southwest" : TABAXROOM + "jungle17",
                "south"     : TABAXROOM + "jungle16",
                "east"      : TABAXROOM + "entry"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
