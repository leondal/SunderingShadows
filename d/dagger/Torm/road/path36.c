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
  "  The low green walls of Torm rise to your east blocking the view of the ocean and all but the tallest spires of the city."
  "  As you look north and south of the city you see the road bordered by low cliffs surmounted by the start of forests that move inland and a golden beach to the west."
  "  The west gates of Torm lay to the south on this road."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
  "spires":"Great spires rise above a few grand buildings in the city.",
      ]));

    set_exits(([
  "northeast":ROAD+"path37",
  "south":ROAD+"path35",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salt sea air mixes with the smells of many types of cooking.");
}
