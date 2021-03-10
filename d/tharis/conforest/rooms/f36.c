#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path36",
    "west" : ROOMS+"f35",
    "north" : ROOMS+"f28",
    "south" : ROOMS+"path10"
    ]) );
}