#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path13",
    "west" : ROOMS+"path11",
    "north" : ROOMS+"f37",
    "south" : ROOMS+"f48"
    ]) );
}