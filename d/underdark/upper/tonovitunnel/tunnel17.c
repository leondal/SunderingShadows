#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "southwest" : TUNNEL"cavern05",
      "northeast" : TUNNEL"tunnel18",
    ]));
}
