#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
    "northwest":"/d/dagger/marsh/witchlair/rooms/clearing1",
    "north":"/d/dagger/marsh/witchlair/rooms/clearing5",
    "northeast":"/d/dagger/marsh/witchlair/rooms/clearing6",
    "east":"/d/dagger/marsh/witchlair/rooms/clearing8",
  ]));
}
