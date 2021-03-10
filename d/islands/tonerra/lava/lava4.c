#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
    "northeast":LAVA+"lava60",
    "south":LAVA+"lava3",
    "north":LAVA+"lava5",
  ]));
}
