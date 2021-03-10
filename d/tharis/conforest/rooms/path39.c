#include <std.h>
#include "../defs.h"
inherit INC+"pathswne";

void create()
{
  ::create();
  set_exits(
    ([
    "northeast" : ROOMS+"path40",
    "southwest" : ROOMS+"path38",
    "north" : ROOMS+"f10",
    "south" : ROOMS+"f23",
    "east" : ROOMS+"f15",
    "west" : ROOMS+"f14"
    ]) );
}