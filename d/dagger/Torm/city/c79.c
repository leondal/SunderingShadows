#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("South crossing of Tanar and State road");
  set_long(
  "South crossing of Tanar and State road.\n"
  "  South Tanar road meets here with State road which leads north towards the center of Torm."
  "  Tanar continues east and west following the outer wall of the city."
  "  A set of stairs leads up to a guardpost on the walls of the city."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city, clinging to the ground and"+
  " obscuring your view.  The road here leads east and west while"+
  " another road leads to the center of Torm.  A set of stairs rise"+
  " above the fog, leading to a guardpost on the walls of the city."
  );
  set_exits(([
  "up":TCITY+"c79a",
  "north":TCITY+"c72",
  "east":TCITY+"c80",
  "west":TCITY+"c78",
  ]));
}
