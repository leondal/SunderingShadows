#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM3;
  e_room = "j_link3";
  s_room = "j_link2a";  
  spec_rooms = ({ "snake_room", "tower" });
}
