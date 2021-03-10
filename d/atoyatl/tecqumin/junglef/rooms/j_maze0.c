#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  r_path = JUNG_ROOM6;
  s_room = "j_link6";
  e_room = "rightbank1";
  n_room = "j_link5a";
  w_room = "ragged_road_connection"; 
  spec_rooms = ({ "bungee_room"});
}
