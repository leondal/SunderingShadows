#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Mainstreet crossing Tanar road on the shores of the Dagger Sea");
  set_long(
    "Mainstreet crossing Tanar road on the shores of the Dagger Sea.\n"
  "  You stand on the last bit of land as the Dagger Sea comes to Torm."
  "  A boardwalk which serves as a dock on its southside runs out into the sea to the east."
    "  To the west and south Torm's marketplace stretches out with many people of all lands walking around doing business."
    "  Tanar runs north and south following the edge of Torm while Main street goes back west to the center of the city."
//   "  A grate that leads down into the street is out of the way but noticeable here as well."
  );
  set("night long",
  "%^BLUE%^"
  "%^BLUE%^"
    "A boardwalk runs out onto the fog covered Dagger Sea to the east,"+
   " disappearing before you can see its end.  The great empty"+
   " marketplace fades into the fog as well to the west and south."+
   "  Everything is silent and empty, all the citizens safely snoring"+
   " in their beds."
//   "  A grate in the street that leads down seems to be letting the mist pool into it here as well."
  );
//   add_item("grate","This grate leads down into the sewers under Torm.");
  set_exits(([
//   "down":SEW+"s38",
  "north":TCITY+"c35",
  "east":TCITY+"c48",
  "west":TCITY+"c46",
  "south":TCITY+"c58",
  ]));
//   set_invis_exits(({"down"}));
}
