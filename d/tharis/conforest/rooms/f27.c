#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "west" : ROOMS+"f26",
    "north" : ROOMS+"f18",
    "south" : ROOMS+"c7"
    ]) );
}