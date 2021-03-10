#include <std.h>
#include "../defs.h"
inherit INC+"pathsenw";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f50",
    "west" : ROOMS+"f49",
    "north" : ROOMS+"f42",
    "south" : ROOMS+"f58",
    "southeast" : ROOMS+"path15",
    "northwest" : ROOMS+"path13"
    ]) );
}