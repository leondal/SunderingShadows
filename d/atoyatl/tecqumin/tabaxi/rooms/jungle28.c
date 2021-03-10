#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "south" : TABAXROOM + "jungle29",
                "southwest" : TABAXROOM + "jungle11"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
