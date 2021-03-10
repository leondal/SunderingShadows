#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "southwest" : TUNNEL"tunnel17",
      "northwest" : TUNNEL"tunnel19",
    ]));
}
