#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : CAVE"cave12",
      //"south"       : ROOMS"/sp10",
      "northwest"   : CAVE"cave10",
           ]));
}