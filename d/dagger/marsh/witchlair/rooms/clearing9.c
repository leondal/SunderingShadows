#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
    "west":"/d/dagger/marsh/witchlair/rooms/clearing8",
    "northwest":"/d/dagger/marsh/witchlair/rooms/clearing6",
    "north":"/d/dagger/marsh/witchlair/rooms/hutentry",
  ]));
}
