#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Wine cellar"
  );
  set_property("indoors",1);
  set_long(
  "Wine cellar\n"
  "  This cool room lies under the winery."
  "  Great casks line the walls and the floor is dark flat stone."
  "  A lift and staircase lead up to the main room of the winery."
  "\n"
  );
  set_smell("default",
  "You smell sweet wine in the air."
  );
  set_listen("default",
  "Its dead silent down here."
  );
  set_items(([
  ]));
  set_exits(([
  "up":ROOMS"v44.c",
  ]));
}
