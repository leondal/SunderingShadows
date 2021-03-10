#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create(){
  ::create();
  set_short("A dark passageway");
  set_long(
@VETRI
%^BLUE%^You find yourself in some sort of underground passageway.  The rough stone
walls are damp and cold.  As you look behind you, you notice the shattered 
mirror through which you came to this place, but you are not able to return
through it.  You begin to search for another way out.
VETRI
  );
  set_indoors(1);
  set_light(1);
  set_listen("default","You hear your own footsteps echoing.");
  set_exits(([
    "east":TEMPLE+"pass12",
    "west":TEMPLE+"pass11"
  ]));
}
