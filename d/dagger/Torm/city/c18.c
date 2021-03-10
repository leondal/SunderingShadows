#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Tanar road on the edge of the Dagger Sea");
  set_long(
  "Tanar road on the edge of the Dagger Sea.\n"
  "  Tanar road here breaks away from the walls of Torm as they reach out into the sea."
    "  South of here you can see the coast curve back into the east, leaving you a grand view of the docks and boardwalks of Torm over the water."
    "  Tanar continues back east towards the city and northwest to follow the walls again."
  );
  set("night long",
  "%^BLUE%^"
  "  The great dark Dagger Sea looms in front of you as you travel down Tanar road."
  "  The fog makes it difficult to see far out onto the sea and the road continues east and northeast from here."+
   " You can still make out the boardwalks and docks, they all seem"+
   " quiet and empty at night."
  );
  set_exits(([
  "northwest":TCITY+"c17",
  "west":TCITY+"c29",
  ]));
}
