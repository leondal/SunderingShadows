#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f36",
    "west" : ROOMS+"f34",
    "south" : ROOMS+"path9"
    ]) );
}