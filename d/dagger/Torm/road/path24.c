#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit ROOM;

void create() {
    ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
  set_short("South of Torm");
    set_long(
  "%^CYAN%^"
    "  Torm's low green walls are north of you running west and east into the Dagger Sea itself."
  "  The ground here is dusted with golden sand but is still solid enough for the small huts you see on the edge of the sea."
  "  Small fishing ships in the water attest to the inhabitants of these huts profession."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
  "spires":"Great spires rise above a few grand buildings in the city.",
  "sea":"The great dagger sea stretches off to the horizon.   A few ships lay anchored off the city waiting to dock.",
  ({"huts","hut"}):"This small hut is on the edge of the sea with a small fishing boat just off shore behind it.",
      ]));

    set_exits(([
  "northwest":ROAD+"path23",
  "hut":ROAD+"path25",
  "southwest":ROAD+"path26",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salt sea air mixes with the smells of many types of cooking.");
}
