#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path9",
    "west" : ROOMS+"path7",
    "north" : ROOMS+"f34",
    "south" : ROOMS+"f44"
    ]) );
}