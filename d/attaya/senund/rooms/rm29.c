#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "south" : ROOMS+"rm28",
        "north" : ROOMS+"rm30"
   
    ]) );

}

 