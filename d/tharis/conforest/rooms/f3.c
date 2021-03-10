#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f4",
    "west" : ROOMS+"f2",
    "south" : ROOMS+"f8"
    ]) );
}