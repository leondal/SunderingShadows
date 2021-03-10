#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"c1",
    "west" : ROOMS+"f42",
    "north" : ROOMS+"f40",
    "south" : ROOMS+"f50"
    ]) );
}