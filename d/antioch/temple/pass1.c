#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create(){
  ::create();
  set_short("A dark passageway");
  set_long(
@VETRI
%^BLUE%^You find yourself in some sort of underground passageway.  The rough stone
walls are damp and cold.  As you continue your search for another way out, 
you keep wondering what could be down here that it was so well hidden.
VETRI
  );
  set_indoors(1);
  set_light(1);
  set_listen("default","You hear your own footsteps echoing.");
  set_exits(([
    "south":TEMPLE+"pass2",
    "northeast":TEMPLE+"pass12",
    "northwest":TEMPLE+"pass11"
  ]));
}
