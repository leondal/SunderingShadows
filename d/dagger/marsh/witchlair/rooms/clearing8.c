#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
    "west":"/d/dagger/marsh/witchlair/rooms/clearing7",
    "northwest":"/d/dagger/marsh/witchlair/rooms/clearing5",
    "north":"/d/dagger/marsh/witchlair/rooms/clearing6",
    "northeast":"/d/dagger/marsh/witchlair/rooms/hutentry",
    "east":"/d/dagger/marsh/witchlair/rooms/clearing9",
  ]));
}
