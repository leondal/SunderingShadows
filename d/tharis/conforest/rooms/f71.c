#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "west" : ROOMS+"f70",
    "north" : ROOMS+"path19",
    "south" : ROOMS+"f76"
    ]) );
}