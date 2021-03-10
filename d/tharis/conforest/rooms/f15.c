#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f16",
    "west" : ROOMS+"path39",
    "north" : ROOMS+"path40",
    "south" : ROOMS+"f24"
    ]) );
}