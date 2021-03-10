#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f31",
    "west" : ROOMS+"path37",
    "north" : ROOMS+"path38",
    "south" : ROOMS+"f38"
    ]) );
}