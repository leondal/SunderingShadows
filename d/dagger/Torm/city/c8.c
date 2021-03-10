#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_long(
  "In the city of Torm.\n"
    "  North Tanar road meets here with Dock road which leads south towards Torm's docks."
   "  Tanar continues east and west here following the outer wall of the city."
  "  A set of stairs leads up to a watchtower on the green walls."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city, clinging to the ground and"+
  " obscuring your view.  The road here leads east and west while"+
  " another road starts leading south into the gloom.  A set of stairs"+
  " rise up above the fog, leading to a watchtower."
  );
  set_exits(([
  "up":TCITY+"c8a",
  "east":TCITY+"c9",
  "south":TCITY+"c14",
  "west":TCITY+"c7",
  ]));
}
