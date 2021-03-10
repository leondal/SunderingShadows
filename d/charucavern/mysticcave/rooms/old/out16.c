#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_exits((["south" : CRROOMS+"out15", "northeast" : CRROOMS+"out11", "east" : CRROOMS+"out12", "southeast" : CRROOMS+"out13"]));		

}
