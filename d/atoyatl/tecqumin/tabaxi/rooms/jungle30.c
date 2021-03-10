#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northwest" : TABAXROOM + "jungle29",
                "southwest" : TABAXROOM + "jungle09"
             ]) );
      set_monsters(({MOB +"tabaxi"}), ({random(2) + 1})); 
      set_repop(50);
}

void init(){
  ::init();
  set_had_players(3);
}
