#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
               "north" : TABAXROOM + "entry",
           "southwest" : TABAXROOM  + "jungle01"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
