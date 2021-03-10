#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "northeast" : ROOMS+"rm18",
        "south" : ROOMS+"rm22",
        "northwest" : ROOMS+"rm20"
   
    ]) );

}

 