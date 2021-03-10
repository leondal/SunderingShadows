#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inh2.c";

void create() {
 ::create();
 set_exits(([
  "southeast":ROOMS"grove1",
  "north":ROOMS"grove5",
  "northeast":ROOMS"grove6",
  "east":ROOMS"grove3",
 ]));
}
