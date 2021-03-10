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
Here in the city, closer to the south side, the buildings 
are complete, having so far been spared in the attacks on 
the city. To the east is the local %^CYAN%^Pawn Shop%^RESET%^, and to the 
west is a %^CYAN%^Clothing Shop%^RESET%^.
DESC
   );
   set_items( ([
      "buildings" : "You can see where the buildings have been destroyed and rebuilt.",
   ]) );
   set_exits( ([
      "north" : "/d/attaya/seneca/street2",
      "south" : "/d/attaya/seneca/square",
      "west" : "/d/attaya/seneca/clothyard",
      "east" : "/d/attaya/seneca/pawnyard",
   ]) );
}
