#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f58",
    "west" : ROOMS+"f56",
    "north" : ROOMS+"f49",
    "south" : ROOMS+"f63"
    ]) );
}