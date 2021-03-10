#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f60",
    "west" : ROOMS+"path15",
    "north" : ROOMS+"f51",
    "south" : ROOMS+"path16"
    ]) );
}