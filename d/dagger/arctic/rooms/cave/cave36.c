#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "south"       : CAVE"cave35",
      "northeast"   : CAVE"cave49",
           ]));
}