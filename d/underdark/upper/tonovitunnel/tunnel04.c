#include <std.h>
#include "../defs.h"
inherit INH+"tunnel1";

void create() {
    ::create();

    set_exits(([
      "south" : TUNNEL"tunnel03",
      "northwest" : TUNNEL"tunnel05",
    ]));
}
