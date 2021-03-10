#include <std.h>
#include "../keep.h"
inherit BB;
void create() {
    ::create();
     set_exits(([
       "up" : KEEPR + "barrack_u2",
       "west" : KEEPR + "keepW4"
    ] ));
}
