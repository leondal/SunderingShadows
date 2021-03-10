#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f75",
    "west" : ROOMS+"f73",
    "north" : ROOMS+"f69",
    "south" : ROOMS+"f77"
    ]) );
}
