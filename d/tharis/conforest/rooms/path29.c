#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path30",
    "west" : ROOMS+"path28",
    "north": "/d/player_houses/rheyn/sapling" //spot where rheyn wants sapling grove
    ]) );
}
