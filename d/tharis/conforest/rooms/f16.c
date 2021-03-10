#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f17",
    "west" : ROOMS+"f15",
    "south" : ROOMS+"f25"
    ]) );
}