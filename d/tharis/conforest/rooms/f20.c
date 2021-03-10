#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f21",
    "north" : ROOMS+"f11",
    "south" : ROOMS+"f28"
    ]) );
}