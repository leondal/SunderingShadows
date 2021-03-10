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
You are just south of the gates into Seneca. Here on this 
street you can see where Intruder and his army broke through 
the gates, but was too weak to make it deeper into the city.  
To the east and west the North Road leads around the edge of
the city.
DESC
   );
   set_items( ([
      "buildings" : "Demolished in attack, the rubble lies strewn before you.",
   ]) );
   set_exits( ([
      "north" : "/d/attaya/seneca/boardwalk3",
      "south" : "/d/attaya/seneca/street2",
      "east" : "/d/attaya/seneca/road1",
      "west" : "/d/attaya/seneca/road39"
   ]) );
}
