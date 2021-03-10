#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "southwest" : TUNNEL"newtunnel6",
      "east" : TUNNEL"newtunnel8"
    ]));
}
