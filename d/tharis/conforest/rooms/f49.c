#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path14",
    "west" : ROOMS+"f48",
    "north" : ROOMS+"path13",
    "south" : ROOMS+"f57"
    ]) );
}