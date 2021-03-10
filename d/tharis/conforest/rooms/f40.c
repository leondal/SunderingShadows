#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f41",
    "west" : ROOMS+"f39",
    "north" : ROOMS+"f32",
    "south" : ROOMS+"f43"
    ]) );
}