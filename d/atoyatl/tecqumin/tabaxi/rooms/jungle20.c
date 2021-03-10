#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
      "northeast" : TABAXROOM + "jungle19",
          "south" : TABAXROOM + "jungle53",
           "west" : TABAXROOM + "jungle21"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
