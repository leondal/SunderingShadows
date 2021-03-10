#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path41",
    "west" : ROOMS+"f4",
    "south" : ROOMS+"f10"
    ]) );
}