#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM4;
  n_room = "tabaxi_exit";
  e_room = "j_link4";
  s_room = "city_jung14"; 
  w_room = "j_link3a"; 
  spec_rooms = ({ "jag_lair_entry" });
}
