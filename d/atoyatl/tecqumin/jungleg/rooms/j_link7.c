#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "west": JUNG_ROOM8 + "j_link7a" ]);
  set_basic_exits();
  r_path = JUNG_ROOM7;
}
int is_map_transition(){
  return 1;
}


void on_enter(){
  set_basic_exits();
  update_exits();
}
