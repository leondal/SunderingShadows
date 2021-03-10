#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"c4",
    "west" : ROOMS+"f40",
    "north" : ROOMS+"f33",
    "south" : ROOMS+"c1"
    ]) );
}