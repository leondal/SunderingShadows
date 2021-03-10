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
  "  The low green walls of Torm rise to the south, leaving the great expanse of the Dagger sea open to you."
    "  A rocky outcropping stretches out north of the city into the sea and from there north runs an amazing golden beach along the edge of the sea till it fades into the distance."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
  "spires":"Great spires rise above a few grand buildings in the city.",
      ]));

    set_exits(([
  "east":ROAD+"path46",
  "northwest":ROAD+"path44",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salt sea air mixes with the smells of many types of cooking.");
}
