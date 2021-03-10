#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit BEACHBASE;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "beach07",
                "southwest" : ROOMS + "beach05"]) );
}
