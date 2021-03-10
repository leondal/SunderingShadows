#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f25",
    "west" : ROOMS+"f23",
    "north" : ROOMS+"f15",
    "south" : ROOMS+"f32"
    ]) );
}