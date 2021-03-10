#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_exits((["south" : CRROOMS+"out18", "southwest" : CRROOMS+"out13", "west" : CRROOMS+"out12", "northwest" : CRROOMS+"out11"]));		

}
