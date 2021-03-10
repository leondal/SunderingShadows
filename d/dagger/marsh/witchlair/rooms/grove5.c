#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inh2.c";

void create() {
 ::create();
 set_exits(([
  "south":ROOMS"grove2",
  "north":ROOMS"grove8",
  "east":ROOMS"grove6",
  "southeast":ROOMS"grove3",
  "south":ROOMS"grove2",
  "northeast":ROOMS"grove9",
 ]));
}
