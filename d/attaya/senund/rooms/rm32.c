#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "northwest" : ROOMS+"rm33",
        "southwest" : ROOMS+"rm31"
   
    ]) );

}

 