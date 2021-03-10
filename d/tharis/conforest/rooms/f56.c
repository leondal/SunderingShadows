#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f57",
    "west" : ROOMS+"f55",
    "north" : ROOMS+"f48"
    ]) );
}