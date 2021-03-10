#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit ROOM;

void create() {
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
  set_short("Beside the walls of Torm");
    set_long(
  "%^CYAN%^"
    "  The low green walls of Torm run north and east here blocking the view of the city but leaving the great expanse of the Dagger Sea open for you."
  "  A great golden beach starts almost from the south of the walls which come right to the edge of the sea."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
  "spires":"Great spires rise above a few grand buildings in the city.",
  "sea":"The great dagger sea stretches off to the horizon.   A few ships lay anchored off the city waiting to dock.",
      ]));

    set_exits(([
  "northwest":ROAD+"path19",
  "northeast":ROAD+"path21",
  "southeast":ROAD+"path32",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salt sea air mixes with the smells of many types of cooking.");
}
