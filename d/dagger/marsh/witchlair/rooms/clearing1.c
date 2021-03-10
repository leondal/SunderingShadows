#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
   "northeast":"/d/dagger/marsh/witchlair/rooms/clearing2.c",
   "east":"/d/dagger/marsh/witchlair/rooms/clearing5.c",
   "southeast":"/d/dagger/marsh/witchlair/rooms/clearing7.c",
  ]));
}
