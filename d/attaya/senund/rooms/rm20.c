#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "southeast" : ROOMS+"rm19",
        "northwest" : ROOMS+"rm21"
   
    ]) );

}

 