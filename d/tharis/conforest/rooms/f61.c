#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f62",
    "west" : ROOMS+"f60",
    "north" : ROOMS+"f53",
    "south" : ROOMS+"path18"
    ]) );
}