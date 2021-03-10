#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path37",
    "west" : ROOMS+"f28",
    "north" : ROOMS+"f21",
    "south" : ROOMS+"path36"
    ]) );
}