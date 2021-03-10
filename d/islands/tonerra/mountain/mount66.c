#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/d/islands/tonerra/mountain.c";

void create(){
   ::create();
   set_short("Side of the volcano");
   set_long(
@DESC
%^CYAN%^You are on a path leading toward a large building. You can
just make out the stone construction of the building from here.
There are few plants in the area, although the volcano has been
dormant long enough to allow some small bushes to grow.
DESC
   );
   set_light(2);
   set_indoors(0);
   set_listen("default","The slight breeze stirs the small plants.");
   set_smell("default","The land has a charred smell about it.");
   set_exits(([
      "west":MOUNTAIN+"mount65",
      "east":MOUNTAIN+"mount67"
   ]));
}
