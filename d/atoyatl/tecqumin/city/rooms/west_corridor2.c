#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CORRIDORBASE;


void create() {
  ::create();

  set_exits(([
     "north" : CITY_ROOM + "west_corridor1",
     "south" : CITY_ROOM + "west_tower"
   ]));
  set_door("tower door", CITY_ROOM + "west_tower", "south", 0);
  set_door_description("tower door", "A simple, but functional"
    +" and very strong looking wooden door");
}


