#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path16",
    "west" : ROOMS+"f64",
    "north" : ROOMS+"path15",
    "south" : ROOMS+"f67"
    ]) );
}