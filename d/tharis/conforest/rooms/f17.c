#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f18",
    "west" : ROOMS+"f16",
    "south" : ROOMS+"f26"
    ]) );
}