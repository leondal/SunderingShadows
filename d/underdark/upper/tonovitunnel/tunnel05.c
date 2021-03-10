#include <std.h>
#include "../defs.h"
inherit INH+"tunnel1";

void create() {
    ::create();

    set_exits(([
      "southeast" : TUNNEL"tunnel04",
      "northwest" : TUNNEL"tunnel06",
    ]));
}
