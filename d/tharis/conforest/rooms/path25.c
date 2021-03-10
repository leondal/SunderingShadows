#include <std.h>
#include "../defs.h"
inherit INC+"pathsenw";

void create()
{
  ::create();
  set_exits(
    ([
    "southeast" : ROOMS+"path26",
    "northwest" : ROOMS+"path24"
    ]) );
}