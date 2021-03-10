#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f52",
    "west" : ROOMS+"f50",
    "north" : ROOMS+"c1",
    "south" : ROOMS+"f59"
    ]) );
}