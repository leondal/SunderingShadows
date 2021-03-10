#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "northwest" : TUNNEL"newtunnel11",
      "southeast" : TUNNEL"newtunnel9"
    ]));
}
