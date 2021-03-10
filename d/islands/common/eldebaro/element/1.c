#include <std.h>
#include "element.h"

inherit INH"temp";

void create()
{
    ::create();
  
    set_exits(([
        "down" : ROOMS"2",
        "out" : "/d/islands/common/eldebaro/rooms/room30",
    ]));
}
