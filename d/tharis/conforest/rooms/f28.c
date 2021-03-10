#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f29",
    "north" : ROOMS+"f20",
    "south" : ROOMS+"f36"
    ]) );
}