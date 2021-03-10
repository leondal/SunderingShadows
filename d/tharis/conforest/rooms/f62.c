#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "west" : ROOMS+"f61",
    "north" : ROOMS+"f54",
    "south" : ROOMS+"path19"
    ]) );
}