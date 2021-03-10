#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit J_MAZE;

void create() {
  r_path = JUNG_ROOM4;
  ::create();
  base_exits = ([
      "southeast" : CITY_ROOM + "city_jung13",
      "southwest" : CITY_ROOM + "city_jung15"
   ]);
  set_basic_exits();


  add_item( ({"palace", "", "palatial structure", "large building"}), 
    "You can't see much from here, but the building is made of stone, and is"
   +" impressively large in scale.");


}
int is_map_transition(){
  return 1;
}


void on_enter(){
  set_basic_exits();
  update_exits();
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

string short_desc(){
  set_basic_exits();
  update_exits();
  load_ghosts();
  return ::short_desc();
}

string long_desc(){
  set_basic_exits();
  update_exits();
  load_ghosts();
  return ::base_desc() + " Generally to the south, you can make out the top"
  +" of a %^RESET%^palatial structure%^GREEN%^, peeking out above the tops of"
  +" the trees";
}
