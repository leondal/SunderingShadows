#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f27",
    "west" : ROOMS+"f25",
    "north" : ROOMS+"f17",
    "south" : ROOMS+"c6"
    ]) );
}