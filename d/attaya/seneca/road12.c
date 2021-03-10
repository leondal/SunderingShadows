#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_property("light", 2);
   set_short("East Road in Seneca");
   set_long(
@DESC
This is the East Road that leads around the edge of the 
city of Seneca. Made from cobblestone, the stone surface 
of the street has stood up to a lot of wear. The outside
of the %^CYAN%^Coliseum%^RESET%^ is on the west side of the road.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "north" : "/d/attaya/seneca/road11",
      "south" : "/d/attaya/seneca/road13",
   ]) );
}
