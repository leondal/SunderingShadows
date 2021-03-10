#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f40",
    "west" : ROOMS+"f38",
    "north" : ROOMS+"f31",
    "south" : ROOMS+"f42"
    ]) );
}