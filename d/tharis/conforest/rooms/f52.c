#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f53",
    "west" : ROOMS+"f51",
    "north" : ROOMS+"c2",
    "south" : ROOMS+"f60"
    ]) );
}