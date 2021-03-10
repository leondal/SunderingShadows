#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f47",
    "west" : ROOMS+"f45",
    "north" : ROOMS+"path10"
    ]) );
}