#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "southeast" : TUNNEL"newtunnel5",
      "northeast" : TUNNEL"newtunnel7"
    ]));
}
