#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
        set_short("Crossroads of Main street and State");
  set_long(
      "Crossroads of Main street and State.\n"
      "  Torm's great marketplace stretches out along Main street to the east and continues to the south."
  "  You can see many of the regular citizens and many strange visitors from other lands here selling or looking to buy."
  "  State road runs north and to the south is overrun by the marketplace."
//   "  A grate that leads down into the street is out of the way but noticeable here as well."
  );
  set("night long",
  "%^BLUE%^"
    "Torm's great empty marketplace stretches out east and south of you,"+
   " fading into the fog.  At dawn this place will be packed with"+
   " people and traders from all over the lands once more, but now it"+
   " is quiet."
//   "  A grate that leads down into the street is out of the way but noticeable here as well."
  );
//   add_item("grate","This grate leads down into the sewers under Torm.");
  set_exits(([
//   "down":SEW+"s34",
  "north":TCITY+"c34",
  "east":TCITY+"c44",
  "west":TCITY+"c41",
  "south":TCITY+"c54",
  ]));
//   set_invis_exits(({"down"}));
}
