#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("North State road");
  set_long(
  "North State road.\n"
  "  State road is flanked on both sides by walled compounds here."
    "  A grand mansion to the west and Torm's park to the east."
    "  You can see Torm's north wall just north of you here while the sounds of the market lie to the south."
  );
  set("night long",
  "%^BLUE%^"
  "Fog has settled lightly over this section of the road.  You can see"+
  " Torm's park to the east and a grand mansion to the west."+
  "  The roads north and south lead further into the fog."
  );
  set_exits(([
  "north":TCITY+"c4",
  "south":TCITY+"c24",
  ]));
}
