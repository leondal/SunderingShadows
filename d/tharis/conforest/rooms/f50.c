#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f51",
    "west" : ROOMS+"path14",
    "north" : ROOMS+"f43",
    "south" : ROOMS+"path15"
    ]) );
}