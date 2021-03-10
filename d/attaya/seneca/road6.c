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
This is the corner where the North Road and the East Road
meet, continuing around the edge of the city of Seneca. 
Made from cobblestone, the stone surface of the street has 
stood up to a lot of wear. A large building is on the corner, 
the entrance appears to be to the west.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "west" : "/d/attaya/seneca/road5",
      "south" : "/d/attaya/seneca/road7",
   ]) );
}
