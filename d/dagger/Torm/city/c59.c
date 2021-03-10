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
  "  Tanar road continues north and south while a side road runs east towards the center of Torm."
  "  A set of stairs lead up to a guardtower on the low green walls."
  "  The citizens of Torm wander around with the visitors from the other lands of shadow without much of a care it seems but their own lives."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled around the streets, but it mostly stays"+
  " clear of the houses and shops, and anyone else who happens to be"+
  " out and about at this time of night.  Stairs lead up out of the fog"+
  " leading to a watchtower along the thin green walls of Torm."
  );
  set_exits(([
  "up":TCITY+"c59a",
  "north":TCITY+"c51",
  "east":TCITY+"c61",
  "south":TCITY+"c71",
  ]));
}
