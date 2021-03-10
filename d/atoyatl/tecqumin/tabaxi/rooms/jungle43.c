#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([     "north" : TABAXROOM + "jungle42",
                "southeast" : TABAXROOM + "jungle52",
                     "west" : TABAXROOM + "jungle44"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
