#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path15",
    "west" : ROOMS+"f57",
    "north" : ROOMS+"path14",
    "south" : ROOMS+"f64"
    ]) );
}