#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("North Road in Seneca");
   set_long(
@DESC
This is the corner where the West Road and the North Road
meet, continuing around the edge of the city of Seneca. 
Made from cobblestone, the stone surface of the street has 
stood up to a lot of wear. An empty stretch of land runs
along the road to the south.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "south" : "/d/attaya/seneca/road33",
      "east" : "/d/attaya/seneca/road35",
   ]) );
}
