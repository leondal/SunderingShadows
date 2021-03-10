#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM1 + "j_maze";
  n_room = JUNG_ROOM + "j_link1.c";
  s_room = JUNG_ROOM + "j_link8a.c";  
}
