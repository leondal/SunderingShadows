#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "west"        : CAVE"cave38",
      "northeast"   : CAVE"cave48",
      //"southeast"   : ROOMS"/sp12",
           ]));
}