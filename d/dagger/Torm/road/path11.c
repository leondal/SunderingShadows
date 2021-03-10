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
  "You draw close to the main west gates of Torm."
  "  Many boats are in several stages of movement, from docking to waiting to leaving for the great open waters."
  "  The spires gleam above the low stone wall that surrounds the city."
   "  Looking north and south you can see the tree line end along a low cliff that borders the golden beaches that stretch off as far as you can see."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
	"boats" : "They are those things that hold people and float on water.",
      ]));

    set_exits(([
 "northwest":"/d/dagger/Torm/road/path10",
  "southeast":"/d/dagger/Torm/road/path12",
      ]));

  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salt sea air mixes with the smells of many types of cooking.");
}
