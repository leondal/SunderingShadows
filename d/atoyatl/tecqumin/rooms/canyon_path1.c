#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CANYON_PATH;

void create() {
  ::create();
  side = "east";
  set_exits((["down"   : JUNG_ROOM + "canyon_riverbank_west",
              "north"   : JUNG_ROOM + "canyon_path2"
    ]));
}
