#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path38",
    "west" : ROOMS+"f21",
    "north" : ROOMS+"f13",
    "south" : ROOMS+"path37"
    ]) );
}