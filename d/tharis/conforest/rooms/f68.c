#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f69",
    "west" : ROOMS+"f67",
    "north" : ROOMS+"path16",
    "south" : ROOMS+"f73"
    ]) );
}