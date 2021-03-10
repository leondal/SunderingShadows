#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f33",
    "west" : ROOMS+"f31",
    "north" : ROOMS+"f24",
    "south" : ROOMS+"f40"
    ]) );
}