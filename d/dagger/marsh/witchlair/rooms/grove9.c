#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inh2.c";

void create() {
 ::create();
 set_exits(([
  "west":ROOMS"grove8",
  "southwest":ROOMS"grove5",
  "south":ROOMS"grove6",
  "southeast":ROOMS"grove7",
  "east":ROOMS"grove10",
 ]));
}
