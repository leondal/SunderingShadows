#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f61",
    "west" : ROOMS+"f59",
    "north" : ROOMS+"f52",
    "south" : ROOMS+"path17"
    ]) );
}