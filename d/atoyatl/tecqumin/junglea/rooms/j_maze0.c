#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM1;
  n_room = "j_link1";
  e_room = "j_link8a"; 
  spec_rooms = ({ "jung_waterhole" });
}
