#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "west" : TUNNEL"newtunnel7",
      "northwest" : TUNNEL"newtunnel9"
    ]));
}
