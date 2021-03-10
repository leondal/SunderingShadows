#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
           "east" : TABAXROOM + "jungle20",
      "northwest" : TABAXROOM + "jungle22",
      "southwest" : TABAXROOM + "jungle51"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
