#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "southwest" : ROOMS+"rm12",
        "northwest" : ROOMS+"rm28",
        "southeast" : ROOMS+"rm14"
   
    ]) );

}

 