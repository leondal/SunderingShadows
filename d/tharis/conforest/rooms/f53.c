#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f54",
    "west" : ROOMS+"f52",
    "north" : ROOMS+"c3",
    "south" : ROOMS+"f61"
    ]) );
}