#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "south" : TUNNEL"tunnel24",
      "north" : TUNNEL"tunnel26",
    ]));
}
