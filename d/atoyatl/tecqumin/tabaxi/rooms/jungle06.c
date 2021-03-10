#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                    "northwest" : TABAXROOM + "treetop_base1",
                     "south" : TABAXROOM + "jungle03",
                "west" : TABAXROOM + "stock_wall1"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
