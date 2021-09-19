#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CANYON_RIVERBANK;

void create() {
  ::create();
  side = "east";
  set_exits((["up"   : JUNG_ROOM + "canyon_path7"  ,
              "south": ROOMS + "canoe_entry" ]));
}
