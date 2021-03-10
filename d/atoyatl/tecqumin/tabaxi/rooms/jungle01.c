#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ "north" : TABAXROOM + "jungle16",
            "northeast" : TABAXROOM + "jungle15",
                "south" : JUNG_ROOM4 + "tabaxi_exit"
             ]) );
  set_pre_exit_functions( ({"north" }), ({"go_north"}) );
}

int go_north(){
  object room;
  room = find_object_or_load(TABAXROOM + "main_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}

void init(){
  ::init();
  set_had_players(3);
}
