#include <std.h>
#include "../tormdefs.h"
inherit whatever;

void create()  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Road in northwest Torm");
  set_long(
  "Road in northeast Torm.\n"
   "  West Tanar road leads north and south here flanked to the west by the residences of Torm whose backs lay against the city's outer wall, and a walled compound to the east."
  );
  set("night long",
  "%^BLUE%^"
  "The entire city seems to be covered in a light fog that has settled"+
  " over the streets, slightly obscuring your vision."
  "   A walled compound rises out of the fog to the east, and the road"+
  " continues to the north and south here."
  );
  set_exits(([
  "north":TCITY+"c2",
  "south":TCITY+"c22",
  ]));
}
