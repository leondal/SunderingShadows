#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f68",
    "west" : ROOMS+"f66",
    "north" : ROOMS+"f65",
    "south" : ROOMS+"f72"
    ]) );
}