#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit BEACHBASE;

void create() {
  ::create();
  set_exits( ([ "northwest" : ROOMS + "beach09",
                "southeast" : ROOMS + "beach07"]) );
}
