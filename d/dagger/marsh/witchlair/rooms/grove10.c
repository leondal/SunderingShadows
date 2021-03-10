#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inh2.c";

void create() {
 ::create();
 set_exits(([
  "west":ROOMS"grove9",
  "southwest":ROOMS"grove6",
  "south":ROOMS"grove7",
 ]));
}
