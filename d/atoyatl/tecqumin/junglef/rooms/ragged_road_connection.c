#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM6;
  base_exits = ([ "west": CITY_ROOM + "city_jung18" ]);
  set_basic_exits();
}
int is_map_transition(){
  return 1;
}


void on_enter(){
  set_basic_exits();
  update_exits();
//  load_ghosts();
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


string long_desc(){
 // load_ghosts();
  return ::long_desc();
}

string short_desc(){
//  load_ghosts();
  return ::short_desc();
}
