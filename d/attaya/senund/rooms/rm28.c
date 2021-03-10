#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "southeast" : ROOMS+"rm13",
        "north" : ROOMS+"rm29"
   
    ]) );

}

 