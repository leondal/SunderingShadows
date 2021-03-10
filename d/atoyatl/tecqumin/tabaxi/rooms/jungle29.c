#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "north" : TABAXROOM + "jungle28",
                "southeast" : TABAXROOM + "jungle30"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
