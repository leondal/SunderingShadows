#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Path to Torm");
    set_long(
  "%^CYAN%^"
  "You break free of the last of the forests and you can see Torm clearly now."
  "  Many boats are in several stages of movement, from docking to waiting to leaving for the great open waters."
  "  The spires that rise above the richer buildings gleam and you can make out the faint reliefs carved onto the low green wall surrounding the city."
  "  Looking north and south you can see the tree line end in the low cliffs then end in the golden beaches that stretch off as far as you can see."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
      ]));

    set_exits(([
  "northwest":"/d/dagger/Torm/road/path9",
  "southeast":"/d/dagger/Torm/road/path11",
      ]));

    set_listen("default","You can hear the faint cry of seabirds.");
  set_smell("default","A slight breeze brings you the scent of sea air.");
}
