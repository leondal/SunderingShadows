
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
    "southwest":LAVA+"lava58",
    "east":LAVA+"lava61",
    "north":LAVA+"lava56",
  ]));
}
