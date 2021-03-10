#include <std.h>
#include "../tormdefs.h"
inherit whatever;

void create()  {
  ::create();
  set_terrain(CITY);
  set_travel(PAVED_ROAD);
  set_short("Dock road and Tanar");
  set_long( "Dock road and Tanar.\n"
  "  Dock road to the north becomes Tanar as it follows the outside of the city back down to the docks."
  "  Tanar continues south towards the docks and the marketplace and east toward a large ampitheatre."
   "  Straight south of here is the eastern edge of the city market."
  );
  set("night long",
    "%^BLUE%^Dock road meets Tanar here as Tanar road goes south to the docks."
    "  Fog hangs in the air here, mostly settling along the ground and"+
    " making it a little difficult to find your way and footing.  You can make out "
    " the walls of the park blocking your way to the west."
  );
  set_exits(([
  "north":TCITY+"c25",
  "east":TCITY+"c36",
  "south":TCITY+"c47",
  ]));
}
