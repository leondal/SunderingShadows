#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "northeast" : ROOMS+"rm31",
        "south" : ROOMS+"rm29"
   
    ]) );

}

 