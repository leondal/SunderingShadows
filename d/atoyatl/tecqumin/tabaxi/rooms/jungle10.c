#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "north" : TABAXROOM + "jungle09",
                "west" : TABAXROOM + "jungle03",
                    "south" : TABAXROOM + "jungle12"
             ]) );
      set_monsters(({MOB +"tabaxi"}), ({random(2) + 1})); 
      set_repop(50);
}

void init(){
  ::init();
  set_had_players(3);
}
