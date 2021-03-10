#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"

inherit "/d/dagger/Torm/inherits/hut";

void create() {
    ::create();
    set_exits(([
  "out":ROAD+"path24",
      ]));
}
