#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path18",
    "west" : ROOMS+"path16",
    "north" : ROOMS+"f60",
    "south" : ROOMS+"f69"
    ]) );
}