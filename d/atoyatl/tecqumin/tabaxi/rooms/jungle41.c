#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northeast" : TABAXROOM + "jungle35",
                     "west" : TABAXROOM + "jungle42",
                "southeast" : TABAXROOM + "jungle36"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
