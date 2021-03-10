#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f71",
    "west" : ROOMS+"f69",
    "north" : ROOMS+"path18",
    "south" : ROOMS+"f75"
    ]) );
}