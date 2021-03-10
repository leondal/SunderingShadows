#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "southwest" : ROOMS + "lake20",
                 "southeast" : ROOMS + "lake22",
                     "north" : ROOMS + "trail08",
                 "northeast" : ROOMS + "trail07",
                      "west" : ROOMS + "trail09" ]) );
  set_long(query_long() + " To the west, some steps lead up to a wooden structure built outward from the bank of the lakeside, resting on stilts as it extents over the water.");
}
