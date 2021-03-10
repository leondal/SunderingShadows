#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
    "north":LAVA+"lava33",
    "southwest":LAVA+"lava37",
    "east":LAVA+"lava44",
  ]));
}
