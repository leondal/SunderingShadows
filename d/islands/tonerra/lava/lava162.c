
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  
  
  
  set_exits(([
  "northwest":LAVA+"lava163",
  "east":LAVA+"lava161",
  ]));
}
