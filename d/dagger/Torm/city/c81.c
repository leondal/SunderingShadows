#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("South Tanar by the gates of Torm");
  set_long(
  "South Tanar by the gates of Torm.\n"
  "  Tanar road continues its path along the walls of Torm here east and west, while a main road heads north towards the center of the city."
  "  Thin, weak looking bronze gates are open to the south leading out of the city."
    "  All around you the citizens of Torm go about their business with mingled visitors from all the lands of Shadow."
  );
  set("night long",
  "%^BLUE%^"
    "Torm's gates lie closed to the south, you can see them clearly"+
   " despite the light fog that has settled over all of the city.  Tanar"+
   " continues east and west while a main road leads north to the center"+
  " of Torm."
  );
  set_exits(([
  "north":TCITY+"c75",
  "east":TCITY+"c82",
  "south":TCITY+"c89",
  "west":TCITY+"c80",
  ]));
}
