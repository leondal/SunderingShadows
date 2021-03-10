#include <std.h>
#include "../defs.h"
inherit INC+"pathsn";

void create()
{
  ::create();
  set_exits(
    ([
    "south" : ROOMS+"path40",
    "west" : ROOMS+"f5"
    ]) );
}
