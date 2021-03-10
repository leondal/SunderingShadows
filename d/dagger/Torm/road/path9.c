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
  "  You are leaving the forests to the west as the ground grows rocky."
  "  You can start to see the great golden beaches that stretch south and north of the rocky outcroping Torm lies on."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
      ]));

    set_exits(([
  "northwest":"/d/dagger/Torm/road/path8",
  "southeast":"/d/dagger/Torm/road/path10",
      ]));

   set_listen("default","The forests are quiet.");
  set_smell("default","A slight breeze brings you the scent of sea air.");
}
