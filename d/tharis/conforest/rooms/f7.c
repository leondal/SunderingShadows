#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f8",
    "west" : ROOMS+"f6",
    "north" : ROOMS+"f2",
    "south" : ROOMS+"f12"
    ]) );
}