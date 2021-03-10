#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Tanar on the shores of the Dagger Sea");
  set_long(
  "Tanar on the shores of the Dagger Sea.\n"
  "  You stand on the last bit of land as the Dagger Sea comes to Torm."
  "  A boardwalk which serves as a dock on its southside runs out into the sea to the east."
   "  To the west and north Torm's marketplace stretches out with many people of all the lands bustling about to their own business."
   "  Tanar continues north and south along the edge of the harbor."
  );
  set("night long",
  "%^BLUE%^"
    "A boardwalk runs out onto the Dagger Sea that is currently covered"+
   " in a light layer of fog that stretches out to encompass the city."+
    "  The great empty marketplace disappears into the same fog to the west and south."
  "  Everything is quiet and still now, unlike the daytime where the"+
  " streets are alive with vendors and shoppers."
  );
  set_exits(([
  "north":TCITY+"c58",
  "east":TCITY+"c67",
  "west":TCITY+"c65",
  "south":TCITY+"c76",
  ]));
}
