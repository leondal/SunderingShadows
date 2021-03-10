#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northwest" : TABAXROOM + "jungle37",
                     "west" : TABAXROOM + "jungle40",
                "northeast" : TABAXROOM + "jungle31"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
