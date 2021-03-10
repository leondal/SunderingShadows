#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "southwest" : TABAXROOM + "jungle22",
                     "east" : TABAXROOM + "jungle39"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
