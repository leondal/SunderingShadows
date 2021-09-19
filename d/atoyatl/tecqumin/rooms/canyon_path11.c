#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CANYON_PATH;

void create() {
  ::create();
  side = "east";
  set_exits((["south"   : JUNG_ROOM + "canyon_path12",
              "north"   : JUNG_ROOM + "canyon_path10"
    ]));
}
