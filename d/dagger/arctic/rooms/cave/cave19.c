#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : CAVE"cave8",
      "west"        : CAVE"cave20",
      "northwest"   : CAVE"cave24",
           ]));
}