#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northwest" : TABAXROOM + "jungle36",
                "southwest" : TABAXROOM + "jungle38",
                "southeast" : TABAXROOM + "jungle39"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
