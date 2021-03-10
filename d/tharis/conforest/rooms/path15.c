#include <std.h>
#include "../defs.h"
inherit INC+"pathsenw";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f59",
    "west" : ROOMS+"f58",
    "north" : ROOMS+"f50",
    "south" : ROOMS+"f65",
    "southeast" : ROOMS+"path16",
    "northwest" : ROOMS+"path14"
    ]) );
}