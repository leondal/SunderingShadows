#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("State road on the marketplace");
  set_long(
  "State road on the marketplace.\n"
    "  State road here becomes Torm's marketplace to the east."
  "  It runs south and north while all around you the shoppers and buyers jostle about."
    "  A low stone building to the west is accessed by a flight of short, wide stairs and a slight hint of steam escapes the open door."
  );
  set("night long",
  "%^BLUE%^"
    "Torm's now empty marketplace stretches out to the east, fading"+
  " into the fog.  State road continues north and south, while a low"+
  " stone building to the west can be accessed by a wide set of stairs."
  );
  set_exits(([
  "north":TCITY+"c43",
  "east":TCITY+"c55",
  "south":TCITY+"c62",
  "stairs":TCITY+"c112",
  ]));
   add_item("stairs","These grand marble stairs lead up to a large building on the west, it appears to be a bathhouse.");
   add_item("building","The large building on the west is quite ornate. You can see steam escaping from it in places, so it is probably Torm's bathhouse.");
}
