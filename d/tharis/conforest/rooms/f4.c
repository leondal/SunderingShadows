#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f5",
    "west" : ROOMS+"f3",
    "south" : ROOMS+"f9"
    ]) );
}