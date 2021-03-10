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
of wear. The center of the city is to the west. Yards leading to
the %^CYAN%^Pawn Shop%^RESET%^ and the %^CYAN%^Questing Hall%^RESET%^ are to the north and south.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "east" : "/d/attaya/seneca/street6",
      "south":"/d/attaya/seneca/questyard",
      "west" : "/d/attaya/seneca/square",
      "north" : "/d/attaya/seneca/pawnyard",
   ]) );
}
