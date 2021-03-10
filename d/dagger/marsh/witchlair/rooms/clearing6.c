#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
    "southwest":"/d/dagger/marsh/witchlair/rooms/clearing7",
    "west":"/d/dagger/marsh/witchlair/rooms/clearing5",
    "northwest":"/d/dagger/marsh/witchlair/rooms/clearing2",
    "north":"/d/dagger/marsh/witchlair/rooms/clearing3",
    "northeast":"/d/dagger/marsh/witchlair/rooms/clearing4",
    "east":"/d/dagger/marsh/witchlair/rooms/hutentry",
    "southeast":"/d/dagger/marsh/witchlair/rooms/clearing9",
    "south":"/d/dagger/marsh/witchlair/rooms/clearing8",
  ]));
}
