#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f32",
    "west" : ROOMS+"f30",
    "north" : ROOMS+"f23",
    "south" : ROOMS+"f39"
    ]) );
}