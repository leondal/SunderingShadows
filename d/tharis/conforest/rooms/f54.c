#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "west" : ROOMS+"f53",
      "south" : ROOMS+"f62"
    ]) );
}
