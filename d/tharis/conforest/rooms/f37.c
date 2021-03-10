#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f38",
    "west" : ROOMS+"path36",
    "north" : ROOMS+"path37",
    "south" : ROOMS+"path12"
    ]) );
}