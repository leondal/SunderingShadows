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
  "  North and south of the road are forests that seem to be thinning as the ground grows rocky."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
      ]));

    set_exits(([
  "west":"/d/dagger/Torm/road/path7",
  "southeast":"/d/dagger/Torm/road/path9",
      ]));

  set_smell("default","A slight breeze brings you the scent of sea air.");
   set_listen("default","The forests are quiet.");
}
