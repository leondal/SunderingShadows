
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
    "west":LAVA+"lava61",
    "south":LAVA+"lava204",
    "east":LAVA+"lava63",
  ]));
}
