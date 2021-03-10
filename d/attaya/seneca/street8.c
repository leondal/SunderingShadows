#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("Street in Seneca");
   set_long(
@DESC
This is the crossroad through Seneca, travelling east and west.  
Made from cobblestone, the stone surface has stood up to a lot 
of wear. The yard of a house is to the west. A street heading 
south leads past another yard and several large buildings. The
center of town is to the east.
DESC
   );
   set_items(([
      "cobblestones" : "These are cobblestones.",
      "buildings" : "There is an L-shaped building to the southwest and a few other buildings along the road."
   ]) );
   set_exits( ([
      "east" : "/d/attaya/seneca/street7",
      "west" : "/d/attaya/seneca/thiefyard",
      "south" : "/d/attaya/seneca/street9"
   ]) );
}
