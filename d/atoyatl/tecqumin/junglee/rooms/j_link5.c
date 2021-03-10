#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "south": JUNG_ROOM6 + "j_link5a"]);
  set_basic_exits();
  r_path = JUNG_ROOM5;
}
int is_map_transition(){
  return 1;
}


void on_enter(){
  set_basic_exits();
  update_exits();
}
