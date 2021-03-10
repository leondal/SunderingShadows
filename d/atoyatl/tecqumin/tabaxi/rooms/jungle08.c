#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                     "west" : TABAXROOM + "treetop_base1",
                "southeast" : TABAXROOM + "jungle09"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
