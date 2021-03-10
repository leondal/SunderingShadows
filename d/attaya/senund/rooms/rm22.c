#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "north" : ROOMS+"rm19",
        "southwest" : ROOMS+"rm23"
   
    ]) );

}

 
