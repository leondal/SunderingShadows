#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f46",
    "west" : ROOMS+"f44",
    "north" : ROOMS+"path9"
    ]) );
}