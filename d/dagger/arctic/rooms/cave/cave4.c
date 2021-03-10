#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : CAVE"cave3",
      "northeast"   : CAVE"cave9",
      "northwest"   : CAVE"cave8",
           ]));
}