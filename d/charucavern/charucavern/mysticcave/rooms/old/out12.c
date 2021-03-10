#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_exits((["north" : CRROOMS+"out11", "east" : CRROOMS+"out17", "southeast" : CRROOMS+"out18", "south" : CRROOMS+"out13", 
    "southwest" : CRROOMS+"out15", "west" : CRROOMS+"out16"]));		

}
