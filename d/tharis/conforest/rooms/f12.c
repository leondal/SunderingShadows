#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f13",
    "west" : ROOMS+"f11",
    "north" : ROOMS+"f7",
    "south" : ROOMS+"f21"
    ]) );
}