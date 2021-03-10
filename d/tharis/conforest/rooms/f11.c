#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f12",
    "north" : ROOMS+"f6",
    "south" : ROOMS+"f20"
    ]) );
}