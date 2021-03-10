#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "northwest" : TUNNEL"newtunnel10",
      "southeast" : TUNNEL"newtunnel8"
    ]));
}
