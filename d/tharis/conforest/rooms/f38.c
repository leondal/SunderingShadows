#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f39",
    "west" : ROOMS+"f37",
    "north" : ROOMS+"f30",
    "south" : ROOMS+"path13"
    ]) );
}