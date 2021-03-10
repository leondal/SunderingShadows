#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northwest" : TABAXROOM + "jungle32",
                "southwest" : TABAXROOM + "jungle39",
                "northeast" : TABAXROOM + "jungle23"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
