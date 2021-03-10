#include <std.h>
#include "../areadefs.h"
inherit MAINROOM;

void create()
{
    ::create();
    set_exits(
    ([
        "west" : ROOMS+"rm9",
        "northeast" : ROOMS+"rm11",
        "southeast" : ROOMS+"rm21"
  
   
    ]) );

}

 