#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
   set_exits( ([    "north" : TABAXROOM + "main_field" ,
	          "northeast" : TABAXROOM + "low_field",
                 "northwest": TABAXROOM + "high_field",
                     "east" : TABAXROOM + "jungle02",
                     "west" : TABAXROOM + "jungle04",
                    "south" : TABAXROOM + "jungle15"
           ]) );
  set_pre_exit_functions( ({"northwest" }), ({"go_northwest"}) );
  set_pre_exit_functions( ({"north" }), ({"go_north"}) );
  set_pre_exit_functions( ({"northeast" }), ({"go_northeast"}) );
}

int go_northeast(){
  object room;
  room = find_object_or_load(TABAXROOM + "low_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}

int go_north(){
  object room;
  room = find_object_or_load(TABAXROOM + "main_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}

int go_northwest(){
  object room;
  room = find_object_or_load(TABAXROOM + "high_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}

string long_desc(){
  return ::long_desc() + "%^RESET%^To the north, the jungle opens out on three large,"
                      +" %^GREEN%^terraced fields%^RESET%^. Beyond the fields, you can see a"
                      +" %^ORANGE%^sturdy wooden stockade%^RESET%^.\n";
}

void init(){
  ::init();
  set_had_players(3);
}
