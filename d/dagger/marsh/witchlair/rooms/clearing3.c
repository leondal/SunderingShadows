#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
    "southwest":"/d/dagger/marsh/witchlair/rooms/clearing5",
    "west":"/d/dagger/marsh/witchlair/rooms/clearing2",
    "east":"/d/dagger/marsh/witchlair/rooms/clearing4",
    "southeast":"/d/dagger/marsh/witchlair/rooms/hutentry",
    "south":"/d/dagger/marsh/witchlair/rooms/clearing6",
  ]));
}
