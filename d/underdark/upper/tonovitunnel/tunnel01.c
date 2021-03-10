#include <std.h>
#include "../defs.h"
inherit INH+"tunnel1";

void create() {
    ::create();

    set_exits(([
      "southwest" : TUNNEL"tormdock03",
      "northeast" : TUNNEL"tunnel02",
    ]));
}
