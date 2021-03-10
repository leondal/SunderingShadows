#include <std.h>
#include "../defs.h"
inherit ISLAND;

void create()
{
  ::create();
  set_exits( 
    ([
    "north" : ROOMS+"island5",
    "northwest" : ROOMS+"island1",
    "northeast" : ROOMS+"island3"
    ]) );
}
