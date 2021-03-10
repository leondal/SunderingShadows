#include <std.h>
#include "../defs.h"
inherit INH+"tunnel1";

void create() {
    ::create();

    set_exits(([
      "south" : TUNNEL"tunnel09",
      "northwest" : TUNNEL"tunnel11",
    ]));
}
