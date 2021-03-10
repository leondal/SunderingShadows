#include <std.h>
#include "element.h"

inherit INH"temp";

void create()
{
    ::create();
  
    set_exits(([
        "up" : ROOMS"1",
        "east" :ROOMS"3",
		"west" :ROOMS"4",
		"north" :ROOMS"5",
    ]));
}
