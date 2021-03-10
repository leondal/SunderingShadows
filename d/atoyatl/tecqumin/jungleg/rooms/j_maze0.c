#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM7;
  w_room = "j_link7";
  n_room = "j_link6a";  
  e_room = "riverbank";
  spec_rooms = ({ "snake_room" ,
                 "parrot_room", "jung_clearing"});
}
