#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM2;
  n_room = "j_link2";
  s_room = "j_link1a";
  e_room = "city_entrance";  
  spec_rooms = ({ "jung_waterfall"});
}
