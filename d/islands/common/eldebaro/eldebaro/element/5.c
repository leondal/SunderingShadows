#include <std.h>
#include "element.h"

inherit INH"temp";

void create()
{
    ::create();
  
    set_exits(([
       
        "south" :ROOMS"2",
	
    ]));
}
