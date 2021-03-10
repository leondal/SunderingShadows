#include <std.h>
#include "../keep.h"
inherit UB;
void create() {
    ::create();
      set_exits(([ "down" : KEEPR + "barrack2" ] ));
 }
