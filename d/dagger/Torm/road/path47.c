#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit ROOM;

void create() {
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
  set_short("Outcropping on the Dagger Sea");
    set_long(
  "%^CYAN%^"
  "  The low green walls of Torm rise to the south, where they go right upto and into the waters of the Dagger Sea."
  "  A rocky outcropping juts from the golden beaches here to continue this path out onto the sea itself."
  "  A small building can be seen far out on the outcropping."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
  "spires":"Great spires rise above a few grand buildings in the city.",
      ]));

    set_exits(([
  "southeast":ROAD+"path48",
  "west":ROAD+"path46",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salt sea air mixes with the smells of many types of cooking.");
}
