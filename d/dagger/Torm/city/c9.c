#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("Street in northeast Torm");
  set_long(
  "Street in northeast Torm.\n"
    "  A walled compound fills your view to the south here."
      "  The houses of Torm line the wall to the north, their backs to the city wall, while Tanar road runs east and west."
  );
  set("night long",
  "%^BLUE%^"
  "A walled compound rises above the fog to the south of here."
  "  Tanar road runs east and west here and all the houses that line the city wall to the north are shuttered and locked against the cold night air."
  );
  set_exits(([
  "east":TCITY+"c10",
  "west":TCITY+"c8",
  ]));
}
