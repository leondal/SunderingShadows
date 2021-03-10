#include <std.h>
#include "../defs.h"
inherit ISLAND;

void create()
{
  ::create();
  set_exits( 
    ([
    "west" : ROOMS+"island5",
    "southwest" : ROOMS+"island4",
    "northwest" : ROOMS+"island2"
    ]) );
}
