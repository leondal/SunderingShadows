#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
           "west" : TABAXROOM + "orog_entry",
      "southeast" : TABAXROOM + "jungle21",
      "northeast" : TABAXROOM + "jungle40",
          "north" : TABAXROOM + "jungle38"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
