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
    "  Main street continues east and west here north of Torm's great marketplace."
  "  The marketplace vibrates with life and you can hear many languages and see visitors from all corners of the lands."
    "  A wall to the north surrounds Torm's central park although a gate to it lies open to the west."
   "  You notice a large fountain to the southwest."
  );
  set("night long",
  "%^BLUE%^"
    "Torm's great empty marketplace stretches out east and south of you,"+
   " fading into the fog.  At dawn this place will be packed with"+
   " people and traders from all over the lands once more, but now it"+
   " is quiet."
  );
   set_items(([
   "wall" : "There is a wall to the north here that surrounds Torm's park. It is an odd green color and is apparently seamless.",
   ]));
  set_exits(([
  "east":TCITY+"c47",
  "south":TCITY+"c57",
  "west":TCITY+"c45",
  ]));
}
