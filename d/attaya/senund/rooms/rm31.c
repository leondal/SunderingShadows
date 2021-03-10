#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "northeast" : ROOMS+"rm32",
        "southwest" : ROOMS+"rm30"
   
    ]) );

}

 