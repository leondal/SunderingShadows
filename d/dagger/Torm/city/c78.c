#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Street in southwest Torm");
  set_long(
  "Street in southwest Torm.\n"
  "  A walled compound fills your view to the north here."
  "  The houses of Torm line the city wall to the south and the road runs east and west here following them."
  );
  set("night long",
  "%^BLUE%^"
    "A walled compound rises above the fog to the north of you.  The"+
  " road runs east and west here along the city wall to the north."+
  "  All the houses shutters are closed away from the chill night air."
  );
  set_exits(([
  "west":TCITY+"c77",
  "east":TCITY+"c79",
  ]));
}
