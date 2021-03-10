#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : CAVE"cave10",
      "northeast"   : CAVE"cave27",
           ]));
}