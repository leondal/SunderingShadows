#include <std.h>
#include "../defs.h"
inherit ISLAND;

void create()
{
  ::create();
  set_exits( 
    ([
    "south" : ROOMS+"island5",
    "southwest" : ROOMS+"island1",
    "southeast" : ROOMS+"island3"
    ]) );
}
