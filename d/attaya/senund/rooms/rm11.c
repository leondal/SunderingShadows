#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "southwest" : ROOMS+"rm10",
        "northeast" : ROOMS+"rm12"
   
    ]) );

}

 