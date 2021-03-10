#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
    "west":"/d/dagger/marsh/witchlair/rooms/clearing1",
    "north":"/d/dagger/marsh/witchlair/rooms/clearing2",
    "northeast":"/d/dagger/marsh/witchlair/rooms/clearing3",
    "east":"/d/dagger/marsh/witchlair/rooms/clearing6",
    "southeast":"/d/dagger/marsh/witchlair/rooms/clearing8",
    "south":"/d/dagger/marsh/witchlair/rooms/clearing7",
  ]));
}
