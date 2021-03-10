#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : CAVE"cave10",
      "northwest"   : CAVE"cave18",
      "southwest"   : CAVE"cave4",
           ]));
}