#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"c6",
    "west" : ROOMS+"f32",
    "north" : ROOMS+"f25",
    "south" : ROOMS+"f41"
    ]) );
}