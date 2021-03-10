#include <std.h>
#include "../../arctic.h"
inherit ROOMS"caveb.c";

void create()
{
    ::create();

  set_exits(([
      "north"       : CAVE"cave16",
      "west"        : CAVE"cave9",
      "southeast"   : CAVE"cave11",
      "northwest"   : CAVE"cave17",
           ]));
}