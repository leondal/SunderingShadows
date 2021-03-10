#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f26",
    "west" : ROOMS+"f24",
    "north" : ROOMS+"f16",
    "south" : ROOMS+"f33"
    ]) );
}