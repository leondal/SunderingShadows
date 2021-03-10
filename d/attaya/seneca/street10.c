#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_property("light", 2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Street in Seneca");
   set_long(
@DESC
This street leads from the east-west crossroad to the road that
circles the city. Made from cobblestone, the stone surface has 
stood up to a lot of wear. There are buildings on either side
of the street, but no entrances. To the south, the street passes 
a few more buildings and yards. 
DESC
   );
   set_items(([
      "cobblestones" : "These are cobblestones.",
      "buildings" : "There is an L-shaped building to the west and a large stone building to the east."
   ]) );
   set_exits( ([
      "south" : "/d/attaya/seneca/street11",
      "north" : "/d/attaya/seneca/street9"
   ]) );
}
