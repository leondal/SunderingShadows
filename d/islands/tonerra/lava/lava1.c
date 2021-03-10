#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
    //"up":LAVA+"lava1",
    "north":LAVA+"lava2",
    "east":LAVA+"lava100",
    "west":LAVA+"lava112"
  ]));
}
