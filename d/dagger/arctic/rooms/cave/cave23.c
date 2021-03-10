#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "north"   : CAVE"cave34",
      "east"    : CAVE"cave24",
           ]));
}