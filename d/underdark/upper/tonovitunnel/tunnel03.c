#include <std.h>
#include "../defs.h"
inherit INH+"tunnel1";

void create() {
    ::create();

    set_exits(([
      "south" : TUNNEL"tunnel02",
      "north" : TUNNEL"tunnel04",
    ]));
}
