#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f48",
    "west" : ROOMS+"f46",
    "north" : ROOMS+"path11",
    "south" : ROOMS+"f55"
    ]) );
}