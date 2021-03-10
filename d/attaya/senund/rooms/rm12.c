#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "southwest" : ROOMS+"rm11",
        "northeast" : ROOMS+"rm13"
   
    ]) );

}

 