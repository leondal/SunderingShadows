#include <std.h>
#include "../tormdefs.h"

inherit whatever;

void create() {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Dock road");
  set_long( "Dock road.\n"
    "  Dock road continues north and south towards the center of Torm."
    "  To the east is new stonework enclosing what was once an alley and empty lot."
    "  To the west is the wall around Torm's central park."
    "  Straight south of here is the eastern edge of the city market."
  );
  set("night long",
  "%^BLUE%^Dock road is covered in a light fog.  The wall around Torm's park"+
  " to the west extends above the fog, giving you a better idea of"+
  " where you are."
  );
  set_exits(([
  "north":TCITY+"c14",
//  "east":TCITY+"c26",  room east converted to Girruuth's place
  "south":TCITY+"c35",
  ]));
}
