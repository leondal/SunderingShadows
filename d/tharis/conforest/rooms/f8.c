#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f9",
    "west" : ROOMS+"f7",
    "north" : ROOMS+"f3",
    "south" : ROOMS+"f13"
    ]) );
}