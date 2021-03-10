#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
      "northeast" : TABAXROOM + "jungle25",
          "south" : TABAXROOM + "jungle23"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
