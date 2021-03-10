#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "west" : TABAXROOM + "jungle19",
           "southeast" : TABAXROOM + "jungle17"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
