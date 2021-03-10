#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path12",
    "west" : ROOMS+"path10",
    "south" : ROOMS+"f47"
    ]) );
}