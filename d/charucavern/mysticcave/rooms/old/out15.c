#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_exits((["north" : CRROOMS+"out16", "northeast" : CRROOMS+"out12", "east" : CRROOMS+"out13", "southeast" : CRROOMS+"out14"]));		

}
