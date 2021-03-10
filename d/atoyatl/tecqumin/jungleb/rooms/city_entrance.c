#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_MAZE;

string long_desc();

inherit J_MAZE;

void create() {
  ::create();
  add_item( ({"road", "ancient road", "remains of road", "remains of ancient road"}),
    "The ancient road has been largely overgrown by the jungle. Only patches of"
   +" stone remain, green with moss and crossed over with tree roots. Even so, what"
   +" is left suggests that long ago this may have been a major causeway." );
  base_exits = ([ "east" : CITY_ROOM + "ragged_road01" ]);
  set_basic_exits();
  r_path = JUNG_ROOM2;
}

void on_enter(){
  set_basic_exits();
  update_exits();
}

string short_desc(){
  load_ghosts();
  return ::short_desc();
}



void load_ghosts(){
  int i, count;
  object room;
  string * rooms;
  rooms = ({CITY_ROOM + "hut01", CITY_ROOM + "hut02", CITY_ROOM + "grand_hut01", 
            CITY_ROOM + "grand_hut02", CITY_ROOM + "ruin01", CITY_ROOM + "ruin02", 
            CITY_ROOM + "ruin03", CITY_ROOM + "ruin04", CITY_ROOM + "grand_ruin01",
            CITY_ROOM + "grand_ruin02", CITY_ROOM + "grand_ruin03", 
            CITY_ROOM + "grand_interior02"}); 
  count = sizeof(rooms);
  for (i=0;i<count;i++){
    room = find_object_or_load(rooms[i]);
  }
}

long_desc(){
  load_ghosts();
   return ::long_desc()+ "To the east, the jungle opens slightly, and you can make out what looks like the remains of an %^RESET%^ancient road%^GREEN%^ heading further in the same direction.";
}


