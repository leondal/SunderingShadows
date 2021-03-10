#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f74",
    "west" : ROOMS+"f72",
    "north" : ROOMS+"f68"
    ]) );
}