#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
    "northeast":LAVA+"lava13",
    "northwest":LAVA+"lava200",
    "south":LAVA+"lava11",
  ]));
}
