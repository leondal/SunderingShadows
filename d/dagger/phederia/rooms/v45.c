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
  "  This large room leads north to a smaller room and continues west."
  "  Great wine presses and casks line the walls here."
  "  It looks as if the place has been abandoned halfway through a run leaving pulp and juices to rot."
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
 "north":ROOMS"v43.c",
  "west":ROOMS"v44.c",
  "southeast":ROOMS"v12.c",
  ]));
}
