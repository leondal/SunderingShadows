#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "northeast": JUNG_ROOM8 + "j_link8", "southeast" : WEMIC + "path14" ]);
  set_basic_exits();
  r_path = JUNG_ROOM1;
}
int is_map_transition(){
  return 1;
}


void on_enter(){
  set_basic_exits();
  update_exits();

}
