#include <std.h>
#include "../defs.h"
inherit INC+"pathswne";

void create()
{
  ::create();
  set_exits(
    ([
    "northeast" : ROOMS+"path38",
    "southwest" : ROOMS+"path36",
    "north" : ROOMS+"f22",
    "south" : ROOMS+"f37",
    "east" : ROOMS+"f30",
    "west" : ROOMS+"f29"
    ]) );
}