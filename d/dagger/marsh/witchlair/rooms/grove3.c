#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inherit.c";

void create() {
 ::create();
 set_exits(([
  "west":ROOMS"grove2",
  "northwest":ROOMS"grove5",
  "north":ROOMS"grove6",
  "northeast":ROOMS"grove7",
  "east":ROOMS"grove4",
  "south":ROOMS"grove1",
 ]));
}
