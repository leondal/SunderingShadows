#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path29",
    "west" : ROOMS+"path27"
    ]) );
}