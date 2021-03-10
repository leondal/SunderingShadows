#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "northwest" : ROOMS+"rm14",
        "southeast" : ROOMS+"rm16"
   
    ]) );

}

 