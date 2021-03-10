#include <std.h>
#include "../defs.h"
inherit INC+"pathswne";

void create()
{
  ::create();
  set_exits(
    ([
    "northeast" : ROOMS+"path37",
    "southwest" : ROOMS+"path10",
    "north" : ROOMS+"f29",
    "east" : ROOMS+"f37",
    "west" : ROOMS+"f36"
    ]) );
}