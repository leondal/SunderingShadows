#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM10;
  n_room = "j_link10a";
  w_room = "leftbank1";
  s_room = "carved_gate";  
}
