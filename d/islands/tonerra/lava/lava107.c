
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([

 "east":LAVA+"lava108",
 "north":LAVA+"lava207",
    "west":LAVA+"lava106",
  ]));
}
