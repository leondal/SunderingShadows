#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northwest" : TABAXROOM + "jungle25",
                    "south" : TABAXROOM + "treetop_base3",
                     "east" : TABAXROOM + "jungle27"
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
