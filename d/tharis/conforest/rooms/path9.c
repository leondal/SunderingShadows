#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path10",
    "west" : ROOMS+"path8",
    "north" : ROOMS+"f35",
    "south" : ROOMS+"f45"
    ]) );
}