#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f76",
    "west" : ROOMS+"f74",
    "north" : ROOMS+"f70",
    "south" : ROOMS+"f78"
    ]) );
}
