#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path39",
    "west" : ROOMS+"f13",
    "north" : ROOMS+"f9",
    "south" : ROOMS+"path38"
    ]) );
}