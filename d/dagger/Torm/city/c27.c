#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("Outside Torm's general store");
  set_door("door",TCITY+"c28","west","masterkey");
  set_long(
    "Outside Torm's general store.\n"
  "  This section of town seems a little seedier than what you're used to from this city."
    "  You feel a little safer when you see a town guardsman walk by who gets only moderately evil glares from the local ruffians."
   "  Torm's general store door lies open to the west and Tanar road goes southwest and east from here."
   "  To the east you see another structure on the north side with a mug of ale and something else on the sign."
   );
  set("night long",
  "%^BLUE%^"
    "Torm's general store door lies closed and barred against the night"+
    " to the west.  The building is strange, with bars on its windows."+
    " You're not sure you'd want to go in there even if it was open,"+
    " unless you really, really needed something.  To the east you"+
    " can see a building that appears to be open, with the sounds of"+
    " drunken laughter spilling out from it."
  );
   add_item("building","To the west is a large stone building that serves as Torm's general store. It doesn't look too inviting or friendly.");
  set_exits(([
  "north":TCITY+"c16",
  "east":TCITY+"c29",
/*  "southwest":TCITY+"c36",  didn't make sense mapped - Styx 12/26/01 */
  "west":TCITY+"c28",
  ]));
}
