#include <std.h>
#include "../keep.h"
inherit TOWERI1;
void create() {
    ::create();
    set_exits(([
       "up" : KEEPR + "towerNE2",
       "southwest" : KEEPR + "keepE6"
    ] ));
}
