#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CANYON_PATH;

void create() {
  ::create();
  side = "east";
  set_exits((["down"   : JUNG_ROOM + "canyon_path9",
              "south"   : JUNG_ROOM + "canyon_path11"
    ]));
}
