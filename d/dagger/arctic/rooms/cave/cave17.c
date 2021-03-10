#include <std.h>
#include "../../arctic.h"
inherit ROOMS"cave.c";

void create()
{
    ::create();

  set_exits(([
      "northeast"   : CAVE"cave26",
      "southeast"   : CAVE"cave10",
           ]));
}