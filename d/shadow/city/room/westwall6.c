//Octothorpe (1/22/12)
//Shadow, West Wall 6

#include <std.h>
#include "../defs.h"
inherit INH+"westwall";

void create(){
    ::create();
    set_exits(([
        "northwest" : ROOMS"westwall5",
        "southeast" : ROOMS"southcross",
    ]));
}

