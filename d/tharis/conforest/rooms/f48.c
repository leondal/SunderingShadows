#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f49",
    "west" : ROOMS+"f47",
    "north" : ROOMS+"path12",
    "south" : ROOMS+"f56"
    ]) );
}