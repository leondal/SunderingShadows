#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
//    set_property("no teleport", 1);
//Don't know why in the world this was set...
//removing it ~Circe~ 4/27/08
    set_short("Path to Torm");
    set_long(
  "%^CYAN%^"
  "You are approaching the great Dagger seaport of Torm."
  "  To the southeast you can see the great town on the solid land, with its boardwalk along the ocean leading to the docks."
  "  Many boats are in several stages of movement, from docking to waiting to leaving for the great open waters."
  "  A dark forest lies to the south along the path to the city and it makes you wonder if you want to pass it."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
      ]));

    set_exits(([
	"north" : "/d/dagger/road/road16",
   "south" : "/d/dagger/Torm/road/path2",
      ]));

}
