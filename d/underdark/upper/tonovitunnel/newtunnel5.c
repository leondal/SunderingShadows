#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "southeast" : TUNNEL"newtunnel4",
      "northwest" : TUNNEL"newtunnel6"
    ]));
}
