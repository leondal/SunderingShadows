#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f14",
    "west" : ROOMS+"f12",
    "north" : ROOMS+"f8",
    "south" : ROOMS+"f22"
    ]) );
}