#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Path to Torm");
    set_long(
  "%^CYAN%^"
  "You are approaching the great Dagger seaport of Torm."
  "  To the southeast you can see the great town on the solid land, with its boardwalk along the ocean leading to the docks."
  "  Many boats are in several stages of movement, from docking to waiting to leaving for the great open waters."
    "  The dark forest lies to the south along the path and as you draw nearer you hope the road doesn't pass to close."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
      ]));

    set_exits(([
  "north":"/d/dagger/Torm/road/path1",
  "southeast":"/d/dagger/Torm/road/path3",
      ]));

   set_listen("default","The forests are quiet.");
  set_smell("default","You can smell the thick scent of the evergreens.");
}
