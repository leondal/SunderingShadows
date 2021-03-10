#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "west" : ROOMS+"rm25",
        "east" : ROOMS+"rm27"
   
    ]) );

}

 