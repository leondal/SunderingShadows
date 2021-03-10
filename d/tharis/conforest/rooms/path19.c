#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path20",
    "west" : ROOMS+"path18",
    "north" : ROOMS+"f62",
    "south" : ROOMS+"f71"
    ]) );
}