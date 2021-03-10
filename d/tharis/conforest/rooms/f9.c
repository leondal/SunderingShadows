#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f10",
    "west" : ROOMS+"f8",
    "north" : ROOMS+"f4",
    "south" : ROOMS+"f14"
    ]) );
}