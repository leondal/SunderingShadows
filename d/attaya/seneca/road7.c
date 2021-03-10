#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("East Road in Seneca");
   set_long(
@DESC
This is the East Road that leads around the edge of the 
city of Seneca. Made from cobblestone, the stone surface 
of the street has stood up to a lot of wear. The outside
of a large building is on the corner.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "north" : "/d/attaya/seneca/road6",
      "south" : "/d/attaya/seneca/road8",
   ]) );
}
