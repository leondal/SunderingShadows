#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ "west" : TABAXROOM + "entry",
                "northeast" : TABAXROOM + "jungle03",
                    "south" : TABAXROOM + "jungle14"
             ]) );
}
void init(){
  ::init();
  set_had_players(3);
}
