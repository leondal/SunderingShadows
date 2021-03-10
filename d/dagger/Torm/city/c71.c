#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Road in southwest Torm");
  set_long(
  "Road in southwest Torm.\n"
    "  West Tanar road leads north and south here flanked to the west by the residences of Torm whose back lay against the city's outer wall, and a walled compound to the east."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog covers the streets here obscuring the ground from view"+
  " and making it difficult to tell what lies on the roads north and"+
  " south.  A walled compound rises above the fog to the east."
  );
  set_exits(([
  "north":TCITY+"c59",
  "south":TCITY+"c77",
  ]));
}
