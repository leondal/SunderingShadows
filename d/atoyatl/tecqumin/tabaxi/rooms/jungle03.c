#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ "southwest" : TABAXROOM + "jungle02",
                "west": TABAXROOM + "low_field",
                "north" :    TABAXROOM  + "jungle06",
                "east" : TABAXROOM + "jungle10"
             ]) );
  set_pre_exit_functions( ({"west" }), ({"go_west"}) );
}

int go_west(){
  object room;
  room = find_object_or_load(TABAXROOM + "low_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}

void init(){
  ::init();
  set_had_players(3);
}
