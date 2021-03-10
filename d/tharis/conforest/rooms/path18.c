#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path19",
    "west" : ROOMS+"path17",
    "north" : ROOMS+"f61",
    "south" : ROOMS+"f70"
    ]) );
}