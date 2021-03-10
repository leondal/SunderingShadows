#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "south": JUNG_ROOM2 + "j_link2"]);
  set_basic_exits();
  r_path = JUNG_ROOM3;
}
int is_map_transition(){
  return 1;
}



void on_enter(){
  set_basic_exits();
  update_exits();
}
