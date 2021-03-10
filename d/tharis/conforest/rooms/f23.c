#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f24",
    "west" : ROOMS+"path38",
    "north" : ROOMS+"path39",
    "south" : ROOMS+"f31"
    ]) );
}