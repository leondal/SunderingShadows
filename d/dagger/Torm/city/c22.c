#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("West Tanar");
  set_long(
  "West Tanar.\n"
  "  Tanar continues its path around the city of Torm."
  "  Stairs lead up to a watchtower on the walls and another road goes east from here."
   "  To the south you can see a building with a healer's sign on it. Southeast of here there is another building that has the sign of a mage's shop."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled here along west Tanar road and makes it a"+
  " little hard to see the path ahead.  Stairs lead up out of the fog"+
  " to a watchtower on the top of the walls.  Another street breaks off"+
  " to the east.  Just south of here you can barely make out a building"+
  " that appears to have a healer's sign on it."
  );
   add_item("building","To the south is a building with a healer's shop. East and south there appears to be a building with the sign of a mage's shop.");
  set_exits(([
  "up":TCITY+"c22a",
  "north":TCITY+"c11",
  "south":TCITY+"c32",
  "east":TCITY+"c23",
  ]));
}
