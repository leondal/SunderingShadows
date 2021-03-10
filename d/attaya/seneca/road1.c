#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_property("light", 2);
   set_short("North Road in Seneca");
   set_long(
@DESC
This is the North Road that leads around the edge of the 
city of Seneca. Made from cobblestone, the stone surface 
of the street has stood up to a lot of wear. The street 
leading to the center of the city is just to the west, 
and the yard in front of the %^CYAN%^Seneca Hospital%^RESET%^ is to the 
south. 
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "south" : "/d/attaya/seneca/healyard",
      "west" : "/d/attaya/seneca/street1",
      "east" : "/d/attaya/seneca/road2"
   ]) );
}
