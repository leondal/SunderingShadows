#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path40",
    "west" : ROOMS+"f9",
    "north" : ROOMS+"f5",
    "south" : ROOMS+"path39"
    ]) );
}