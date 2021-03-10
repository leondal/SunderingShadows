#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "east"        : CAVE"cave55",
      "west"        : CAVE"cave53",
           ]));
}