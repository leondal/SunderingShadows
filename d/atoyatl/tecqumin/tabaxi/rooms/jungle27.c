#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "southwest" : TABAXROOM + "treetop_base3",
                    "south" : TABAXROOM + "treetop_base2",
                "southeast" : TABAXROOM + "treetop_base1",
                     "west" : TABAXROOM + "jungle26"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
