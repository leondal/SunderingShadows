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
This is the corner where the East Road and the South Road
meet, continuing around the edge of the city of Seneca. 
Made from cobblestone, the stone surface of the street has 
stood up to a lot of wear. The outside of a huge %^CYAN%^Coliseum%^RESET%^ 
is on the corner.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "north" : "/d/attaya/seneca/road13",
      "west" : "/d/attaya/seneca/road15",
   ]) );
}
