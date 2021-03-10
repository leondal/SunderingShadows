#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f22",
    "west" : ROOMS+"f20",
    "north" : ROOMS+"f12",
    "south" : ROOMS+"f29"
    ]) );
}