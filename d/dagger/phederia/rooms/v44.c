#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Main room of the winery"
  );
  set_property("indoors",1);
  set_long(
  "Main room of the winery\n"
  "  This large room leads back to the east."
  "  Great wine presses and casks line the walls here."
  "  It looks as if the place has been abandoned halfway through a run leaving pulp and juices to rot."
  "  A stairway and lift lead to a cellar."
  "\n"
  );
  set_smell("default",
  "You smell sweet wine in the air."
  );
  set_listen("default",
  "Flies buzz around the casks."
  );
  set_items(([
  ]));
  set_exits(([
  "east":ROOMS"v45.c",
  "down":ROOMS"v44b.c",
  ]));
}
