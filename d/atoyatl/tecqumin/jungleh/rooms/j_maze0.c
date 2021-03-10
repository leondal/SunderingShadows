#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM8;
  w_room = "j_link8";
  e_room = "j_link7a";  
  spec_rooms = ({ "tun_entry" });
}
