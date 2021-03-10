#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "north" : TUNNEL"newtunnel12",
      "southeast" : TUNNEL"newtunnel10"
    ]));
}
