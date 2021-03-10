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
This is the North Road that leads around the edge of the 
city of Seneca. Made from cobblestone, the stone surface 
of the street has stood up to a lot of wear. The yard 
outside the %^CYAN%^Bank%^RESET%^ is to the south.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "east" : "/d/attaya/seneca/street1",
      "west" : "/d/attaya/seneca/road38",
      "south" : "/d/attaya/seneca/bankyard"
   ]) );
}
