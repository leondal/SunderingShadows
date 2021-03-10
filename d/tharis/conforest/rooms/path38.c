#include <std.h>
#include "../defs.h"
inherit INC+"pathswne";

void create()
{
  ::create();
  set_exits(
    ([
    "northeast" : ROOMS+"path39",
    "southwest" : ROOMS+"path37",
    "north" : ROOMS+"f14",
    "south" : ROOMS+"f30",
    "east" : ROOMS+"f23",
    "west" : ROOMS+"f22"
    ]) );
}