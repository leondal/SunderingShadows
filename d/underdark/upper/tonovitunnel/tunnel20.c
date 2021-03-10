#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "southeast" : TUNNEL"tunnel19",
      "northwest" : TUNNEL"tunnel21",
    ]));
}
