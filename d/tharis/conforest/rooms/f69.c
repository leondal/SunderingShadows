#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f70",
    "west" : ROOMS+"f68",
    "north" : ROOMS+"path17",
    "south" : ROOMS+"f74"
    ]) );
}