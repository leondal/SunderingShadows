#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("South Road in Seneca");
   set_long(
@DESC
This is the South Road that leads around the edge of the 
city of Seneca. Made from cobblestone, the stone surface 
of the street has stood up to a lot of wear. An empty lot
is on the north side of the road.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "east" : "/d/attaya/seneca/road18",
      "west" : "/d/attaya/seneca/road20",
   ]) );
}
