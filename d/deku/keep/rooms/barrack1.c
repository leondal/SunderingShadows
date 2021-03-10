#include <std.h>
#include "../keep.h"
inherit BB;
void create() {
    ::create();
    set_exits(([
       "south" : KEEPR + "keepE1",
       "up" : KEEPR + "barrack_u1"
    ] ));
}
