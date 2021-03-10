#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "northwest"   : CAVE"cave27",
      //"southwest"   : CAVE"sp9",
           ]));
}