#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "west"        : CAVE"cave44",
      "southeast"   : CAVE"cave42",
           ]));
}