#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("State road");
  set_long(
  "State road.\n"
  "  State road continues north and south towards the center of Torm."
    "  A side road leads west here and to the east is the wall around Torm's central park."
   "  You can hear the noise of the marketplace to the south. Just west of here on the south side is a building with the sign of a mage's shop on it."
  );
  set("night long",
  "%^BLUE%^"
  "  State road is covered in a light fog.  The wall around Torm's park"+
  " to the east extends above the fog, giving you a better idea of"+
  " where you are."
  );
   add_item("building","The building to the west and south here has the sign of a mage's shop.");
  set_exits(([
  "north":TCITY+"c13",
  "south":TCITY+"c34",
  "west":TCITY+"c23",
  ]));
}
