#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ "southeast" : TABAXROOM + "jungle04",
                    "north" : TABAXROOM + "jungle07",
                     "east" : TABAXROOM + "high_field",
             ]) );
  set_pre_exit_functions( ({"east" }), ({"go_east"}) );
}

int go_east(){
  object room;
  room = find_object_or_load(TABAXROOM + "high_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}

void init(){
  ::init();
  set_had_players(3);
}
