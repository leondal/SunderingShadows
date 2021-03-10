#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f43",
    "west" : ROOMS+"path13",
    "north" : ROOMS+"f39",
    "south" : ROOMS+"path14"
    ]) );
}