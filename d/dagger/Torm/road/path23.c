#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit ROOM;

void create() {
    ::create();
   set_terrain(BEACH);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("East of Torm's south gates");
    set_long(
  "%^CYAN%^"
  "  The walls of Torm run west and east from here with a gate seen just to the west."
  "  A great golden beach starts almost from the south of the walls which come right to the edge of the sea."
  "  Along this road southeast you can see several small huts on the edge of the sea."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
  "spires":"Great spires rise above a few grand buildings in the city.",
  "sea":"The great dagger sea stretches off to the horizon.   A few ships lay anchored off the city waiting to dock.",
      ]));

    set_exits(([
  "west":ROAD+"path22",
  "southeast":ROAD+"path24",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salt sea air mixes with the smells of many types of cooking.");
}
