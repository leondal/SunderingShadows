#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Mainstreet on the marketplace");
  set_long(
  "Mainstreet on the marketplace.\n"
    "  Mainstreet continues east and west here north of Torm's great marketplace."
  "  The marketplace vibrates with life and you can hear many languages and see visitors from all corners of the lands."
      "  A wall to the north surrounds Torm's central park and has a gate that stands open to the east."
   "  There is a large fountain to the southeast."
  );
  set("night long",
  "%^BLUE%^"
    "Torm's great empty marketplace stretches out east and south of you,"+
   " fading into the fog.  At dawn this place will be packed with"+
   " people and traders from all over the lands once more, but now it"+
   " is quiet."
  );
  set_exits(([
  "east":TCITY+"c45",
  "west":TCITY+"c43",
  "south":TCITY+"c55",
  ]));
}
