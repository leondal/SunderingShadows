#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f65",
    "west" : ROOMS+"f63",
    "north" : ROOMS+"f58",
    "south" : ROOMS+"f66"
    ]) );
}