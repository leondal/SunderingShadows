#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "northeast" : ROOMS+"rm17",
        "southwest" : ROOMS+"rm19"
   
    ]) );

}

 